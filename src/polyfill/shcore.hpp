

#if (WP_SUPPORT_VERSION < NTDDI_WINBLUE)

// Windows 8.1 [desktop apps only]
// Windows Server 2012 R2 [desktop apps only]
__DEFINE_THUNK(
    shcore,
    16,
    HRESULT,
    STDAPICALLTYPE,
    GetDpiForMonitor,
    _In_ HMONITOR hmonitor,
    _In_ MONITOR_DPI_TYPE dpiType,
    _Out_ UINT *dpiX,
    _Out_ UINT *dpiY)
{
    if (auto const pGetDpiForMonitor = wp_get_GetDpiForMonitor())
    {
        return pGetDpiForMonitor(hmonitor, dpiType, dpiX, dpiY);
    }

    if (dpiX == nullptr || dpiY == nullptr)
    {
        return __HRESULT_FROM_WIN32(ERROR_INVALID_ADDRESS);
    }

    auto DpiForSystem = internal::GetDpiForSystemDownlevel();

    *dpiX = DpiForSystem;
    *dpiY = DpiForSystem;

    return S_OK;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WINBLUE)

// Windows 8.1 [desktop apps only]
// Windows Server 2012 R2 [desktop apps only]
__DEFINE_THUNK(
    shcore,
    4,
    HRESULT,
    STDAPICALLTYPE,
    SetProcessDpiAwareness,
    _In_ PROCESS_DPI_AWARENESS value)
{
    if (auto const pSetProcessDpiAwareness = wp_get_SetProcessDpiAwareness())
    {
        return pSetProcessDpiAwareness(value);
    }

    if (value != PROCESS_DPI_UNAWARE)
    {
        return wp_SetProcessDPIAware() ? S_OK : E_FAIL;
    }

    return S_OK;
}
#endif
