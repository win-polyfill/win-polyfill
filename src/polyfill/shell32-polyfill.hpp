

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
__DEFINE_THUNK(
    shell32,
    -1,
    HRESULT,
    WINAPI,
    SHGetStockIconInfo,
    SHSTOCKICONID siid,
    UINT uFlags,
    _Inout_ SHSTOCKICONINFO *psii)
{
    if (const auto pSHGetStockIconInfo = wp_get_SHGetStockIconInfo())
    {
        return pSHGetStockIconInfo(siid, uFlags, psii);
    }

    // TODO
    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN6)

#if (WP_SUPPORT_VERSION < NTDDI_WIN7)
// Windows 7 [desktop apps | UWP apps]
// Windows Server 2008 R2 [desktop apps | UWP apps]

__DEFINE_THUNK(
    shell32,
    -1,
    HRESULT,
    WINAPI,
    Shell_NotifyIconGetRect,
    const NOTIFYICONIDENTIFIER *identifier,
    RECT *iconLocation)
{
    if (const auto pShell_NotifyIconGetRect = wp_get_Shell_NotifyIconGetRect())
    {
        return pShell_NotifyIconGetRect(identifier, iconLocation);
    }

    TBBUTTON buttonData;
    DWORD processID = 0;
    HWND trayHandle = wp_get_FindWindowW()(L"Shell_TrayWnd", NULL);

    // find the toolbar used in the notification area
    if (trayHandle)
    {
        trayHandle = wp_get_FindWindowExW()(trayHandle, NULL, L"TrayNotifyWnd", NULL);
        if (trayHandle)
        {
            HWND hwnd = wp_get_FindWindowExW()(trayHandle, NULL, L"SysPager", NULL);
            if (hwnd)
            {
                hwnd = wp_get_FindWindowExW()(hwnd, NULL, L"ToolbarWindow32", NULL);
                if (hwnd)
                    trayHandle = hwnd;
            }
        }
    }

    HRESULT ret = __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
    if (!trayHandle)
        return ret;

    wp_get_GetWindowThreadProcessId()(trayHandle, &processID);
    if (processID <= 0)
        return ret;

    HANDLE trayProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ, 0, processID);
    if (!trayProcess)
        return ret;

    int buttonCount = wp_get_SendMessageW()(trayHandle, TB_BUTTONCOUNT, 0, 0);
    LPVOID data = VirtualAllocEx(trayProcess, NULL, sizeof(TBBUTTON), MEM_COMMIT, PAGE_READWRITE);

    if (buttonCount < 1 || !data)
    {
        CloseHandle(trayProcess);
        return ret;
    }

    struct AppData
    {
        HWND hwnd;
        UINT uID;
    };
    // search for our icon among all toolbar buttons
    for (int toolbarButton = 0; toolbarButton < buttonCount; ++toolbarButton)
    {
        SIZE_T numBytes = 0;
        AppData appData = {0, 0};
        wp_get_SendMessageW()(trayHandle, TB_GETBUTTON, toolbarButton, (LPARAM)data);

        if (!ReadProcessMemory(trayProcess, data, &buttonData, sizeof(TBBUTTON), &numBytes))
            continue;

        if (!ReadProcessMemory(
                trayProcess, (LPVOID)buttonData.dwData, &appData, sizeof(AppData), &numBytes))
            continue;

        bool isHidden = buttonData.fsState & TBSTATE_HIDDEN;

        if (identifier->hWnd == appData.hwnd && appData.uID == identifier->uID && !isHidden)
        {
            wp_get_SendMessageW()(trayHandle, TB_GETITEMRECT, toolbarButton, (LPARAM)data);
            if (ReadProcessMemory(trayProcess, data, iconLocation, sizeof(RECT), &numBytes))
            {
                if (wp_get_MapWindowPoints()(trayHandle, NULL, (LPPOINT)iconLocation, 2))
                {
                    iconLocation->left += 1;
                    iconLocation->right -= 1;
                    iconLocation->top += 1;
                    iconLocation->bottom -= 1;
                    if (iconLocation->right > iconLocation->left &&
                        iconLocation->bottom > iconLocation->top)
                    {
                        ret = HRESULT_FROM_WIN32(ERROR_SUCCESS);
                    }
                    else
                    {
                        SetLastError(ERROR_POINT_NOT_FOUND);
                    }
                }
            }
            if (ret != HRESULT_FROM_WIN32(ERROR_SUCCESS))
            {
                ret = HRESULT_FROM_WIN32(GetLastError());
            }
        }
    }
    VirtualFreeEx(trayProcess, data, 0, MEM_RELEASE);
    CloseHandle(trayProcess);
    return ret;
}

__DEFINE_THUNK(shell32, -1, HRESULT, WINAPI, SetCurrentProcessExplicitAppUserModelID, PCWSTR AppID)
{
    if (const auto pSetCurrentProcessExplicitAppUserModelID =
            wp_get_SetCurrentProcessExplicitAppUserModelID())
    {
        return pSetCurrentProcessExplicitAppUserModelID(AppID);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN7)
