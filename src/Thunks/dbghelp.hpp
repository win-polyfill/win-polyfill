

#if (YY_Thunks_Support_Version < NTDDI_WIN6)
// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]

__DEFINE_THUNK(
    dbghelp,
    -1,
    BOOL,
    __stdcall,
    SymGetSearchPathW,
    _In_ HANDLE hProcess,
    _Out_writes_(SearchPathLength) PWSTR SearchPath,
    _In_ DWORD SearchPathLength)
{
    if (auto const pSymGetSearchPathW = try_get_SymGetSearchPathW())
    {
        return pSymGetSearchPathW(hProcess, SearchPath, SearchPathLength);
    }

    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

__DEFINE_THUNK(
    dbghelp,
    -1,
    BOOL,
    __stdcall,
    SymSetSearchPathW,
    _In_ HANDLE hProcess,
    _In_opt_ PCWSTR SearchPath)
{
    if (auto const pSymSetSearchPathW = try_get_SymSetSearchPathW())
    {
        return pSymSetSearchPathW(hProcess, SearchPath);
    }

    SetLastError(ERROR_NOT_SUPPORTED);
    return FALSE;
}

#endif // (YY_Thunks_Support_Version < NTDDI_WIN6)
