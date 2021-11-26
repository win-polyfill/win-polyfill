

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)

// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]
__DEFINE_THUNK(
    version,
    20,
    BOOL,
    APIENTRY,
    GetFileVersionInfoExW,
    _In_ DWORD dwFlags,
    _In_ LPCWSTR lpwstrFilename,
    _Reserved_ DWORD dwHandle,
    _In_ DWORD dwLen,
    _Out_writes_bytes_(dwLen) LPVOID lpData)
{
    if (auto pGetFileVersionInfoExW = wp_get_GetFileVersionInfoExW())
    {
        return pGetFileVersionInfoExW(dwFlags, lpwstrFilename, dwHandle, dwLen, lpData);
    }

    return GetFileVersionInfoW(lpwstrFilename, dwHandle, dwLen, lpData);
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)

// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]
__DEFINE_THUNK(
    version,
    20,
    BOOL,
    APIENTRY,
    GetFileVersionInfoExA,
    _In_ DWORD dwFlags,
    _In_ LPCSTR lpwstrFilename,
    _Reserved_ DWORD dwHandle,
    _In_ DWORD dwLen,
    _Out_writes_bytes_(dwLen) LPVOID lpData)
{
    if (auto pGetFileVersionInfoExA = wp_get_GetFileVersionInfoExA())
    {
        return pGetFileVersionInfoExA(dwFlags, lpwstrFilename, dwHandle, dwLen, lpData);
    }

    return GetFileVersionInfoA(lpwstrFilename, dwHandle, dwLen, lpData);
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)

// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]
__DEFINE_THUNK(
    version,
    12,
    DWORD,
    APIENTRY,
    GetFileVersionInfoSizeExW,
    _In_ DWORD dwFlags,
    _In_ LPCWSTR lpwstrFilename,
    _Out_ LPDWORD lpdwHandle)
{
    if (auto pGetFileVersionInfoSizeExW = wp_get_GetFileVersionInfoSizeExW())
    {
        return pGetFileVersionInfoSizeExW(dwFlags, lpwstrFilename, lpdwHandle);
    }

    return GetFileVersionInfoSizeW(lpwstrFilename, lpdwHandle);
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)

// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]
__DEFINE_THUNK(
    version,
    12,
    DWORD,
    APIENTRY,
    GetFileVersionInfoSizeExA,
    _In_ DWORD dwFlags,
    _In_ LPCSTR lpwstrFilename,
    _Out_ LPDWORD lpdwHandle)
{
    if (auto pGetFileVersionInfoSizeExA = wp_get_GetFileVersionInfoSizeExA())
    {
        return pGetFileVersionInfoSizeExA(dwFlags, lpwstrFilename, lpdwHandle);
    }

    return GetFileVersionInfoSizeA(lpwstrFilename, lpdwHandle);
}
#endif
