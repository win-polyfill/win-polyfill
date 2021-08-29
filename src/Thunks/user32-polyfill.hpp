

#if (YY_Thunks_Support_Version < NTDDI_WIN6)

__DEFINE_THUNK(
    user32,
    -1,
    BOOL,
    WINAPI,
    UpdateLayeredWindowIndirect,
    _In_ HWND hWnd,
    _In_ const UPDATELAYEREDWINDOWINFO *pULWInfo)
{
    if (auto const pUpdateLayeredWindowIndirect = try_get_UpdateLayeredWindowIndirect())
    {
        return pUpdateLayeredWindowIndirect(hWnd, pULWInfo);
    }

    // TODO: not all parameter are used
    return UpdateLayeredWindow(
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
    if (auto const pRegisterPowerSettingNotification = try_get_RegisterPowerSettingNotification())
    {
        return pRegisterPowerSettingNotification(hRecipient, PowerSettingGuid, Flags);
    }

    SetLastError(ERROR_NOT_SUPPORTED);
    return nullptr;
}

__DEFINE_THUNK(user32, -1, BOOL, WINAPI, UnregisterPowerSettingNotification, IN HPOWERNOTIFY Handle)
{
    if (auto const pUnregisterPowerSettingNotification =
            try_get_UnregisterPowerSettingNotification())
    {
        return pUnregisterPowerSettingNotification(Handle);
    }

    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

#endif // (YY_Thunks_Support_Version < NTDDI_WIN6)

#if (YY_Thunks_Support_Version < NTDDI_WIN7)
// Windows 7 [desktop apps | UWP apps]
// Windows Server 2008 R2 [desktop apps | UWP apps]

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
    if (auto pChangeWindowMessageFilterEx = try_get_ChangeWindowMessageFilterEx())
    {
        return pChangeWindowMessageFilterEx(hwnd, message, action, pChangeFilterStruct);
    }
    if (auto pChangeWindowMessageFilter = try_get_ChangeWindowMessageFilter())
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

#endif // (YY_Thunks_Support_Version < NTDDI_WIN7)
