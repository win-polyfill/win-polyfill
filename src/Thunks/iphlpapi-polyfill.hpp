

#if (YY_Thunks_Support_Version < NTDDI_WIN6)
// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]

__DEFINE_THUNK(
    iphlpapi,
    -1,
    NETIO_STATUS,
    WINAPI,
    ConvertInterfaceNameToLuidW,
    _In_z_ CONST WCHAR *InterfaceName,
    _Out_ NET_LUID *InterfaceLuid)
{
    if (auto const pConvertInterfaceNameToLuidW = try_get_ConvertInterfaceNameToLuidW())
    {
        return pConvertInterfaceNameToLuidW(InterfaceName, InterfaceLuid);
    }

    return ERROR_NOT_SUPPORTED;
}

__DEFINE_THUNK(
    iphlpapi,
    -1,
    NETIO_STATUS,
    WINAPI,
    ConvertInterfaceLuidToNameW,
    _In_ CONST NET_LUID *InterfaceLuid,
    _Out_writes_(Length) PWSTR InterfaceName,
    _In_ SIZE_T Length)
{
    if (auto const pConvertInterfaceLuidToNameW = try_get_ConvertInterfaceLuidToNameW())
    {
        return pConvertInterfaceLuidToNameW(InterfaceLuid, InterfaceName, Length);
    }

    return ERROR_NOT_SUPPORTED;
}

__DEFINE_THUNK(
    iphlpapi,
    -1,
    NETIO_STATUS,
    WINAPI,
    ConvertInterfaceLuidToIndex,
    _In_ CONST NET_LUID *InterfaceLuid,
    _Out_ PNET_IFINDEX InterfaceIndex)
{
    if (auto const pConvertInterfaceLuidToIndex = try_get_ConvertInterfaceLuidToIndex())
    {
        return pConvertInterfaceLuidToIndex(InterfaceLuid, InterfaceIndex);
    }

    return ERROR_NOT_SUPPORTED;
}

__DEFINE_THUNK(
    iphlpapi,
    -1,
    NETIO_STATUS,
    WINAPI,
    ConvertInterfaceIndexToLuid,
    _In_ NET_IFINDEX InterfaceIndex,
    _Out_ PNET_LUID InterfaceLuid)
{
    if (auto const pConvertInterfaceIndexToLuid = try_get_ConvertInterfaceIndexToLuid())
    {
        return pConvertInterfaceIndexToLuid(InterfaceIndex, InterfaceLuid);
    }

    return ERROR_NOT_SUPPORTED;
}

#endif // (YY_Thunks_Support_Version < NTDDI_WIN6)
