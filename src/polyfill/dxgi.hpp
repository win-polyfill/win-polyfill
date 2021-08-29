

#if (WP_SUPPORT_VERSION < NTDDI_WIN7)
// Windows 7 [desktop apps | UWP apps]
// Windows Server 2008 R2 [desktop apps | UWP apps]

__DEFINE_THUNK(
    dxgi,
    -1,
    HRESULT,
    WINAPI,
    CreateDXGIFactory1,
    REFIID riid,
    _COM_Outptr_ void **ppFactory)
{
    if (const auto pCreateDXGIFactory1 = wp_get_CreateDXGIFactory1())
    {
        return pCreateDXGIFactory1(riid, ppFactory);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN7)
