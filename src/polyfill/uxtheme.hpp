

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]

__DEFINE_THUNK(
    uxtheme,
    -1,
    HRESULT,
    STDAPICALLTYPE,
    DrawThemeTextEx,
    _In_ HTHEME hTheme,
    _In_ HDC hdc,
    _In_ int iPartId,
    _In_ int iStateId,
    _In_reads_(cchText) LPCWSTR pszText,
    _In_ int cchText,
    _In_ DWORD dwTextFlags,
    _Inout_ LPRECT pRect,
    _In_opt_ const DTTOPTS *pOptions)
{
    if (auto const pDrawThemeTextEx = wp_get_DrawThemeTextEx())
    {
        return pDrawThemeTextEx(
            hTheme, hdc, iPartId, iStateId, pszText, cchText, dwTextFlags, pRect, pOptions);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(
    uxtheme,
    -1,
    HRESULT,
    STDAPICALLTYPE,
    SetWindowThemeAttribute,
    _In_ HWND hwnd,
    _In_ enum WINDOWTHEMEATTRIBUTETYPE eAttribute,
    _In_reads_bytes_(cbAttribute) PVOID pvAttribute,
    _In_ DWORD cbAttribute)
{
    if (auto const pSetWindowThemeAttribute = wp_get_SetWindowThemeAttribute())
    {
        return pSetWindowThemeAttribute(hwnd, eAttribute, pvAttribute, cbAttribute);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(
    uxtheme,
    -1,
    HRESULT,
    STDAPICALLTYPE,
    GetThemeTransitionDuration,
    _In_ HTHEME hTheme,
    _In_ int iPartId,
    _In_ int iStateIdFrom,
    _In_ int iStateIdTo,
    _In_ int iPropId,
    _Out_ DWORD *pdwDuration)
{
    if (auto const pGetThemeTransitionDuration = wp_get_GetThemeTransitionDuration())
    {
        return pGetThemeTransitionDuration(
            hTheme, iPartId, iStateIdFrom, iStateIdTo, iPropId, pdwDuration);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(
    uxtheme,
    -1,
    HRESULT,
    STDAPICALLTYPE,
    GetThemePartSize,
    _In_ HTHEME hTheme,
    _In_opt_ HDC hdc,
    _In_ int iPartId,
    _In_ int iStateId,
    _In_opt_ LPCRECT prc,
    _In_ enum THEMESIZE eSize,
    _Out_ SIZE *psz)
{
    if (auto const pGetThemePartSize = wp_get_GetThemePartSize())
    {
        return pGetThemePartSize(hTheme, hdc, iPartId, iStateId, prc, eSize, psz);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN6)
