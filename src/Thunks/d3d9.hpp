

#if (YY_Thunks_Support_Version < NTDDI_WIN6)
// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]

__DEFINE_THUNK(d3d9, -1, HRESULT, WINAPI, Direct3DCreate9Ex, UINT SDKVersion, IDirect3D9Ex **out)
{
    if (auto const pDirect3DCreate9Ex = try_get_Direct3DCreate9Ex())
    {
        return pDirect3DCreate9Ex(SDKVersion, out);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif // (YY_Thunks_Support_Version < NTDDI_WIN6)
