

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)

__DEFINE_THUNK(
    user32,
    -1,
    BOOL,
    WINAPI,
    UpdateLayeredWindowIndirect,
    _In_ HWND hWnd,
    _In_ const UPDATELAYEREDWINDOWINFO *pULWInfo)
{
    if (auto const pUpdateLayeredWindowIndirect = wp_get_UpdateLayeredWindowIndirect())
    {
        return pUpdateLayeredWindowIndirect(hWnd, pULWInfo);
    }

    // TODO: not all parameter are used
    return wp_get_UpdateLayeredWindow()(
        hWnd,
        pULWInfo->hdcDst,
        (POINT *)pULWInfo->pptDst,
        (SIZE *)pULWInfo->psize,
        pULWInfo->hdcSrc,
        (POINT *)pULWInfo->pptSrc,
        pULWInfo->crKey,
        (BLENDFUNCTION *)pULWInfo->pblend,
        pULWInfo->dwFlags);
}

__DEFINE_THUNK(
    user32,
    -1,
    HPOWERNOTIFY,
    WINAPI,
    RegisterPowerSettingNotification,
    IN HANDLE hRecipient,
    IN LPCGUID PowerSettingGuid,
    IN DWORD Flags)
{
    if (auto const pRegisterPowerSettingNotification = wp_get_RegisterPowerSettingNotification())
    {
        return pRegisterPowerSettingNotification(hRecipient, PowerSettingGuid, Flags);
    }

    SetLastError(ERROR_NOT_SUPPORTED);
    return nullptr;
}

__DEFINE_THUNK(user32, -1, BOOL, WINAPI, UnregisterPowerSettingNotification, IN HPOWERNOTIFY Handle)
{
    if (auto const pUnregisterPowerSettingNotification =
            wp_get_UnregisterPowerSettingNotification())
    {
        return pUnregisterPowerSettingNotification(Handle);
    }

    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN6)

#if (WP_SUPPORT_VERSION < NTDDI_WIN7)
// Windows 7 [desktop apps | UWP apps]
// Windows Server 2008 R2 [desktop apps | UWP apps]

__DEFINE_THUNK(user32, -1, BOOL, WINAPI, CloseTouchInputHandle, HTOUCHINPUT hTouchInput)
{
    if (auto pCloseTouchInputHandle = wp_get_CloseTouchInputHandle())
    {
        return pCloseTouchInputHandle(hTouchInput);
    }
    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

__DEFINE_THUNK(
    user32,
    -1,
    BOOL,
    WINAPI,
    GetTouchInputInfo,
    _In_ HTOUCHINPUT hTouchInput,              // input event handle; from touch message lParam
    _In_ UINT cInputs,                         // number of elements in the array
    _Out_writes_(cInputs) PTOUCHINPUT pInputs, // array of touch inputs
    _In_ int cbSize)
{
    if (auto pGetTouchInputInfo = wp_get_GetTouchInputInfo())
    {
        return pGetTouchInputInfo(hTouchInput, cInputs, pInputs, cbSize);
    }
    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

__DEFINE_THUNK(user32, -1, BOOL, WINAPI, IsTouchWindow, _In_ HWND hwnd, _Out_opt_ PULONG pulFlags)
{
    if (auto pIsTouchWindow = wp_get_IsTouchWindow())
    {
        return pIsTouchWindow(hwnd, pulFlags);
    }
    return FALSE;
}

__DEFINE_THUNK(user32, -1, BOOL, WINAPI, UnregisterTouchWindow, _In_ HWND hwnd)
{
    if (auto pUnregisterTouchWindow = wp_get_UnregisterTouchWindow())
    {
        return pUnregisterTouchWindow(hwnd);
    }
    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

__DEFINE_THUNK(user32, -1, BOOL, WINAPI, RegisterTouchWindow, _In_ HWND hwnd, _In_ ULONG ulFlags)
{
    if (auto pRegisterTouchWindow = wp_get_RegisterTouchWindow())
    {
        return pRegisterTouchWindow(hwnd, ulFlags);
    }
    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

__DEFINE_THUNK(
    user32,
    -1,
    BOOL,
    WINAPI,
    ChangeWindowMessageFilterEx,
    _In_ HWND hwnd,                                      // Window
    _In_ UINT message,                                   // WM_ message
    _In_ DWORD action,                                   // Message filter action value
    _Inout_opt_ PCHANGEFILTERSTRUCT pChangeFilterStruct) // Optional
{
    if (auto pChangeWindowMessageFilterEx = wp_get_ChangeWindowMessageFilterEx())
    {
        return pChangeWindowMessageFilterEx(hwnd, message, action, pChangeFilterStruct);
    }
    if (auto pChangeWindowMessageFilter = wp_get_ChangeWindowMessageFilter())
    {
        switch (action)
        {
        case MSGFLT_ALLOW:
            return pChangeWindowMessageFilter(message, MSGFLT_ADD);
        case MSGFLT_DISALLOW:
            return pChangeWindowMessageFilter(message, MSGFLT_REMOVE);
        default:
            break;
        }
    }
    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN7)
