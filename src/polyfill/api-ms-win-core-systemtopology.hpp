﻿

#if (WP_SUPPORT_VERSION < NTDDI_WINXPSP2)

// Windows Vista, Windows XP Professional x64 Edition, Windows XP with SP2, Windows Server 2003
__DEFINE_THUNK(
    kernel32,
    8,
    BOOL,
    WINAPI,
    GetNumaNodeProcessorMask,
    _In_ UCHAR Node,
    _Out_ PULONGLONG ProcessorMask)
{
    if (auto pGetNumaNodeProcessorMask = wp_get_GetNumaNodeProcessorMask())
    {
        return pGetNumaNodeProcessorMask(Node, ProcessorMask);
    }

    if (Node == 0)
    {
        // 因为我们假定只有一个 Node，所以所有处理器必然在这个 Node 中。

        SYSTEM_INFO SystemInfo;
        GetSystemInfo(&SystemInfo);

        *ProcessorMask = (1ull << SystemInfo.dwNumberOfProcessors) - 1;

        return TRUE;
    }

    // 不支持此接口
    SetLastError(ERROR_INVALID_PARAMETER);
    return FALSE;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN7)

// Windows 7, Windows Server 2008 R2
__DEFINE_THUNK(
    kernel32,
    8,
    BOOL,
    WINAPI,
    GetNumaNodeProcessorMaskEx,
    _In_ USHORT Node,
    _Out_ PGROUP_AFFINITY ProcessorMask)
{
    if (auto pGetNumaNodeProcessorMaskEx = wp_get_GetNumaNodeProcessorMaskEx())
    {
        return pGetNumaNodeProcessorMaskEx(Node, ProcessorMask);
    }
    else
    {
        ULONGLONG ullProcessorMask;
        auto bRet = GetNumaNodeProcessorMask(Node, &ullProcessorMask);

        if (bRet)
        {
            ProcessorMask->Mask = ullProcessorMask;
            // 假定只有一组CPU
            ProcessorMask->Group = 0;
            ProcessorMask->Reserved[0] = 0;
            ProcessorMask->Reserved[1] = 0;
            ProcessorMask->Reserved[2] = 0;
        }

        return bRet;
    }
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN7)

// Windows 7, Windows Server 2008 R2
__DEFINE_THUNK(
    kernel32,
    12,
    BOOL,
    WINAPI,
    SetThreadGroupAffinity,
    _In_ HANDLE hThread,
    _In_ CONST GROUP_AFFINITY *GroupAffinity,
    _Out_opt_ PGROUP_AFFINITY PreviousGroupAffinity)
{
    if (auto pSetThreadGroupAffinity = wp_get_SetThreadGroupAffinity())
    {
        return pSetThreadGroupAffinity(hThread, GroupAffinity, PreviousGroupAffinity);
    }

    auto NewMask = SetThreadAffinityMask(hThread, GroupAffinity->Mask);

    if (NewMask == 0)
    {
        return FALSE;
    }

    if (PreviousGroupAffinity)
    {
        PreviousGroupAffinity->Mask = NewMask;
        PreviousGroupAffinity->Group = 0;
        PreviousGroupAffinity->Reserved[0] = 0;
        PreviousGroupAffinity->Reserved[1] = 0;
        PreviousGroupAffinity->Reserved[2] = 0;
    }

    return TRUE;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WINXPSP2)

// Windows Vista, Windows XP Professional x64 Edition, Windows XP with SP2 [desktop apps only]
// Windows Server 2003 [desktop apps only]
__DEFINE_THUNK(kernel32, 4, BOOL, WINAPI, GetNumaHighestNodeNumber, _Out_ PULONG HighestNodeNumber)
{
    if (auto pGetNumaHighestNodeNumber = wp_get_GetNumaHighestNodeNumber())
    {
        return pGetNumaHighestNodeNumber(HighestNodeNumber);
    }

    // 不支持时始终假定只有一个NUMA节点
    *HighestNodeNumber = 0;

    return TRUE;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN7)

// Minimum supported client	Windows 7 [desktop apps only]
// Minimum supported server	Windows Server 2008 R2 [desktop apps only]
__DEFINE_THUNK(
    kernel32,
    8,
    _Success_(return) BOOL,
    WINAPI,
    GetNumaProximityNodeEx,
    _In_ ULONG ProximityId,
    _Out_ PUSHORT NodeNumber)
{
    if (const auto pGetNumaProximityNodeEx = wp_get_GetNumaProximityNodeEx())
    {
        return pGetNumaProximityNodeEx(ProximityId, NodeNumber);
    }

    UCHAR NodeNumberTmp;
    auto bRet = wp_GetNumaProximityNode(ProximityId, &NodeNumberTmp);
    if (bRet)
    {
        *NodeNumber = NodeNumberTmp;
    }

    return bRet;
}
#endif
