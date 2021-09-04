
/*
https://gist.github.com/alexeiz/3371541
Atomic init once
*/
static __analysis_noreturn __forceinline void RaiseStatus(NTSTATUS Status)
{
    RaiseException(Status, EXCEPTION_NONCONTINUABLE, 0, NULL);
}

/**
 * @brief InitGlobalKeyedEventHandle
 * http://joeduffyblog.com/2006/11/28/windows-keyed-events-critical-sections-and-new-vista-synchronization-features/
 * This is when keyed events were born. They were added to Windows XP as a new kernel object type,
 * and there is always one global event \KernelObjects\CritSecOutOfMemoryEvent, shared among all
 * processes. There is no need for any of your code to initialize or create it—it’s always there and
 * always available, regardless of the amount of resources on the machine. Having it there always
 * adds a single HANDLE per process, which is a very small price to pay for the benefit that comes
 * along with it. If you dump the handles with !handle in WinDbg, you’ll always see one of type
 * KeyedEvent. Well, what does it do?
 * @return HANDLE
 */
static HANDLE InitGlobalKeyedEventHandle()
{
    static HANDLE _GlobalKeyedEventHandle = NULL;
    if (_GlobalKeyedEventHandle == NULL)
    {
        const wchar_t Name[] = L"\\KernelObjects\\CritSecOutOfMemoryEvent";

        UNICODE_STRING ObjectName = {
            sizeof(Name) - sizeof(wchar_t), sizeof(Name) - sizeof(wchar_t), (PWSTR)Name};
        OBJECT_ATTRIBUTES attr = {sizeof(attr), NULL, &ObjectName};

        HANDLE KeyedEventHandle;

        if (NtOpenKeyedEvent(&KeyedEventHandle, MAXIMUM_ALLOWED, &attr) < 0)
        {
            RaiseStatus(STATUS_RESOURCE_NOT_OWNED);
        }

        if (InterlockedCompareExchange(
                (size_t *)&_GlobalKeyedEventHandle, (size_t)KeyedEventHandle, (size_t)NULL))
        {
            CloseHandle(KeyedEventHandle);
        }
    }
    return _GlobalKeyedEventHandle;
}

static __forceinline HANDLE GetGlobalKeyedEventHandle(HANDLE handle)
{
    if (NtCurrentTeb()->ProcessEnvironmentBlock->OSMajorVersion < 6)
    {
        if (handle == NULL)
        {
            return InitGlobalKeyedEventHandle();
        }
    }
    return handle;
}

/******************************************************************************
 *              NtWaitForKeyedEvent (NTDLL.@)
 */
static NTSTATUS WINAPI
NtWaitForKeyedEventXp(HANDLE handle, PVOID key, BOOLEAN alertable, LARGE_INTEGER *timeout)
{
    return NtWaitForKeyedEvent(GetGlobalKeyedEventHandle(handle), key, alertable, timeout);
}

/******************************************************************************
 *              NtReleaseKeyedEvent (NTDLL.@)
 */
static NTSTATUS WINAPI
NtReleaseKeyedEventXp(HANDLE handle, PVOID key, BOOLEAN alertable, LARGE_INTEGER *timeout)
{
    return NtReleaseKeyedEvent(GetGlobalKeyedEventHandle(handle), key, alertable, timeout);
}

#define NtWaitForKeyedEvent NtWaitForKeyedEventXp
#define NtReleaseKeyedEvent NtReleaseKeyedEventXp

typedef ULONG /* LOGICAL */
    (NTAPI *PRTL_RUN_ONCE_INIT_FN)(
        _Inout_ PRTL_RUN_ONCE RunOnce,
        _Inout_opt_ PVOID Parameter,
        _Inout_opt_ PVOID *Context);

#define interlocked_cmpxchg_ptr InterlockedCompareExchangePointer

/**
 * @brief RtlRunOnce set functions copied from reactos and that's taken from Wine ntdll/sync.c
 * https://github.com/reactos/reactos/blob/master/sdk/lib/rtl/runonce.c
 * RtlRunOnceInitialize
 * RtlRunOnceBeginInitialize
 * RtlRunOnceComplete
 * RtlRunOnceExecuteOnce
 *
 */

/******************************************************************
 *              RtlRunOnceInitialize (NTDLL.@)
 */
