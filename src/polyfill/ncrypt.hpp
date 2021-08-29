

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]

__DEFINE_THUNK(ncrypt, -1, SECURITY_STATUS, WINAPI, NCryptFreeObject, _In_ NCRYPT_HANDLE hObject)

{
    if (auto const pNCryptFreeObject = wp_get_NCryptFreeObject())
    {
        return pNCryptFreeObject(hObject);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(
    ncrypt,
    -1,
    _Check_return_ SECURITY_STATUS,
    WINAPI,
    NCryptSignHash,
    _In_ NCRYPT_KEY_HANDLE hKey,
    _In_opt_ VOID *pPaddingInfo,
    _In_reads_bytes_(cbHashValue) PBYTE pbHashValue,
    _In_ DWORD cbHashValue,
    _Out_writes_bytes_to_opt_(cbSignature, *pcbResult) PBYTE pbSignature,
    _In_ DWORD cbSignature,
    _Out_ DWORD *pcbResult,
    _In_ DWORD dwFlags)
{
    if (auto const pNCryptSignHash = wp_get_NCryptSignHash())
    {
        return pNCryptSignHash(
            hKey,
            pPaddingInfo,
            pbHashValue,
            cbHashValue,
            pbSignature,
            cbSignature,
            pcbResult,
            dwFlags);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN6)
