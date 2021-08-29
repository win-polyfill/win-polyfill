

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
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
    if (const auto pCreateNamedPipeW = wp_get_CreateNamedPipeW())
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

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
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
    if (const auto pGetUserPreferredUILanguages = wp_get_GetUserPreferredUILanguages())
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

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN6)

#if (WP_SUPPORT_VERSION < NTDDI_WIN7)
// Windows 7 [desktop apps | UWP apps]
// Windows Server 2008 R2 [desktop apps | UWP apps]

__DEFINE_THUNK(kernel32, -1, HANDLE, WINAPI, PowerCreateRequest, _In_ PREASON_CONTEXT Context)
{
    if (const auto pPowerCreateRequest = wp_get_PowerCreateRequest())
    {
        return pPowerCreateRequest(Context);
    }
    return INVALID_HANDLE_VALUE;
}

__DEFINE_THUNK(
    kernel32,
    -1,
    BOOL,
    WINAPI,
    PowerSetRequest,
    _In_ HANDLE PowerRequest,
    _In_ POWER_REQUEST_TYPE RequestType)
{
    if (const auto pPowerSetRequest = wp_get_PowerSetRequest())
    {
        return pPowerSetRequest(PowerRequest, RequestType);
    }
    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

__DEFINE_THUNK(
    kernel32,
    -1,
    BOOL,
    WINAPI,
    PowerClearRequest,
    _In_ HANDLE PowerRequest,
    _In_ POWER_REQUEST_TYPE RequestType)
{
    if (const auto pPowerClearRequest = wp_get_PowerClearRequest())
    {
        return pPowerClearRequest(PowerRequest, RequestType);
    }
    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

__DEFINE_THUNK(
    kernel32,
    -1,
    BOOL,
    WINAPI,
    QueryUnbiasedInterruptTime,
    _Out_ PULONGLONG UnbiasedTime)
{
    if (const auto pQueryUnbiasedInterruptTime = wp_get_QueryUnbiasedInterruptTime())
    {
        return pQueryUnbiasedInterruptTime(UnbiasedTime);
    }
    if (!UnbiasedTime)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }
    *UnbiasedTime = ::wp_GetTickCount64();
    return TRUE;
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN7)