void WINAPI RtlRunOnceInitialize(RTL_RUN_ONCE *once) { once->Ptr = NULL; }

/******************************************************************
 *              RtlRunOnceBeginInitialize (NTDLL.@)
 */
DWORD WINAPI RtlRunOnceBeginInitialize(RTL_RUN_ONCE *once, ULONG flags, void **context)
{
    if (flags & RTL_RUN_ONCE_CHECK_ONLY)
    {
        ULONG_PTR val = (ULONG_PTR)once->Ptr;

        if (flags & RTL_RUN_ONCE_ASYNC)
            return STATUS_INVALID_PARAMETER;
        if ((val & 3) != 2)
            return STATUS_UNSUCCESSFUL;
        if (context)
            *context = (void *)(val & ~3);
        return STATUS_SUCCESS;
    }

    for (;;)
    {
        ULONG_PTR next, val = (ULONG_PTR)once->Ptr;

        switch (val & 3)
        {
        case 0: /* first time */
            if (!interlocked_cmpxchg_ptr(
                    &once->Ptr, (flags & RTL_RUN_ONCE_ASYNC) ? (void *)3 : (void *)1, 0))
                return STATUS_PENDING;
            break;

        case 1: /* in progress, wait */
            if (flags & RTL_RUN_ONCE_ASYNC)
                return STATUS_INVALID_PARAMETER;
            next = val & ~3;
            if (interlocked_cmpxchg_ptr(&once->Ptr, (void *)((ULONG_PTR)&next | 1), (void *)val) ==
                (void *)val)
                NtWaitForKeyedEvent(0, &next, FALSE, NULL);
            break;

        case 2: /* done */
            if (context)
                *context = (void *)(val & ~3);
            return STATUS_SUCCESS;

        case 3: /* in progress, async */
            if (!(flags & RTL_RUN_ONCE_ASYNC))
                return STATUS_INVALID_PARAMETER;
            return STATUS_PENDING;
        }
    }
}

/******************************************************************
 *              RtlRunOnceComplete (NTDLL.@)
 */
DWORD WINAPI RtlRunOnceComplete(RTL_RUN_ONCE *once, ULONG flags, void *context)
{
    if ((ULONG_PTR)context & 3)
        return STATUS_INVALID_PARAMETER;

    if (flags & RTL_RUN_ONCE_INIT_FAILED)
    {
        if (context)
            return STATUS_INVALID_PARAMETER;
        if (flags & RTL_RUN_ONCE_ASYNC)
            return STATUS_INVALID_PARAMETER;
    }
    else
        context = (void *)((ULONG_PTR)context | 2);

    for (;;)
    {
        ULONG_PTR val = (ULONG_PTR)once->Ptr;

        switch (val & 3)
        {
        case 1: /* in progress */
            if (interlocked_cmpxchg_ptr(&once->Ptr, context, (void *)val) != (void *)val)
                break;
            val &= ~3;
            while (val)
            {
                ULONG_PTR next = *(ULONG_PTR *)val;
                NtReleaseKeyedEvent(0, (void *)val, FALSE, NULL);
                val = next;
            }
            return STATUS_SUCCESS;

        case 3: /* in progress, async */
            if (!(flags & RTL_RUN_ONCE_ASYNC))
                return STATUS_INVALID_PARAMETER;
            if (interlocked_cmpxchg_ptr(&once->Ptr, context, (void *)val) != (void *)val)
                break;
            return STATUS_SUCCESS;

        default:
            return STATUS_UNSUCCESSFUL;
        }
    }
}

/******************************************************************
 *              RtlRunOnceExecuteOnce (NTDLL.@)
 */
DWORD WINAPI
RtlRunOnceExecuteOnce(RTL_RUN_ONCE *once, PRTL_RUN_ONCE_INIT_FN func, void *param, void **context)
{
    DWORD ret = RtlRunOnceBeginInitialize(once, 0, context);

    if (ret != STATUS_PENDING)
        return ret;

    if (!func(once, param, context))
    {
        RtlRunOnceComplete(once, RTL_RUN_ONCE_INIT_FAILED, NULL);
        return STATUS_UNSUCCESSFUL;
    }

    return RtlRunOnceComplete(once, 0, context ? *context : NULL);
}

#undef interlocked_cmpxchg_ptr
