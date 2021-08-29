# win-polyfill list

A list of Win32 APIs that polyfilled for old Windows.
Polyfill more Win32 APIs are welcome.

> Do not use API with leading `*`, just getting the compiling procedure working. If we used, then
> the old Windows system will have performance penaty.

| Function                                                                                                                           | Fallback
| ----                                                                                                                           | -----------
| [DecodePointer](https://msdn.microsoft.com/library/bb432242.aspx)                                                              | When not exist, return the pointer itself.
| [EncodePointer](https://msdn.microsoft.com/library/bb432254.aspx)                                                              | When not exist, return the pointer itself.
| [RegDeleteKeyExW(A)](https://msdn.microsoft.com/library/windows/desktop/ms724847.aspx)                                         | When not exist, calling to RegDeleteKeyW(A).
| [Wow64DisableWow64FsRedirection](https://msdn.microsoft.com/library/windows/desktop/aa365743.aspx)                             | When not exist, return FALSE, and setting LastError = ERROR_INVALID_FUNCTION.
| [Wow64RevertWow64FsRedirection](https://msdn.microsoft.com/library/windows/desktop/aa365745.aspx)                              | When not exist, return FALSE, and setting LastError = ERROR_INVALID_FUNCTION.
| [Wow64EnableWow64FsRedirection](https://msdn.microsoft.com/library/windows/desktop/aa365744.aspx)                              | When not exist, return FALSE, and setting LastError = ERROR_INVALID_FUNCTION.
| [IsWow64Process](https://msdn.microsoft.com/library/windows/desktop/ms684139.aspx)                                             | When not exist, return TRUE, and setting `*Wow64Process = FALSE`.
| [IsWow64Message](https://msdn.microsoft.com/library/windows/desktop/ms684136.aspx)                                             | When not exist, return FALSE.
| [RegSetKeyValueW(A)](https://msdn.microsoft.com/library/ms724921.aspx)                                                         | calling RegCreateKeyExW(A) and RegSetValueExW(A).
| [RegDeleteKeyValueW(A)](https://msdn.microsoft.com/library/ms724848.aspx)                                                      | calling RegOpenKeyExW(A) and RegDeleteValueW(A).
| [RegDeleteTreeW(A)](https://msdn.microsoft.com/library/aa379776.aspx)                                                          | calling SHDeleteKeyW(A).
| [RegGetValueW(A)](https://msdn.microsoft.com/library/aa379776.aspx)                                                            | When not exist, calling to RegQueryValueExW(A).
| [RegCopyTreeW(A)](https://docs.microsoft.com/windows/win32/api/winreg/nf-winreg-regcopytreew)                                  | When not exist, calling to SHCopyKeyW(A).
| [IsWow64Process2](https://msdn.microsoft.com/library/windows/desktop/mt804318.aspx)                                            | When not exist, calling to IsWow64Process.
| [IsWow64GuestMachineSupported](https://msdn.microsoft.com/library/windows/desktop/mt804321.aspx)                               | When not exist, calling to GetNativeSystemInfo.
| [GetTickCount64](https://msdn.microsoft.com/library/windows/desktop/ms724411.aspx)                                             | When not exist, calling to GetTickCount.
| [GetSystemTimePreciseAsFileTime](https://msdn.microsoft.com/library/windows/desktop/hh706895.aspx)                             | When not exist, calling to GetSystemTimeAsFileTime.
| [InitializeCriticalSectionEx](https://msdn.microsoft.com/library/ms683477.aspx)                                                | When not exist, calling to InitializeCriticalSectionAndSpinCount.
| [InitOnceInitialize](https://msdn.microsoft.com/library/ms683495.aspx)                                                         | Initialized to INIT_ONCE_STATIC_INIT.
| [InitOnceBeginInitialize](https://msdn.microsoft.com/library/ms683487.aspx)                                                    | When not exist, calling to NtWaitForKeyedEvent.
| [InitOnceComplete](https://msdn.microsoft.com/library/ms683491.aspx)                                                           | When not exist, calling to NtReleaseKeyedEvent.
| [InitOnceExecuteOnce](https://msdn.microsoft.com/library/windows/desktop/ms683493.aspx)                                        | When not exist, calling to NtWaitForKeyedEvent and NtReleaseKeyedEvent.
| [LocaleNameToLCID](https://docs.microsoft.com/windows/desktop/api/winnls/nf-winnls-localenametolcid)                           | When not exist, check LocaleNameToLcidTable.
| [LCIDToLocaleName](https://docs.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcidtolocalename)                           | When not exist, check LcidToLocaleNameTable.
| [GetLocaleInfoEx](https://docs.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex)                             | When not exist, calling to GetLocaleInfoW.
| [GetDateFormatEx](https://docs.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformatex)                   | When not exist, calling to GetDateFormatW.
| [GetTimeFormatEx](https://docs.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformatex)                   | When not exist, calling to GetTimeFormatW.
| [GetNumberFormatEx](https://docs.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnumberformatex)                         | When not exist, calling to GetNumberFormatW.
| [GetCurrencyFormatEx](https://docs.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcurrencyformatex)                     | When not exist, calling to GetCurrencyFormatW.
| [GetUserDefaultLocaleName](https://docs.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlocalename)           | When not exist, calling to LCIDToLocaleName.
| [GetSystemDefaultLocaleName](https://docs.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlocalename)       | When not exist, calling to LCIDToLocaleName.
| [EnumCalendarInfoExEx](https://docs.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexex)                   | When not exist, calling to EnumCalendarInfoExW.
| [EnumDateFormatsExEx](https://docs.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex)                     | When not exist, calling to EnumDateFormatsExW.
| [GetFileInformationByHandleEx](https://docs.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex) | When not exist, calling to NtQueryInformationFile or NtQueryDirectoryFile.
| [SetFileInformationByHandle](https://docs.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)   | When not exist, calling to NtSetInformationFile.
| [GetFinalPathNameByHandleW(A)](https://docs.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfinalpathnamebyhandlew)    | When not exist, calling to NtQueryObject and NtQueryInformationFile.
| [GetLogicalProcessorInformation](https://msdn.microsoft.com/library/ms683194.aspx)                                             | When not exist, return FALSE, and setting LastError = ERROR_INVALID_FUNCTION.
| [GetLogicalProcessorInformationEx](https://msdn.microsoft.com/library/dd405488.aspx)                                           | When not exist, calling to GetLogicalProcessorInformation.
| [InetPtonW(inet_pton)](https://docs.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetptonw)                          | When not exist, use sscanf to parse it.
| [InetNtopW(inet_ntop)](https://docs.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)                          | When not exist, use sprintf to construct the string.
| [WSAPoll](https://docs.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsapoll)                                           | When not exist, calling to select.
| [GetNumaHighestNodeNumber](https://msdn.microsoft.com/library/windows/desktop/ms683203.aspx)                                   | When not exist, return 0.
| [RaiseFailFastException](https://msdn.microsoft.com/library/windows/desktop/dd941688.aspx)                                     | When not exist, calling to TerminateProcess.
| [GetThreadId](https://docs.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadid)               | When not exist, calling to NtQueryInformationThread.
| [GetProcessIdOfThread](https://msdn.microsoft.com/library/ms683216.aspx)                                                       | When not exist, calling to NtQueryInformationThread.
| [GetProcessId](https://docs.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessid)             | When not exist, calling to NtQueryInformationProcess.
| [QueryThreadCycleTime](https://docs.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-querythreadcycletime)   | When not exist, calling to GetThreadTimes.
| [QueryProcessCycleTime](https://docs.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryprocesscycletime) | When not exist, calling to GetProcessTimes.
| [K32EnumProcessModules](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocessmodules)                      | calling EnumProcessModules.
| [K32EnumProcessModulesEx](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocessmodulesex)                  | calling EnumProcessModulesEx.
| [K32GetModuleBaseNameW(A)](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmodulebasenamea)                   | calling GetModuleBaseNameW(A).
| [K32GetModuleFileNameExW(A)](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmodulefilenameexw)               | calling K32GetModuleFileNameExW(A).
| [K32EmptyWorkingSet](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-emptyworkingset)                            | calling EmptyWorkingSet.
| [K32QueryWorkingSet](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-queryworkingset)                            | calling QueryWorkingSet.
| [K32QueryWorkingSetEx](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-queryworkingsetex)                        | calling QueryWorkingSetEx.
| [K32InitializeProcessForWsWatch](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-initializeprocessforwswatch)    | calling InitializeProcessForWsWatch.
| [K32GetWsChanges](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-getwschanges)                                  | calling GetWsChanges.
| [K32GetWsChangesEx](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-getwschangesex)                              | calling GetWsChangesEx.
| [K32GetMappedFileNameW(A)](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmappedfilenamew)                   | calling GetMappedFileNameW(A).
| [K32EnumDeviceDrivers](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumdevicedrivers)                        | calling EnumDeviceDrivers.
| [K32GetDeviceDriverBaseNameW(A)](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-getdevicedriverbasenamew)       | calling GetDeviceDriverBaseNameW(A).
| [K32GetDeviceDriverFileNameW(A)](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-getdevicedriverfilenamew)       | calling GetDeviceDriverFileNameW(A).
| [K32GetPerformanceInfo](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-getperformanceinfo)                      | calling GetPerformanceInfo.
| [K32EnumPageFilesW(A)](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumpagefilesw)                           | calling EnumPageFilesW(A).
| [K32GetProcessImageFileNameW(A)](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumpagefilesw)                 | calling GetProcessImageFileNameW(A).
| [EnumProcessModulesEx](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocessmodulesex)                     | When not exist, calling to EnumProcessModules.
| [GetWsChangesEx](https://docs.microsoft.com/windows/desktop/api/psapi/nf-psapi-getwschangesex)                                 | When not exist, calling to GetWsChanges.
| [QueryFullProcessImageNameW(A)](https://docs.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryfullprocessimagenamew)  | When not exist, calling to GetProcessImageFileNameW(A) or GetModuleFileNameExW(A).
| [CreateFile2](https://docs.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfile2)                                   | When not exist, calling to CreateFileW.
| [CreateEventExW(A)](https://docs.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventexw)                        | When not exist, calling to CreateEventW(A).
| [CreateMutexExW(A)](https://docs.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexexw)                        | When not exist, calling to CreateMutexW(A).
| [CreateSemaphoreExW](https://docs.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createsemaphoreexw)                   | When not exist, calling to CreateSemaphoreW.
| [CreateWaitableTimerExW](https://docs.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createwaitabletimerexw)           | When not exist, calling to CreateWaitableTimerW.
| [GetFileVersionInfoExW(A)](https://docs.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizeexw)          | When not exist, calling to GetFileVersionInfoW(A).
| [GetFileVersionInfoSizeExW(A)](https://docs.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizeexw)      | When not exist, calling to GetFileVersionInfoSizeW(A).
| [InterlockedCompareExchange64](https://docs.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedcompareexchange64)     | calling to interal function _InterlockedCompareExchange64.
| [SetThreadErrorMode](https://docs.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setthreaderrormode)       | When not exist, calling to SetErrorMode.
| [GetThreadErrorMode](https://docs.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getthreaderrormode)       | When not exist, calling to GetErrorMode.
| [GetErrorMode](https://docs.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-geterrormode)                   | When not exist, calling to NtQueryInformationProcess.
| [InitializeSRWLock](https://docs.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initializesrwlock)                     | Initialized to RTL_SRWLOCK_INIT.
| [AcquireSRWLockExclusive](https://docs.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-acquiresrwlockexclusive)         | When not exist, calling to NtWaitForKeyedEvent.
| [TryAcquireSRWLockExclusive](https://msdn.microsoft.com/library/Dd405523.aspx)                                                 | When not exist, calling to InterlockedBitTestAndSet(64).
| [ReleaseSRWLockExclusive](https://msdn.microsoft.com/library/ms685076.aspx)                                                    | When not exist, calling to NtReleaseKeyedEvent.
| [AcquireSRWLockShared](https://msdn.microsoft.com/library/ms681934.aspx)                                                       | When not exist, calling to NtWaitForKeyedEvent.
| [TryAcquireSRWLockShared](https://msdn.microsoft.com/library/Dd405524.aspx)                                                    | When not exist, calling to InterlockedCompareExchange.
| [ReleaseSRWLockShared](https://msdn.microsoft.com/library/ms685080.aspx)                                                       | When not exist, calling to NtReleaseKeyedEvent.
| [InitializeConditionVariable](https://docs.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializeconditionvariable)   | Initialized to CONDITION_VARIABLE_INIT.
| [SleepConditionVariableCS](https://docs.microsoft.com/windows/win32/api/synchapi/nf-synchapi-sleepconditionvariablecs)         | When not exist, calling to NtWaitForKeyedEvent.
| [SleepConditionVariableSRW](https://docs.microsoft.com/windows/win32/api/synchapi/nf-synchapi-sleepconditionvariablesrw)       | When not exist, calling to NtWaitForKeyedEvent.
| [WakeConditionVariable](https://docs.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakeconditionvariable)               | When not exist, calling to NtReleaseKeyedEvent.
| [WakeAllConditionVariable](https://docs.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakeallconditionvariable)         | When not exist, calling to NtReleaseKeyedEvent.
| [InitializeSynchronizationBarrier](https://msdn.microsoft.com/library/hh706890.aspx)                                           | When not exist, calling to CreateEvent.
| [EnterSynchronizationBarrier](https://msdn.microsoft.com/library/hh706889.aspx)                                                | When not exist, calling to WaitForSingleObject.
| [DeleteSynchronizationBarrier](https://msdn.microsoft.com/library/hh706887.aspx)                                               | When not exist, calling to CloseHandle.
| [WaitOnAddress](https://docs.microsoft.com/windows/desktop/api/SynchAPI/nf-synchapi-waitonaddress)                             | When not exist, calling to NtWaitForKeyedEvent.*WARNING*, do not use this function cross module!!!
| [WakeByAddressSingle](https://docs.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakebyaddresssingle)                   | When not exist, calling to NtReleaseKeyedEvent.*WARNING*, do not use this function cross module!!!
| [WakeByAddressAll](https://docs.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakebyaddressall)                         | When not exist, calling to NtReleaseKeyedEvent.*WARNING*, do not use this function cross module!!!
| *[GetCurrentProcessorNumber](https://msdn.microsoft.com/library/windows/desktop/ms683181.aspx)                                 | When not exist, return 0.
| *[GetCurrentProcessorNumberEx](https://msdn.microsoft.com/library/windows/desktop/dd405487.aspx)                               | When not exist, calling to GetCurrentProcessorNumber.
| *[GetNumaNodeProcessorMask](https://msdn.microsoft.com/library/windows/desktop/ms683204.aspx)                                  | When not exist, return FALSE, and setting LastError = ERROR_INVALID_PARAMETER.
| *[GetNumaNodeProcessorMaskEx](https://msdn.microsoft.com/library/windows/desktop/dd405493.aspx)                                | When not exist, calling to GetNumaNodeProcessorMask.
| *[SetThreadGroupAffinity](https://msdn.microsoft.com/library/windows/desktop/dd405516.aspx)                                    | When not exist, calling to SetThreadAffinityMask.
| *[CancelIoEx](https://docs.microsoft.com/windows/desktop/FileIO/cancelioex-func)                                               | When not exist, calling to CancelIo(`Will cancel all IO operation bind to this HANDLE`).
| *[QueryWorkingSetEx](https://docs.microsoft.com/windows/desktop/api/Psapi/nf-psapi-getwschangesex)                             | When not exist, return FALSE, and setting LastError = ERROR_INVALID_FUNCTION.
| [SHGetKnownFolderPath](https://docs.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath)           | When not exist, calling to SHGetFolderPathW.
| [SHSetKnownFolderPath](https://docs.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-shsetknownfolderpath)           | When not exist, calling to SHSetFolderPathW.
| [SHGetKnownFolderIDList](https://docs.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-shgetknownfolderidlist)       | When not exist, calling to SHGetFolderLocation.
| [SHBindToFolderIDListParent](https://docs.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-shbindtofolderidlistparent)      | When not exist, calling to IShellFolder.
| [SHBindToFolderIDListParentEx](https://docs.microsoft.com//windows/win32/api/shlobj_core/nf-shlobj_core-shbindtofolderidlistparentex) | When not exist, calling to IShellFolder.
| [SHBindToObject](https://docs.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-shbindtoobject)                        | When not exist, calling to IShellFolder.
| [SHCreateItemFromIDList](https://docs.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromidlist)    | When not exist, calling to IShellItem.
| [SHCreateItemWithParent](https://docs.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-shcreateitemwithparent)    | When not exist, calling to IShellItem.
| [SHCreateItemFromRelativeName](https://docs.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromrelativename) | When not exist, calling to IShellItem.
| [SHGetNameFromIDList](https://docs.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-shgetnamefromidlist)          | When not exist, calling to IShellItem.
| [SHCreateShellItem](https://docs.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-shcreateshellitem)                  | When not exist, calling to IShellItem.
| [OpenFileById](https://docs.microsoft.com/windows/win32/api/winbase/nf-winbase-openfilebyid)                                    | When not exist, calling to NtCreateFile.
| [CreateSymbolicLinkW(A)](https://docs.microsoft.com/windows/win32/api/winbase/nf-winbase-createsymboliclinkw)                   | When not exist, return FALSE, and setting LastError = ERROR_INVALID_FUNCTION.
| [ReOpenFile](https://docs.microsoft.com/windows/win32/api/winbase/nf-winbase-reopenfile)                                        | When not exist, calling to NtCreateFile.
| [CompareStringEx](https://docs.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-comparestringex)                    | When not exist, calling to CompareStringW.
| [CompareStringOrdinal](https://docs.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-comparestringordinal)          | When not exist, calling to internal UnicodeCaseTableData to implement this function.
| [SetFilePointerEx](https://docs.microsoft.com/windows/win32/api/fileapi/nf-fileapi-setfilepointerex)                            | When not exist, calling to SetFilePointer.
| [GetModuleHandleExW(A)](https://docs.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandleexw)           | When not exist, calling to GetModuleHandleW(A).
| [WTSGetActiveConsoleSessionId](https://docs.microsoft.com/windows/win32/api/winbase/nf-winbase-wtsgetactiveconsolesessionid)    | When not exist, return  0.
| [StrToInt64ExW(A)](https://docs.microsoft.com/windows/win32/api/shlwapi/nf-shlwapi-strtoint64exw)                               | When not exist, parse to int64 manually.
| [GetNativeSystemInfo](https://docs.microsoft.com/windows/win32/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo)                | When not exist, calling to GetSystemInfo.
| [InitializeSListHead](https://docs.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-initializeslisthead)        | Initialized to 0.
| [InterlockedFlushSList](https://docs.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedflushslist)    | When not exist, calling to lock cmpxchg8b instruction.
| [QueryDepthSList](https://docs.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-querydepthslist)                | When not exist, return Depth.
| [InterlockedPushEntrySList](https://docs.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpushentryslist) | When not exist, calling to lock cmpxchg8b instruction.
| [InterlockedPopEntrySList](https://docs.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpopentryslist) | When not exist, calling to lock cmpxchg8b instruction.
| [SetupDiGetDevicePropertyW](https://docs.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdigetdevicepropertyw)        | When not exist, calling to SetupDiGetDeviceRegistryPropertyW.
| [SetupDiSetDevicePropertyW](https://docs.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdisetdevicepropertyw)        | When not exist, calling to SetupDiSetDeviceRegistryPropertyW.
| [SetupDiGetClassPropertyW](https://docs.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdigetclasspropertyw)          | When not exist, calling to SetupDiGetClassRegistryPropertyW.
| [SetupDiGetClassPropertyExW](https://docs.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdigetclasspropertyexw)      | When not exist, calling to SetupDiGetClassRegistryPropertyW.
| [SetupDiSetClassPropertyW](https://docs.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdisetclasspropertyw)          | When not exist, calling to SetupDiSetClassRegistryPropertyW.
| [SetupDiSetClassPropertyExW](https://docs.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdisetclasspropertyexw)      | When not exist, calling to SetupDiSetClassRegistryPropertyW.
| [GetDpiForMonitor](https://docs.microsoft.com/windows/win32/api/shellscalingapi/nf-shellscalingapi-getdpiformonitor)            | When not exist, calling to GetDeviceCaps.
| [SetProcessDpiAwareness](https://docs.microsoft.com/windows/win32/api/shellscalingapi/nf-shellscalingapi-setprocessdpiawareness)| When not exist, calling to SetProcessDPIAware.
| [SetProcessDPIAware](https://docs.microsoft.com/windows/win32/api/shellscalingapi/nf-shellscalingapi-setprocessdpiawareness)    | When not exist, return TRUE.
| [SetProcessDpiAwarenessContext](https://docs.microsoft.com/windows/win32/api/winuser/nf-winuser-setprocessdpiawarenesscontext)  | When not exist, calling to SetProcessDpiAwareness.
| [GetDpiForSystem](https://docs.microsoft.com/windows/win32/api/winuser/nf-winuser-getdpiforsystem)                              | When not exist, calling to GetDeviceCaps.
| [GetDpiForWindow](https://docs.microsoft.com/windows/win32/api/winuser/nf-winuser-getdpiforwindow)                              | When not exist, calling to GetDpiForMonitor.
| [GetSystemMetricsForDpi](https://docs.microsoft.com/windows/win32/api/winuser/nf-winuser-getsystemmetricsfordpi)                | When not exist, calling to GetSystemMetrics.
| [AdjustWindowRectExForDpi](https://docs.microsoft.com/windows/win32/api/winuser/nf-winuser-adjustwindowrectexfordpi)            | When not exist, calling to AdjustWindowRectEx.
| [SystemParametersInfoForDpi](https://docs.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfofordpi)        | When not exist, calling to SystemParametersInfoW.
