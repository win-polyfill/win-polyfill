

#if (YY_Thunks_Support_Version < NTDDI_WIN6)
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
    if (const auto pSHGetStockIconInfo = try_get_SHGetStockIconInfo())
    {
        return pSHGetStockIconInfo(siid, uFlags, psii);
    }

    // TODO
    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif // (YY_Thunks_Support_Version < NTDDI_WIN6)

#if (YY_Thunks_Support_Version < NTDDI_WIN7)
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
    if (const auto pShell_NotifyIconGetRect = try_get_Shell_NotifyIconGetRect())
    {
        return pShell_NotifyIconGetRect(identifier, iconLocation);
    }

    TBBUTTON buttonData;
    DWORD processID = 0;
    HWND trayHandle = FindWindowW(L"Shell_TrayWnd", NULL);

    // find the toolbar used in the notification area
    if (trayHandle)
    {
        trayHandle = FindWindowExW(trayHandle, NULL, L"TrayNotifyWnd", NULL);
        if (trayHandle)
        {
            HWND hwnd = FindWindowExW(trayHandle, NULL, L"SysPager", NULL);
            if (hwnd)
            {
                hwnd = FindWindowExW(hwnd, NULL, L"ToolbarWindow32", NULL);
                if (hwnd)
                    trayHandle = hwnd;
            }
        }
    }

    HRESULT ret = __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
    if (!trayHandle)
        return ret;

    GetWindowThreadProcessId(trayHandle, &processID);
    if (processID <= 0)
        return ret;

    HANDLE trayProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ, 0, processID);
    if (!trayProcess)
        return ret;

    int buttonCount = SendMessageW(trayHandle, TB_BUTTONCOUNT, 0, 0);
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
        SendMessageW(trayHandle, TB_GETBUTTON, toolbarButton, (LPARAM)data);

        if (!ReadProcessMemory(trayProcess, data, &buttonData, sizeof(TBBUTTON), &numBytes))
            continue;

        if (!ReadProcessMemory(
                trayProcess, (LPVOID)buttonData.dwData, &appData, sizeof(AppData), &numBytes))
            continue;

        bool isHidden = buttonData.fsState & TBSTATE_HIDDEN;

        if (identifier->hWnd == appData.hwnd && appData.uID == identifier->uID && !isHidden)
        {
            SendMessageW(trayHandle, TB_GETITEMRECT, toolbarButton, (LPARAM)data);
            if (ReadProcessMemory(trayProcess, data, iconLocation, sizeof(RECT), &numBytes))
            {
                if (MapWindowPoints(trayHandle, NULL, (LPPOINT)iconLocation, 2))
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
            try_get_SetCurrentProcessExplicitAppUserModelID())
    {
        return pSetCurrentProcessExplicitAppUserModelID(AppID);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif // (YY_Thunks_Support_Version < NTDDI_WIN7)
