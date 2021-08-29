

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]

__DEFINE_THUNK(
    advapi32,
    -1,
    ULONG,
    __stdcall,
    EventWriteTransfer,
    _In_ REGHANDLE RegHandle,
    _In_ PCEVENT_DESCRIPTOR EventDescriptor,
    _In_opt_ LPCGUID ActivityId,
    _In_opt_ LPCGUID RelatedActivityId,
    _In_range_(0, MAX_EVENT_DATA_DESCRIPTORS) ULONG UserDataCount,
    _In_reads_opt_(UserDataCount) PEVENT_DATA_DESCRIPTOR UserData)
{
    if (auto const pEventWriteTransfer = wp_get_EventWriteTransfer())
    {
        return pEventWriteTransfer(
            RegHandle, EventDescriptor, ActivityId, RelatedActivityId, UserDataCount, UserData);
    }

    return ERROR_NOT_SUPPORTED;
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN6)
