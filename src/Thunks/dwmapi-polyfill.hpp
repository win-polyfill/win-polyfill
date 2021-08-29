﻿

#if (YY_Thunks_Support_Version < NTDDI_WIN6)
// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]

__DEFINE_THUNK(
    dwmapi,
    -1,
    BOOL,
    STDAPICALLTYPE,
    DwmDefWindowProc,
    _In_ HWND hWnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam,
    _Out_ LRESULT *plResult)
{
    if (auto const pDwmDefWindowProc = try_get_DwmDefWindowProc())
    {
        return pDwmDefWindowProc(hWnd, msg, wParam, lParam, plResult);
    }

    return FALSE;
}

__DEFINE_THUNK(dwmapi, -1, HRESULT, STDAPICALLTYPE, DwmIsCompositionEnabled, _Out_ BOOL *pfEnabled)
{
    if (auto const pDwmIsCompositionEnabled = try_get_DwmIsCompositionEnabled())
    {
        return pDwmIsCompositionEnabled(pfEnabled);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(
    dwmapi,
    -1,
    HRESULT,
    STDAPICALLTYPE,
    DwmExtendFrameIntoClientArea,
    HWND hWnd,
    _In_ const MARGINS *pMarInset)
{
    if (auto const pDwmExtendFrameIntoClientArea = try_get_DwmExtendFrameIntoClientArea())
    {
        return pDwmExtendFrameIntoClientArea(hWnd, pMarInset);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(dwmapi, -1, HRESULT, STDAPICALLTYPE, DwmInvalidateIconicBitmaps, HWND hwnd)
{
    if (auto const pDwmInvalidateIconicBitmaps = try_get_DwmInvalidateIconicBitmaps())
    {
        return pDwmInvalidateIconicBitmaps(hwnd);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(
    dwmapi,
    -1,
    HRESULT,
    STDAPICALLTYPE,
    DwmSetIconicLivePreviewBitmap,
    HWND hwnd,
    HBITMAP hbmp,
    _In_opt_ POINT *pptClient,
    DWORD dwSITFlags)
{
    if (auto const pDwmSetIconicLivePreviewBitmap = try_get_DwmSetIconicLivePreviewBitmap())
    {
        return pDwmSetIconicLivePreviewBitmap(hwnd, hbmp, pptClient, dwSITFlags);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(
    dwmapi,
    -1,
    HRESULT,
    STDAPICALLTYPE,
    DwmSetIconicThumbnail,
    HWND hwnd,
    HBITMAP hbmp,
    DWORD dwSITFlags)
{
    if (auto const pDwmSetIconicThumbnail = try_get_DwmSetIconicThumbnail())
    {
        return pDwmSetIconicThumbnail(hwnd, hbmp, dwSITFlags);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(
    dwmapi,
    -1,
    HRESULT,
    STDAPICALLTYPE,
    DwmSetWindowAttribute,
    HWND hwnd,
    DWORD dwAttribute,
    _In_reads_bytes_(cbAttribute) LPCVOID pvAttribute,
    DWORD cbAttribute)
{
    if (auto const pDwmSetWindowAttribute = try_get_DwmSetWindowAttribute())
    {
        return pDwmSetWindowAttribute(hwnd, dwAttribute, pvAttribute, cbAttribute);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(
    dwmapi,
    -1,
    HRESULT,
    STDAPICALLTYPE,
    DwmGetWindowAttribute,
    HWND hwnd,
    DWORD dwAttribute,
    _Out_writes_bytes_(cbAttribute) PVOID pvAttribute,
    DWORD cbAttribute)
{
    if (auto const pDwmGetWindowAttribute = try_get_DwmGetWindowAttribute())
    {
        return pDwmGetWindowAttribute(hwnd, dwAttribute, pvAttribute, cbAttribute);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(
    dwmapi,
    -1,
    HRESULT,
    STDAPICALLTYPE,
    DwmGetColorizationColor,
    _Out_ DWORD *pcrColorization,
    _Out_ BOOL *pfOpaqueBlend)
{
    if (auto const pDwmGetColorizationColor = try_get_DwmGetColorizationColor())
    {
        return pDwmGetColorizationColor(pcrColorization, pfOpaqueBlend);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

__DEFINE_THUNK(dwmapi, -1, HRESULT, STDAPICALLTYPE, DwmEnableComposition, UINT uCompositionAction)
{
    if (auto const pDwmEnableComposition = try_get_DwmEnableComposition())
    {
        return pDwmEnableComposition(uCompositionAction);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif /* (YY_Thunks_Support_Version < NTDDI_WIN6) */
