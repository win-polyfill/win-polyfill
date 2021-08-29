

#if (YY_Thunks_Support_Version < NTDDI_WIN6)
// Windows Vista,  Windows Server 2008
__DEFINE_THUNK(
    kernel32,
    -1,
    HANDLE,
    WINAPI,
    CreateNamedPipeW,
    _In_ LPCWSTR lpName,
    _In_ DWORD dwOpenMode,
    _In_ DWORD dwPipeMode,
    _In_ DWORD nMaxInstances,
    _In_ DWORD nOutBufferSize,
    _In_ DWORD nInBufferSize,
    _In_ DWORD nDefaultTimeOut,
    _In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
    if (const auto pCreateNamedPipeW = try_get_CreateNamedPipeW())
    {
        /* According to
         * https://stackoverflow.com/questions/11004775/createnamedpipe-without-pipe-reject-remote-clients
         * PIPE_REJECT_REMOTE_CLIENTS only supports Windows Vista and upper
         */
        if (NtCurrentTeb()->ProcessEnvironmentBlock->OSMajorVersion < 6)
        {
            if (dwPipeMode & PIPE_REJECT_REMOTE_CLIENTS)
            {
                dwPipeMode -= PIPE_REJECT_REMOTE_CLIENTS;
            }
        }
        return pCreateNamedPipeW(
            lpName,
            dwOpenMode,
            dwPipeMode,
            nMaxInstances,
            nOutBufferSize,
            nInBufferSize,
            nDefaultTimeOut,
            lpSecurityAttributes);
    }

    return INVALID_HANDLE_VALUE;
}
#endif

#if (YY_Thunks_Support_Version < NTDDI_WIN6)
// Windows Vista,  Windows Server 2008

__DEFINE_THUNK(
    kernel32,
    -1,
    BOOL,
    WINAPI,
    GetUserPreferredUILanguages,
    _In_ DWORD dwFlags,
    _Out_ PULONG pulNumLanguages,
    _Out_writes_opt_(*pcchLanguagesBuffer) PZZWSTR pwszLanguagesBuffer,
    _Inout_ PULONG pcchLanguagesBuffer)
{
    if (const auto pGetUserPreferredUILanguages = try_get_GetUserPreferredUILanguages())
    {
        return pGetUserPreferredUILanguages(
            dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer);
    }

    {
        wchar_t lang[16];
        wchar_t country[16];
        const int langrc = GetLocaleInfoW(
            LOCALE_USER_DEFAULT, LOCALE_SISO639LANGNAME, lang, sizeof(lang) / sizeof(lang[0]));

        const int ctryrc = GetLocaleInfoW(
            LOCALE_USER_DEFAULT,
            LOCALE_SISO3166CTRYNAME,
            country,
            sizeof(country) / sizeof(country[0]));

        /* Win95 systems will fail, because they don't have LOCALE_SISO*NAME ... */
        if (langrc == 0)
        {
            return FALSE;
        }
        else
        {
            *pulNumLanguages = 1;
            int count = _snwprintf(
                pwszLanguagesBuffer,
                *pcchLanguagesBuffer,
                L"%s%s%s",
                lang,
                ctryrc ? L"_" : L"",
                ctryrc ? country : L"");
            if (count < 0)
            {
                return FALSE;
            }
            if (pwszLanguagesBuffer == NULL)
            {
                *pcchLanguagesBuffer = count + 1;
            }
            else
            {
                *pcchLanguagesBuffer = count;
            }
            return TRUE;
        }
    }
}

#endif // (YY_Thunks_Support_Version < NTDDI_WIN6)

#if (YY_Thunks_Support_Version < NTDDI_WIN7)
// Windows 7 [desktop apps | UWP apps]
// Windows Server 2008 R2 [desktop apps | UWP apps]

__DEFINE_THUNK(
    kernel32,
    -1,
    BOOL,
    WINAPI,
    QueryUnbiasedInterruptTime,
    _Out_ PULONGLONG UnbiasedTime)
{
    if (const auto pQueryUnbiasedInterruptTime = try_get_QueryUnbiasedInterruptTime())
    {
        return pQueryUnbiasedInterruptTime(UnbiasedTime);
    }
    if (!UnbiasedTime)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }
    *UnbiasedTime = GetTickCount64();
    return TRUE;
}

#endif // (YY_Thunks_Support_Version < NTDDI_WIN7)
