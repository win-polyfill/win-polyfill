

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]

__DEFINE_THUNK(
    d3d11,
    -1,
    HRESULT,
    WINAPI,
    D3D11CreateDevice,
    _In_opt_ IDXGIAdapter *pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    _In_reads_opt_(FeatureLevels) CONST D3D_FEATURE_LEVEL *pFeatureLevels,
    UINT FeatureLevels,
    UINT SDKVersion,
    _COM_Outptr_opt_ ID3D11Device **ppDevice,
    _Out_opt_ D3D_FEATURE_LEVEL *pFeatureLevel,
    _COM_Outptr_opt_ ID3D11DeviceContext **ppImmediateContext)
{
    if (auto const pD3D11CreateDevice = wp_get_D3D11CreateDevice())
    {
        return pD3D11CreateDevice(
            pAdapter,
            DriverType,
            Software,
            Flags,
            pFeatureLevels,
            FeatureLevels,
            SDKVersion,
            ppDevice,
            pFeatureLevel,
            ppImmediateContext);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN6)
