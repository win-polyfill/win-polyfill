

/* ntdll */
__wp_expand_function(ntdll, NtCreateFile, -1);
__wp_expand_function(ntdll, NtClose, -1);
__wp_expand_function(ntdll, NtQueryDirectoryFile, -1);
__wp_expand_function(ntdll, NtQueryInformationFile, -1);
__wp_expand_function(ntdll, NtSetInformationFile, -1);
__wp_expand_function(ntdll, RtlNtStatusToDosError, -1);
__wp_expand_function(ntdll, RtlDetermineDosPathNameType_U, -1);
__wp_expand_function(ntdll, RtlDosPathNameToNtPathName_U, -1);
__wp_expand_function(ntdll, RtlDosPathNameToNtPathName_U_WithStatus, -1);
__wp_expand_function(ntdll, RtlFreeUnicodeString, -1);
__wp_expand_function(ntdll, NtQueryObject, -1);
__wp_expand_function(ntdll, NtQueryInformationThread, -1);
__wp_expand_function(ntdll, NtQueryInformationProcess, -1);
__wp_expand_function(ntdll, NtQuerySystemInformation, -1);
__wp_expand_function(ntdll, NtOpenKeyedEvent, -1);
__wp_expand_function(ntdll, NtWaitForKeyedEvent, -1);
__wp_expand_function(ntdll, NtReleaseKeyedEvent, -1);
__wp_expand_function(ntdll, RtlAdjustPrivilege, -1);
__wp_expand_function(ntdll, RtlPcToFileHeader, -1);
__wp_expand_function(ntdll, LdrAddRefDll, -1);
__wp_expand_function(ntdll, RtlWow64EnableFsRedirectionEx, -1);
__wp_expand_function(ntdll, LdrLoadDll, -1);
__wp_expand_function(ntdll, RtlDllShutdownInProgress, -1);

/* advapi32 */

/* gdi32 */
__wp_expand_function(gdi32, GetDeviceCaps, 8);

/* kernel32 */
__wp_expand_function(kernel32, AddDllDirectory, -1);

/* setupapi */
__wp_expand_function(setupapi, SetupDiGetClassRegistryPropertyW, 32);
__wp_expand_function(setupapi, SetupDiSetDeviceRegistryPropertyW, 20);
__wp_expand_function(setupapi, SetupDiSetClassRegistryPropertyW, 24);
__wp_expand_function(setupapi, SetupDiGetDeviceRegistryPropertyW, 28);

/* user32 */
__wp_expand_function(user32, GetSystemMetrics, 4);
__wp_expand_function(user32, GetDC, 4);
__wp_expand_function(user32, ReleaseDC, 8);
__wp_expand_function(user32, AdjustWindowRectEx, 16);
__wp_expand_function(user32, SystemParametersInfoW, 16);
__wp_expand_function(user32, MonitorFromWindow, 8);
__wp_expand_function(user32, UpdateLayeredWindow, 8);
__wp_expand_function(user32, ChangeWindowMessageFilter, 8);
__wp_expand_function(user32, SendMessageW, -1);
__wp_expand_function(user32, MapWindowPoints, -1);
__wp_expand_function(user32, FindWindowW, -1);
__wp_expand_function(user32, FindWindowExW, -1);
__wp_expand_function(user32, GetWindowThreadProcessId, -1);
