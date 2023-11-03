
#pragma once
#include "win-polyfill.h"
#include "win-polyfill-id.h"

using YY::Thunks::internal::WinPolyfillModule;
using YY::Thunks::internal::WinPolyfillModuleId;
using YY::Thunks::internal::WinPolyfillFunction;
using YY::Thunks::internal::WinPolyfillFunctionId;

static void *__fastcall try_get_function(WinPolyfillFunction *function_info, const char *name, WinPolyfillModuleId module_id) noexcept;
static HMODULE __fastcall try_get_module_by_name(WinPolyfillModuleId module_id, const wchar_t *name) noexcept;

static HMODULE try_get_module(WinPolyfillModuleId module_id) noexcept
{
    switch (module_id) {
    case WinPolyfillModuleId::WinPolyfillModuleIdNtdll: {
      return try_get_module_by_name(module_id, L"ntdll.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdKernel32: {
      return try_get_module_by_name(module_id, L"kernel32.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32: {
      return try_get_module_by_name(module_id, L"advapi32.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdGdi32: {
      return try_get_module_by_name(module_id, L"gdi32.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdUser32: {
      return try_get_module_by_name(module_id, L"user32.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdPsapi: {
      return try_get_module_by_name(module_id, L"psapi.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdVersion: {
      return try_get_module_by_name(module_id, L"version.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdOle32: {
      return try_get_module_by_name(module_id, L"ole32.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdIphlpapi: {
      return try_get_module_by_name(module_id, L"iphlpapi.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdPdh: {
      return try_get_module_by_name(module_id, L"pdh.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdShlwapi: {
      return try_get_module_by_name(module_id, L"shlwapi.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdSetupapi: {
      return try_get_module_by_name(module_id, L"setupapi.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdShell32: {
      return try_get_module_by_name(module_id, L"shell32.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdWs2_32: {
      return try_get_module_by_name(module_id, L"ws2_32.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0: {
      return try_get_module_by_name(module_id, L"api-ms-win-core-path-l1-1-0.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_synch_l1_2_0: {
      return try_get_module_by_name(module_id, L"api-ms-win-core-synch-l1-2-0.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_error_l1_1_0: {
      return try_get_module_by_name(module_id, L"api-ms-win-core-winrt-error-l1-1-0.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_string_l1_1_0: {
      return try_get_module_by_name(module_id, L"api-ms-win-core-winrt-string-l1-1-0.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_l1_1_0: {
      return try_get_module_by_name(module_id, L"api-ms-win-core-winrt-l1-1-0.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdPowrprof: {
      return try_get_module_by_name(module_id, L"powrprof.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdBcrypt: {
      return try_get_module_by_name(module_id, L"bcrypt.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdBluetoothapis: {
      return try_get_module_by_name(module_id, L"bluetoothapis.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdDwmapi: {
      return try_get_module_by_name(module_id, L"dwmapi.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdMfplat: {
      return try_get_module_by_name(module_id, L"mfplat.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdNetapi32: {
      return try_get_module_by_name(module_id, L"netapi32.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdShcore: {
      return try_get_module_by_name(module_id, L"shcore.dll");
    }
    case WinPolyfillModuleId::WinPolyfillModuleIdUserenv: {
      return try_get_module_by_name(module_id, L"userenv.dll");
    }
    default: break;
    }
    return nullptr;
}

namespace YY
{
    namespace Thunks
    {
        namespace TryGet
        {
            decltype(&::NtCreateFile) try_get_NtCreateFile()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtCreateFile))try_get_function(
                        &function_info, "NtCreateFile",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtClose) try_get_NtClose()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtClose))try_get_function(
                        &function_info, "NtClose",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtQueryDirectoryFile) try_get_NtQueryDirectoryFile()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtQueryDirectoryFile))try_get_function(
                        &function_info, "NtQueryDirectoryFile",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtQueryInformationFile) try_get_NtQueryInformationFile()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtQueryInformationFile))try_get_function(
                        &function_info, "NtQueryInformationFile",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtQuerySystemInformation) try_get_NtQuerySystemInformation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtQuerySystemInformation))try_get_function(
                        &function_info, "NtQuerySystemInformation",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtSetInformationFile) try_get_NtSetInformationFile()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtSetInformationFile))try_get_function(
                        &function_info, "NtSetInformationFile",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::RtlNtStatusToDosError) try_get_RtlNtStatusToDosError()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RtlNtStatusToDosError))try_get_function(
                        &function_info, "RtlNtStatusToDosError",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::RtlDetermineDosPathNameType_U) try_get_RtlDetermineDosPathNameType_U()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RtlDetermineDosPathNameType_U))try_get_function(
                        &function_info, "RtlDetermineDosPathNameType_U",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::RtlDosPathNameToNtPathName_U) try_get_RtlDosPathNameToNtPathName_U()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RtlDosPathNameToNtPathName_U))try_get_function(
                        &function_info, "RtlDosPathNameToNtPathName_U",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::RtlDosPathNameToNtPathName_U_WithStatus) try_get_RtlDosPathNameToNtPathName_U_WithStatus()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RtlDosPathNameToNtPathName_U_WithStatus))try_get_function(
                        &function_info, "RtlDosPathNameToNtPathName_U_WithStatus",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::RtlFreeUnicodeString) try_get_RtlFreeUnicodeString()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RtlFreeUnicodeString))try_get_function(
                        &function_info, "RtlFreeUnicodeString",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtQueryObject) try_get_NtQueryObject()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtQueryObject))try_get_function(
                        &function_info, "NtQueryObject",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtQueryInformationThread) try_get_NtQueryInformationThread()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtQueryInformationThread))try_get_function(
                        &function_info, "NtQueryInformationThread",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtSetInformationThread) try_get_NtSetInformationThread()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtSetInformationThread))try_get_function(
                        &function_info, "NtSetInformationThread",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtQueryInformationProcess) try_get_NtQueryInformationProcess()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtQueryInformationProcess))try_get_function(
                        &function_info, "NtQueryInformationProcess",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtSetInformationProcess) try_get_NtSetInformationProcess()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtSetInformationProcess))try_get_function(
                        &function_info, "NtSetInformationProcess",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtOpenKeyedEvent) try_get_NtOpenKeyedEvent()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtOpenKeyedEvent))try_get_function(
                        &function_info, "NtOpenKeyedEvent",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtWaitForKeyedEvent) try_get_NtWaitForKeyedEvent()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtWaitForKeyedEvent))try_get_function(
                        &function_info, "NtWaitForKeyedEvent",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtReleaseKeyedEvent) try_get_NtReleaseKeyedEvent()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtReleaseKeyedEvent))try_get_function(
                        &function_info, "NtReleaseKeyedEvent",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::RtlAdjustPrivilege) try_get_RtlAdjustPrivilege()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RtlAdjustPrivilege))try_get_function(
                        &function_info, "RtlAdjustPrivilege",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::RtlPcToFileHeader) try_get_RtlPcToFileHeader()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RtlPcToFileHeader))try_get_function(
                        &function_info, "RtlPcToFileHeader",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::LdrAddRefDll) try_get_LdrAddRefDll()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::LdrAddRefDll))try_get_function(
                        &function_info, "LdrAddRefDll",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::RtlWow64EnableFsRedirectionEx) try_get_RtlWow64EnableFsRedirectionEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RtlWow64EnableFsRedirectionEx))try_get_function(
                        &function_info, "RtlWow64EnableFsRedirectionEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::LdrLoadDll) try_get_LdrLoadDll()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::LdrLoadDll))try_get_function(
                        &function_info, "LdrLoadDll",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::RtlDllShutdownInProgress) try_get_RtlDllShutdownInProgress()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RtlDllShutdownInProgress))try_get_function(
                        &function_info, "RtlDllShutdownInProgress",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::RtlCutoverTimeToSystemTime) try_get_RtlCutoverTimeToSystemTime()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RtlCutoverTimeToSystemTime))try_get_function(
                        &function_info, "RtlCutoverTimeToSystemTime",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::NtCancelIoFile) try_get_NtCancelIoFile()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::NtCancelIoFile))try_get_function(
                        &function_info, "NtCancelIoFile",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&::AddDllDirectory) try_get_AddDllDirectory()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::AddDllDirectory))try_get_function(
                        &function_info, "AddDllDirectory",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&::SystemFunction036) try_get_SystemFunction036()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SystemFunction036))try_get_function(
                        &function_info, "SystemFunction036",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::GetDeviceCaps) try_get_GetDeviceCaps()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetDeviceCaps))try_get_function(
                        &function_info, "GetDeviceCaps",
                        WinPolyfillModuleId::WinPolyfillModuleIdGdi32);
            }

            decltype(&::GetMessageW) try_get_GetMessageW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetMessageW))try_get_function(
                        &function_info, "GetMessageW",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::TranslateMessage) try_get_TranslateMessage()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::TranslateMessage))try_get_function(
                        &function_info, "TranslateMessage",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::DispatchMessageW) try_get_DispatchMessageW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::DispatchMessageW))try_get_function(
                        &function_info, "DispatchMessageW",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::SendMessageW) try_get_SendMessageW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SendMessageW))try_get_function(
                        &function_info, "SendMessageW",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::PostMessageW) try_get_PostMessageW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::PostMessageW))try_get_function(
                        &function_info, "PostMessageW",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::DefWindowProcW) try_get_DefWindowProcW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::DefWindowProcW))try_get_function(
                        &function_info, "DefWindowProcW",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::PostQuitMessage) try_get_PostQuitMessage()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::PostQuitMessage))try_get_function(
                        &function_info, "PostQuitMessage",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::RegisterClassW) try_get_RegisterClassW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegisterClassW))try_get_function(
                        &function_info, "RegisterClassW",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::CreateWindowExW) try_get_CreateWindowExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::CreateWindowExW))try_get_function(
                        &function_info, "CreateWindowExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::DestroyWindow) try_get_DestroyWindow()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::DestroyWindow))try_get_function(
                        &function_info, "DestroyWindow",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::SetTimer) try_get_SetTimer()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SetTimer))try_get_function(
                        &function_info, "SetTimer",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::GetSystemMetrics) try_get_GetSystemMetrics()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetSystemMetrics))try_get_function(
                        &function_info, "GetSystemMetrics",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::GetDC) try_get_GetDC()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetDC))try_get_function(
                        &function_info, "GetDC",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::ReleaseDC) try_get_ReleaseDC()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::ReleaseDC))try_get_function(
                        &function_info, "ReleaseDC",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::AdjustWindowRectEx) try_get_AdjustWindowRectEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::AdjustWindowRectEx))try_get_function(
                        &function_info, "AdjustWindowRectEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::GetWindowLongW) try_get_GetWindowLongW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetWindowLongW))try_get_function(
                        &function_info, "GetWindowLongW",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::SetWindowLongW) try_get_SetWindowLongW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SetWindowLongW))try_get_function(
                        &function_info, "SetWindowLongW",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::SystemParametersInfoW) try_get_SystemParametersInfoW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SystemParametersInfoW))try_get_function(
                        &function_info, "SystemParametersInfoW",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::MonitorFromWindow) try_get_MonitorFromWindow()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::MonitorFromWindow))try_get_function(
                        &function_info, "MonitorFromWindow",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&::EnumProcessModules) try_get_EnumProcessModules()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::EnumProcessModules))try_get_function(
                        &function_info, "EnumProcessModules",
                        WinPolyfillModuleId::WinPolyfillModuleIdPsapi);
            }

            decltype(&::GetModuleFileNameExA) try_get_GetModuleFileNameExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetModuleFileNameExA))try_get_function(
                        &function_info, "GetModuleFileNameExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdPsapi);
            }

            decltype(&::GetModuleFileNameExW) try_get_GetModuleFileNameExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetModuleFileNameExW))try_get_function(
                        &function_info, "GetModuleFileNameExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdPsapi);
            }

            decltype(&::GetWsChanges) try_get_GetWsChanges()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetWsChanges))try_get_function(
                        &function_info, "GetWsChanges",
                        WinPolyfillModuleId::WinPolyfillModuleIdPsapi);
            }

            decltype(&::GetProcessImageFileNameA) try_get_GetProcessImageFileNameA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetProcessImageFileNameA))try_get_function(
                        &function_info, "GetProcessImageFileNameA",
                        WinPolyfillModuleId::WinPolyfillModuleIdPsapi);
            }

            decltype(&::GetProcessImageFileNameW) try_get_GetProcessImageFileNameW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetProcessImageFileNameW))try_get_function(
                        &function_info, "GetProcessImageFileNameW",
                        WinPolyfillModuleId::WinPolyfillModuleIdPsapi);
            }

            decltype(&::RegCloseKey) try_get_RegCloseKey()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegCloseKey))try_get_function(
                        &function_info, "RegCloseKey",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegCreateKeyExA) try_get_RegCreateKeyExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegCreateKeyExA))try_get_function(
                        &function_info, "RegCreateKeyExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegCreateKeyExW) try_get_RegCreateKeyExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegCreateKeyExW))try_get_function(
                        &function_info, "RegCreateKeyExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegDeleteKeyA) try_get_RegDeleteKeyA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegDeleteKeyA))try_get_function(
                        &function_info, "RegDeleteKeyA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegDeleteKeyW) try_get_RegDeleteKeyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegDeleteKeyW))try_get_function(
                        &function_info, "RegDeleteKeyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegDeleteValueA) try_get_RegDeleteValueA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegDeleteValueA))try_get_function(
                        &function_info, "RegDeleteValueA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegDeleteValueW) try_get_RegDeleteValueW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegDeleteValueW))try_get_function(
                        &function_info, "RegDeleteValueW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegEnumKeyW) try_get_RegEnumKeyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegEnumKeyW))try_get_function(
                        &function_info, "RegEnumKeyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegOpenKeyExA) try_get_RegOpenKeyExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegOpenKeyExA))try_get_function(
                        &function_info, "RegOpenKeyExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegOpenKeyExW) try_get_RegOpenKeyExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegOpenKeyExW))try_get_function(
                        &function_info, "RegOpenKeyExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegQueryValueExA) try_get_RegQueryValueExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegQueryValueExA))try_get_function(
                        &function_info, "RegQueryValueExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegQueryValueExW) try_get_RegQueryValueExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegQueryValueExW))try_get_function(
                        &function_info, "RegQueryValueExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegSetValueExA) try_get_RegSetValueExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegSetValueExA))try_get_function(
                        &function_info, "RegSetValueExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::RegSetValueExW) try_get_RegSetValueExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::RegSetValueExW))try_get_function(
                        &function_info, "RegSetValueExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&::GetFileVersionInfoSizeA) try_get_GetFileVersionInfoSizeA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetFileVersionInfoSizeA))try_get_function(
                        &function_info, "GetFileVersionInfoSizeA",
                        WinPolyfillModuleId::WinPolyfillModuleIdVersion);
            }

            decltype(&::GetFileVersionInfoSizeW) try_get_GetFileVersionInfoSizeW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetFileVersionInfoSizeW))try_get_function(
                        &function_info, "GetFileVersionInfoSizeW",
                        WinPolyfillModuleId::WinPolyfillModuleIdVersion);
            }

            decltype(&::GetFileVersionInfoA) try_get_GetFileVersionInfoA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetFileVersionInfoA))try_get_function(
                        &function_info, "GetFileVersionInfoA",
                        WinPolyfillModuleId::WinPolyfillModuleIdVersion);
            }

            decltype(&::GetFileVersionInfoW) try_get_GetFileVersionInfoW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetFileVersionInfoW))try_get_function(
                        &function_info, "GetFileVersionInfoW",
                        WinPolyfillModuleId::WinPolyfillModuleIdVersion);
            }

            decltype(&::CoUninitialize) try_get_CoUninitialize()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::CoUninitialize))try_get_function(
                        &function_info, "CoUninitialize",
                        WinPolyfillModuleId::WinPolyfillModuleIdOle32);
            }

            decltype(&::CoInitializeEx) try_get_CoInitializeEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::CoInitializeEx))try_get_function(
                        &function_info, "CoInitializeEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdOle32);
            }

            decltype(&::CoGetContextToken) try_get_CoGetContextToken()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::CoGetContextToken))try_get_function(
                        &function_info, "CoGetContextToken",
                        WinPolyfillModuleId::WinPolyfillModuleIdOle32);
            }

            decltype(&::CoTaskMemAlloc) try_get_CoTaskMemAlloc()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::CoTaskMemAlloc))try_get_function(
                        &function_info, "CoTaskMemAlloc",
                        WinPolyfillModuleId::WinPolyfillModuleIdOle32);
            }

            decltype(&::CoTaskMemFree) try_get_CoTaskMemFree()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::CoTaskMemFree))try_get_function(
                        &function_info, "CoTaskMemFree",
                        WinPolyfillModuleId::WinPolyfillModuleIdOle32);
            }

            decltype(&::GetIfEntry) try_get_GetIfEntry()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetIfEntry))try_get_function(
                        &function_info, "GetIfEntry",
                        WinPolyfillModuleId::WinPolyfillModuleIdIphlpapi);
            }

            decltype(&::GetIfTable) try_get_GetIfTable()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::GetIfTable))try_get_function(
                        &function_info, "GetIfTable",
                        WinPolyfillModuleId::WinPolyfillModuleIdIphlpapi);
            }

            decltype(&::PdhAddCounterW) try_get_PdhAddCounterW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::PdhAddCounterW))try_get_function(
                        &function_info, "PdhAddCounterW",
                        WinPolyfillModuleId::WinPolyfillModuleIdPdh);
            }

            decltype(&::PdhAddCounterA) try_get_PdhAddCounterA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::PdhAddCounterA))try_get_function(
                        &function_info, "PdhAddCounterA",
                        WinPolyfillModuleId::WinPolyfillModuleIdPdh);
            }

            decltype(&::SHDeleteKeyA) try_get_SHDeleteKeyA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHDeleteKeyA))try_get_function(
                        &function_info, "SHDeleteKeyA",
                        WinPolyfillModuleId::WinPolyfillModuleIdShlwapi);
            }

            decltype(&::SHDeleteKeyW) try_get_SHDeleteKeyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHDeleteKeyW))try_get_function(
                        &function_info, "SHDeleteKeyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdShlwapi);
            }

            decltype(&::SHQueryValueExA) try_get_SHQueryValueExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHQueryValueExA))try_get_function(
                        &function_info, "SHQueryValueExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdShlwapi);
            }

            decltype(&::SHQueryValueExW) try_get_SHQueryValueExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHQueryValueExW))try_get_function(
                        &function_info, "SHQueryValueExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdShlwapi);
            }

            decltype(&::SHCopyKeyA) try_get_SHCopyKeyA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHCopyKeyA))try_get_function(
                        &function_info, "SHCopyKeyA",
                        WinPolyfillModuleId::WinPolyfillModuleIdShlwapi);
            }

            decltype(&::SHCopyKeyW) try_get_SHCopyKeyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHCopyKeyW))try_get_function(
                        &function_info, "SHCopyKeyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdShlwapi);
            }

            decltype(&::SetupDiGetDeviceRegistryPropertyW) try_get_SetupDiGetDeviceRegistryPropertyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SetupDiGetDeviceRegistryPropertyW))try_get_function(
                        &function_info, "SetupDiGetDeviceRegistryPropertyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdSetupapi);
            }

            decltype(&::SetupDiGetClassRegistryPropertyW) try_get_SetupDiGetClassRegistryPropertyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SetupDiGetClassRegistryPropertyW))try_get_function(
                        &function_info, "SetupDiGetClassRegistryPropertyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdSetupapi);
            }

            decltype(&::SetupDiSetDeviceRegistryPropertyW) try_get_SetupDiSetDeviceRegistryPropertyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SetupDiSetDeviceRegistryPropertyW))try_get_function(
                        &function_info, "SetupDiSetDeviceRegistryPropertyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdSetupapi);
            }

            decltype(&::SetupDiSetClassRegistryPropertyW) try_get_SetupDiSetClassRegistryPropertyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SetupDiSetClassRegistryPropertyW))try_get_function(
                        &function_info, "SetupDiSetClassRegistryPropertyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdSetupapi);
            }

            decltype(&::ILClone) try_get_ILClone()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::ILClone))try_get_function(
                        &function_info, "ILClone",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&::ILFree) try_get_ILFree()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::ILFree))try_get_function(
                        &function_info, "ILFree",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&::ILFindLastID) try_get_ILFindLastID()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::ILFindLastID))try_get_function(
                        &function_info, "ILFindLastID",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&::ILRemoveLastID) try_get_ILRemoveLastID()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::ILRemoveLastID))try_get_function(
                        &function_info, "ILRemoveLastID",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&::SHGetFolderPathW) try_get_SHGetFolderPathW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHGetFolderPathW))try_get_function(
                        &function_info, "SHGetFolderPathW",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&::SHGetFolderLocation) try_get_SHGetFolderLocation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHGetFolderLocation))try_get_function(
                        &function_info, "SHGetFolderLocation",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&::SHSetFolderPathW) try_get_SHSetFolderPathW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHSetFolderPathW))try_get_function(
                        &function_info, "SHSetFolderPathW",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&::SHGetDesktopFolder) try_get_SHGetDesktopFolder()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHGetDesktopFolder))try_get_function(
                        &function_info, "SHGetDesktopFolder",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&::SHCoCreateInstance) try_get_SHCoCreateInstance()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHCoCreateInstance))try_get_function(
                        &function_info, "SHCoCreateInstance",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&::SHParseDisplayName) try_get_SHParseDisplayName()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::SHParseDisplayName))try_get_function(
                        &function_info, "SHParseDisplayName",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&::__WSAFDIsSet) try_get___WSAFDIsSet()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::__WSAFDIsSet))try_get_function(
                        &function_info, "__WSAFDIsSet",
                        WinPolyfillModuleId::WinPolyfillModuleIdWs2_32);
            }

            decltype(&::select) try_get_select()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::select))try_get_function(
                        &function_info, "select",
                        WinPolyfillModuleId::WinPolyfillModuleIdWs2_32);
            }

            decltype(&::WSASetLastError) try_get_WSASetLastError()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&::WSASetLastError))try_get_function(
                        &function_info, "WSASetLastError",
                        WinPolyfillModuleId::WinPolyfillModuleIdWs2_32);
            }

            decltype(&YY::Thunks::wp_CoGetApartmentType) try_get_CoGetApartmentType()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CoGetApartmentType))try_get_function(
                        &function_info, "CoGetApartmentType",
                        WinPolyfillModuleId::WinPolyfillModuleIdOle32);
            }

            decltype(&YY::Thunks::wp_GetDateFormatEx) try_get_GetDateFormatEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetDateFormatEx))try_get_function(
                        &function_info, "GetDateFormatEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetTimeFormatEx) try_get_GetTimeFormatEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetTimeFormatEx))try_get_function(
                        &function_info, "GetTimeFormatEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_RaiseFailFastException) try_get_RaiseFailFastException()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RaiseFailFastException))try_get_function(
                        &function_info, "RaiseFailFastException",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetThreadErrorMode) try_get_SetThreadErrorMode()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetThreadErrorMode))try_get_function(
                        &function_info, "SetThreadErrorMode",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetThreadErrorMode) try_get_GetThreadErrorMode()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetThreadErrorMode))try_get_function(
                        &function_info, "GetThreadErrorMode",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetErrorMode) try_get_GetErrorMode()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetErrorMode))try_get_function(
                        &function_info, "GetErrorMode",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_FlsAlloc) try_get_FlsAlloc()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_FlsAlloc))try_get_function(
                        &function_info, "FlsAlloc",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_FlsGetValue) try_get_FlsGetValue()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_FlsGetValue))try_get_function(
                        &function_info, "FlsGetValue",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_FlsSetValue) try_get_FlsSetValue()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_FlsSetValue))try_get_function(
                        &function_info, "FlsSetValue",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_FlsFree) try_get_FlsFree()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_FlsFree))try_get_function(
                        &function_info, "FlsFree",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_IsThreadAFiber) try_get_IsThreadAFiber()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_IsThreadAFiber))try_get_function(
                        &function_info, "IsThreadAFiber",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_ConvertThreadToFiberEx) try_get_ConvertThreadToFiberEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_ConvertThreadToFiberEx))try_get_function(
                        &function_info, "ConvertThreadToFiberEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetFileInformationByHandleEx) try_get_GetFileInformationByHandleEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetFileInformationByHandleEx))try_get_function(
                        &function_info, "GetFileInformationByHandleEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetFileInformationByHandle) try_get_SetFileInformationByHandle()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetFileInformationByHandle))try_get_function(
                        &function_info, "SetFileInformationByHandle",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetFinalPathNameByHandleW) try_get_GetFinalPathNameByHandleW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetFinalPathNameByHandleW))try_get_function(
                        &function_info, "GetFinalPathNameByHandleW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetFinalPathNameByHandleA) try_get_GetFinalPathNameByHandleA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetFinalPathNameByHandleA))try_get_function(
                        &function_info, "GetFinalPathNameByHandleA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateFile2) try_get_CreateFile2()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateFile2))try_get_function(
                        &function_info, "CreateFile2",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_OpenFileById) try_get_OpenFileById()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_OpenFileById))try_get_function(
                        &function_info, "OpenFileById",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateSymbolicLinkW) try_get_CreateSymbolicLinkW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateSymbolicLinkW))try_get_function(
                        &function_info, "CreateSymbolicLinkW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateSymbolicLinkA) try_get_CreateSymbolicLinkA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateSymbolicLinkA))try_get_function(
                        &function_info, "CreateSymbolicLinkA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_ReOpenFile) try_get_ReOpenFile()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_ReOpenFile))try_get_function(
                        &function_info, "ReOpenFile",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetFilePointerEx) try_get_SetFilePointerEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetFilePointerEx))try_get_function(
                        &function_info, "SetFilePointerEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_FindFirstFileExW) try_get_FindFirstFileExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_FindFirstFileExW))try_get_function(
                        &function_info, "FindFirstFileExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_FindFirstFileExA) try_get_FindFirstFileExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_FindFirstFileExA))try_get_function(
                        &function_info, "FindFirstFileExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InterlockedCompareExchange64) try_get_InterlockedCompareExchange64()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InterlockedCompareExchange64))try_get_function(
                        &function_info, "InterlockedCompareExchange64",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InitializeSListHead) try_get_InitializeSListHead()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InitializeSListHead))try_get_function(
                        &function_info, "InitializeSListHead",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InterlockedFlushSList) try_get_InterlockedFlushSList()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InterlockedFlushSList))try_get_function(
                        &function_info, "InterlockedFlushSList",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_QueryDepthSList) try_get_QueryDepthSList()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_QueryDepthSList))try_get_function(
                        &function_info, "QueryDepthSList",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InterlockedPushEntrySList) try_get_InterlockedPushEntrySList()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InterlockedPushEntrySList))try_get_function(
                        &function_info, "InterlockedPushEntrySList",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InterlockedPopEntrySList) try_get_InterlockedPopEntrySList()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InterlockedPopEntrySList))try_get_function(
                        &function_info, "InterlockedPopEntrySList",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CancelIoEx) try_get_CancelIoEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CancelIoEx))try_get_function(
                        &function_info, "CancelIoEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CancelSynchronousIo) try_get_CancelSynchronousIo()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CancelSynchronousIo))try_get_function(
                        &function_info, "CancelSynchronousIo",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetQueuedCompletionStatusEx) try_get_GetQueuedCompletionStatusEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetQueuedCompletionStatusEx))try_get_function(
                        &function_info, "GetQueuedCompletionStatusEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_PowerCreateRequest) try_get_PowerCreateRequest()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PowerCreateRequest))try_get_function(
                        &function_info, "PowerCreateRequest",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_PowerSetRequest) try_get_PowerSetRequest()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PowerSetRequest))try_get_function(
                        &function_info, "PowerSetRequest",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_PowerClearRequest) try_get_PowerClearRequest()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PowerClearRequest))try_get_function(
                        &function_info, "PowerClearRequest",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetFileCompletionNotificationModes) try_get_SetFileCompletionNotificationModes()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetFileCompletionNotificationModes))try_get_function(
                        &function_info, "SetFileCompletionNotificationModes",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetModuleHandleExA) try_get_GetModuleHandleExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetModuleHandleExA))try_get_function(
                        &function_info, "GetModuleHandleExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetModuleHandleExW) try_get_GetModuleHandleExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetModuleHandleExW))try_get_function(
                        &function_info, "GetModuleHandleExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_LoadLibraryExW) try_get_LoadLibraryExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_LoadLibraryExW))try_get_function(
                        &function_info, "LoadLibraryExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_LoadLibraryExA) try_get_LoadLibraryExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_LoadLibraryExA))try_get_function(
                        &function_info, "LoadLibraryExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_EnumResourceLanguagesExW) try_get_EnumResourceLanguagesExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_EnumResourceLanguagesExW))try_get_function(
                        &function_info, "EnumResourceLanguagesExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_EnumResourceLanguagesExA) try_get_EnumResourceLanguagesExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_EnumResourceLanguagesExA))try_get_function(
                        &function_info, "EnumResourceLanguagesExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_LocaleNameToLCID) try_get_LocaleNameToLCID()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_LocaleNameToLCID))try_get_function(
                        &function_info, "LocaleNameToLCID",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_LCIDToLocaleName) try_get_LCIDToLocaleName()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_LCIDToLocaleName))try_get_function(
                        &function_info, "LCIDToLocaleName",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetLocaleInfoEx) try_get_GetLocaleInfoEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetLocaleInfoEx))try_get_function(
                        &function_info, "GetLocaleInfoEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumberFormatEx) try_get_GetNumberFormatEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumberFormatEx))try_get_function(
                        &function_info, "GetNumberFormatEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetCurrencyFormatEx) try_get_GetCurrencyFormatEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetCurrencyFormatEx))try_get_function(
                        &function_info, "GetCurrencyFormatEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetUserDefaultLocaleName) try_get_GetUserDefaultLocaleName()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetUserDefaultLocaleName))try_get_function(
                        &function_info, "GetUserDefaultLocaleName",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetSystemDefaultLocaleName) try_get_GetSystemDefaultLocaleName()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetSystemDefaultLocaleName))try_get_function(
                        &function_info, "GetSystemDefaultLocaleName",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_EnumCalendarInfoExEx) try_get_EnumCalendarInfoExEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_EnumCalendarInfoExEx))try_get_function(
                        &function_info, "EnumCalendarInfoExEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_EnumDateFormatsExEx) try_get_EnumDateFormatsExEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_EnumDateFormatsExEx))try_get_function(
                        &function_info, "EnumDateFormatsExEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_LCMapStringEx) try_get_LCMapStringEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_LCMapStringEx))try_get_function(
                        &function_info, "LCMapStringEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_EnumSystemLocalesEx) try_get_EnumSystemLocalesEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_EnumSystemLocalesEx))try_get_function(
                        &function_info, "EnumSystemLocalesEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetThreadPreferredUILanguages) try_get_GetThreadPreferredUILanguages()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetThreadPreferredUILanguages))try_get_function(
                        &function_info, "GetThreadPreferredUILanguages",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetThreadUILanguage) try_get_GetThreadUILanguage()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetThreadUILanguage))try_get_function(
                        &function_info, "GetThreadUILanguage",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_ResolveLocaleName) try_get_ResolveLocaleName()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_ResolveLocaleName))try_get_function(
                        &function_info, "ResolveLocaleName",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetMemoryErrorHandlingCapabilities) try_get_GetMemoryErrorHandlingCapabilities()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetMemoryErrorHandlingCapabilities))try_get_function(
                        &function_info, "GetMemoryErrorHandlingCapabilities",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_AllocateUserPhysicalPagesNuma) try_get_AllocateUserPhysicalPagesNuma()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_AllocateUserPhysicalPagesNuma))try_get_function(
                        &function_info, "AllocateUserPhysicalPagesNuma",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_VirtualAllocFromApp) try_get_VirtualAllocFromApp()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_VirtualAllocFromApp))try_get_function(
                        &function_info, "VirtualAllocFromApp",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_VirtualAllocExNuma) try_get_VirtualAllocExNuma()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_VirtualAllocExNuma))try_get_function(
                        &function_info, "VirtualAllocExNuma",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_VirtualAlloc2) try_get_VirtualAlloc2()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_VirtualAlloc2))try_get_function(
                        &function_info, "VirtualAlloc2",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_VirtualAlloc2FromApp) try_get_VirtualAlloc2FromApp()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_VirtualAlloc2FromApp))try_get_function(
                        &function_info, "VirtualAlloc2FromApp",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateFileMappingNumaW) try_get_CreateFileMappingNumaW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateFileMappingNumaW))try_get_function(
                        &function_info, "CreateFileMappingNumaW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateFileMappingNumaA) try_get_CreateFileMappingNumaA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateFileMappingNumaA))try_get_function(
                        &function_info, "CreateFileMappingNumaA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateFileMappingFromApp) try_get_CreateFileMappingFromApp()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateFileMappingFromApp))try_get_function(
                        &function_info, "CreateFileMappingFromApp",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateFileMapping2) try_get_CreateFileMapping2()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateFileMapping2))try_get_function(
                        &function_info, "CreateFileMapping2",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_MapViewOfFileFromApp) try_get_MapViewOfFileFromApp()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_MapViewOfFileFromApp))try_get_function(
                        &function_info, "MapViewOfFileFromApp",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_UnmapViewOfFileEx) try_get_UnmapViewOfFileEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_UnmapViewOfFileEx))try_get_function(
                        &function_info, "UnmapViewOfFileEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_VirtualProtectFromApp) try_get_VirtualProtectFromApp()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_VirtualProtectFromApp))try_get_function(
                        &function_info, "VirtualProtectFromApp",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_OpenFileMappingFromApp) try_get_OpenFileMappingFromApp()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_OpenFileMappingFromApp))try_get_function(
                        &function_info, "OpenFileMappingFromApp",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetLargePageMinimum) try_get_GetLargePageMinimum()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetLargePageMinimum))try_get_function(
                        &function_info, "GetLargePageMinimum",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_DiscardVirtualMemory) try_get_DiscardVirtualMemory()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_DiscardVirtualMemory))try_get_function(
                        &function_info, "DiscardVirtualMemory",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_OfferVirtualMemory) try_get_OfferVirtualMemory()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_OfferVirtualMemory))try_get_function(
                        &function_info, "OfferVirtualMemory",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_ReclaimVirtualMemory) try_get_ReclaimVirtualMemory()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_ReclaimVirtualMemory))try_get_function(
                        &function_info, "ReclaimVirtualMemory",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_PrefetchVirtualMemory) try_get_PrefetchVirtualMemory()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PrefetchVirtualMemory))try_get_function(
                        &function_info, "PrefetchVirtualMemory",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_PathIsUNCEx) try_get_PathIsUNCEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathIsUNCEx))try_get_function(
                        &function_info, "PathIsUNCEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchIsRoot) try_get_PathCchIsRoot()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchIsRoot))try_get_function(
                        &function_info, "PathCchIsRoot",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchAddBackslashEx) try_get_PathCchAddBackslashEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchAddBackslashEx))try_get_function(
                        &function_info, "PathCchAddBackslashEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchAddBackslash) try_get_PathCchAddBackslash()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchAddBackslash))try_get_function(
                        &function_info, "PathCchAddBackslash",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchRemoveBackslashEx) try_get_PathCchRemoveBackslashEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchRemoveBackslashEx))try_get_function(
                        &function_info, "PathCchRemoveBackslashEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchRemoveBackslash) try_get_PathCchRemoveBackslash()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchRemoveBackslash))try_get_function(
                        &function_info, "PathCchRemoveBackslash",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchSkipRoot) try_get_PathCchSkipRoot()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchSkipRoot))try_get_function(
                        &function_info, "PathCchSkipRoot",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchStripToRoot) try_get_PathCchStripToRoot()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchStripToRoot))try_get_function(
                        &function_info, "PathCchStripToRoot",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchRemoveFileSpec) try_get_PathCchRemoveFileSpec()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchRemoveFileSpec))try_get_function(
                        &function_info, "PathCchRemoveFileSpec",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchFindExtension) try_get_PathCchFindExtension()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchFindExtension))try_get_function(
                        &function_info, "PathCchFindExtension",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchAddExtension) try_get_PathCchAddExtension()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchAddExtension))try_get_function(
                        &function_info, "PathCchAddExtension",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchRenameExtension) try_get_PathCchRenameExtension()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchRenameExtension))try_get_function(
                        &function_info, "PathCchRenameExtension",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchRemoveExtension) try_get_PathCchRemoveExtension()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchRemoveExtension))try_get_function(
                        &function_info, "PathCchRemoveExtension",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchCanonicalizeEx) try_get_PathCchCanonicalizeEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchCanonicalizeEx))try_get_function(
                        &function_info, "PathCchCanonicalizeEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchCanonicalize) try_get_PathCchCanonicalize()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchCanonicalize))try_get_function(
                        &function_info, "PathCchCanonicalize",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchCombineEx) try_get_PathCchCombineEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchCombineEx))try_get_function(
                        &function_info, "PathCchCombineEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchCombine) try_get_PathCchCombine()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchCombine))try_get_function(
                        &function_info, "PathCchCombine",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchAppendEx) try_get_PathCchAppendEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchAppendEx))try_get_function(
                        &function_info, "PathCchAppendEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchAppend) try_get_PathCchAppend()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchAppend))try_get_function(
                        &function_info, "PathCchAppend",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathCchStripPrefix) try_get_PathCchStripPrefix()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathCchStripPrefix))try_get_function(
                        &function_info, "PathCchStripPrefix",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathAllocCombine) try_get_PathAllocCombine()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathAllocCombine))try_get_function(
                        &function_info, "PathAllocCombine",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_PathAllocCanonicalize) try_get_PathAllocCanonicalize()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PathAllocCanonicalize))try_get_function(
                        &function_info, "PathAllocCanonicalize",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_path_l1_1_0);
            }

            decltype(&YY::Thunks::wp_GetCurrentProcessorNumber) try_get_GetCurrentProcessorNumber()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetCurrentProcessorNumber))try_get_function(
                        &function_info, "GetCurrentProcessorNumber",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetCurrentProcessorNumberEx) try_get_GetCurrentProcessorNumberEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetCurrentProcessorNumberEx))try_get_function(
                        &function_info, "GetCurrentProcessorNumberEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetThreadId) try_get_GetThreadId()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetThreadId))try_get_function(
                        &function_info, "GetThreadId",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetProcessIdOfThread) try_get_GetProcessIdOfThread()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetProcessIdOfThread))try_get_function(
                        &function_info, "GetProcessIdOfThread",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetProcessId) try_get_GetProcessId()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetProcessId))try_get_function(
                        &function_info, "GetProcessId",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_FlushProcessWriteBuffers) try_get_FlushProcessWriteBuffers()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_FlushProcessWriteBuffers))try_get_function(
                        &function_info, "FlushProcessWriteBuffers",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InitializeProcThreadAttributeList) try_get_InitializeProcThreadAttributeList()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InitializeProcThreadAttributeList))try_get_function(
                        &function_info, "InitializeProcThreadAttributeList",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_DeleteProcThreadAttributeList) try_get_DeleteProcThreadAttributeList()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_DeleteProcThreadAttributeList))try_get_function(
                        &function_info, "DeleteProcThreadAttributeList",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_UpdateProcThreadAttribute) try_get_UpdateProcThreadAttribute()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_UpdateProcThreadAttribute))try_get_function(
                        &function_info, "UpdateProcThreadAttribute",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetThreadStackGuarantee) try_get_SetThreadStackGuarantee()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetThreadStackGuarantee))try_get_function(
                        &function_info, "SetThreadStackGuarantee",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetProcessMitigationPolicy) try_get_GetProcessMitigationPolicy()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetProcessMitigationPolicy))try_get_function(
                        &function_info, "GetProcessMitigationPolicy",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetProcessMitigationPolicy) try_get_SetProcessMitigationPolicy()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetProcessMitigationPolicy))try_get_function(
                        &function_info, "SetProcessMitigationPolicy",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetProcessInformation) try_get_SetProcessInformation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetProcessInformation))try_get_function(
                        &function_info, "SetProcessInformation",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetThreadInformation) try_get_SetThreadInformation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetThreadInformation))try_get_function(
                        &function_info, "SetThreadInformation",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetThreadInformation) try_get_GetThreadInformation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetThreadInformation))try_get_function(
                        &function_info, "GetThreadInformation",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetMaximumProcessorCount) try_get_GetMaximumProcessorCount()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetMaximumProcessorCount))try_get_function(
                        &function_info, "GetMaximumProcessorCount",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetActiveProcessorCount) try_get_GetActiveProcessorCount()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetActiveProcessorCount))try_get_function(
                        &function_info, "GetActiveProcessorCount",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetActiveProcessorGroupCount) try_get_GetActiveProcessorGroupCount()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetActiveProcessorGroupCount))try_get_function(
                        &function_info, "GetActiveProcessorGroupCount",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetMaximumProcessorGroupCount) try_get_GetMaximumProcessorGroupCount()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetMaximumProcessorGroupCount))try_get_function(
                        &function_info, "GetMaximumProcessorGroupCount",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_QueryFullProcessImageNameW) try_get_QueryFullProcessImageNameW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_QueryFullProcessImageNameW))try_get_function(
                        &function_info, "QueryFullProcessImageNameW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_QueryFullProcessImageNameA) try_get_QueryFullProcessImageNameA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_QueryFullProcessImageNameA))try_get_function(
                        &function_info, "QueryFullProcessImageNameA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_QueryThreadCycleTime) try_get_QueryThreadCycleTime()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_QueryThreadCycleTime))try_get_function(
                        &function_info, "QueryThreadCycleTime",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_QueryProcessCycleTime) try_get_QueryProcessCycleTime()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_QueryProcessCycleTime))try_get_function(
                        &function_info, "QueryProcessCycleTime",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_RegDeleteKeyExW) try_get_RegDeleteKeyExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegDeleteKeyExW))try_get_function(
                        &function_info, "RegDeleteKeyExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegDeleteKeyExA) try_get_RegDeleteKeyExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegDeleteKeyExA))try_get_function(
                        &function_info, "RegDeleteKeyExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegSetKeyValueW) try_get_RegSetKeyValueW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegSetKeyValueW))try_get_function(
                        &function_info, "RegSetKeyValueW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegSetKeyValueA) try_get_RegSetKeyValueA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegSetKeyValueA))try_get_function(
                        &function_info, "RegSetKeyValueA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegDeleteKeyValueW) try_get_RegDeleteKeyValueW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegDeleteKeyValueW))try_get_function(
                        &function_info, "RegDeleteKeyValueW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegDeleteKeyValueA) try_get_RegDeleteKeyValueA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegDeleteKeyValueA))try_get_function(
                        &function_info, "RegDeleteKeyValueA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegDeleteTreeW) try_get_RegDeleteTreeW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegDeleteTreeW))try_get_function(
                        &function_info, "RegDeleteTreeW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegDeleteTreeA) try_get_RegDeleteTreeA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegDeleteTreeA))try_get_function(
                        &function_info, "RegDeleteTreeA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegGetValueW) try_get_RegGetValueW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegGetValueW))try_get_function(
                        &function_info, "RegGetValueW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegGetValueA) try_get_RegGetValueA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegGetValueA))try_get_function(
                        &function_info, "RegGetValueA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegCopyTreeW) try_get_RegCopyTreeW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegCopyTreeW))try_get_function(
                        &function_info, "RegCopyTreeW",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RegCopyTreeA) try_get_RegCopyTreeA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegCopyTreeA))try_get_function(
                        &function_info, "RegCopyTreeA",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_RtlCaptureStackBackTrace) try_get_RtlCaptureStackBackTrace()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RtlCaptureStackBackTrace))try_get_function(
                        &function_info, "RtlCaptureStackBackTrace",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&YY::Thunks::wp_CompareStringEx) try_get_CompareStringEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CompareStringEx))try_get_function(
                        &function_info, "CompareStringEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CompareStringOrdinal) try_get_CompareStringOrdinal()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CompareStringOrdinal))try_get_function(
                        &function_info, "CompareStringOrdinal",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CompareStringA) try_get_CompareStringA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CompareStringA))try_get_function(
                        &function_info, "CompareStringA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CompareStringW) try_get_CompareStringW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CompareStringW))try_get_function(
                        &function_info, "CompareStringW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InitializeCriticalSectionEx) try_get_InitializeCriticalSectionEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InitializeCriticalSectionEx))try_get_function(
                        &function_info, "InitializeCriticalSectionEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InitOnceInitialize) try_get_InitOnceInitialize()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InitOnceInitialize))try_get_function(
                        &function_info, "InitOnceInitialize",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InitOnceBeginInitialize) try_get_InitOnceBeginInitialize()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InitOnceBeginInitialize))try_get_function(
                        &function_info, "InitOnceBeginInitialize",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InitOnceComplete) try_get_InitOnceComplete()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InitOnceComplete))try_get_function(
                        &function_info, "InitOnceComplete",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InitOnceExecuteOnce) try_get_InitOnceExecuteOnce()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InitOnceExecuteOnce))try_get_function(
                        &function_info, "InitOnceExecuteOnce",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateEventExW) try_get_CreateEventExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateEventExW))try_get_function(
                        &function_info, "CreateEventExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateEventExA) try_get_CreateEventExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateEventExA))try_get_function(
                        &function_info, "CreateEventExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateMutexExW) try_get_CreateMutexExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateMutexExW))try_get_function(
                        &function_info, "CreateMutexExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateMutexExA) try_get_CreateMutexExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateMutexExA))try_get_function(
                        &function_info, "CreateMutexExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateSemaphoreExW) try_get_CreateSemaphoreExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateSemaphoreExW))try_get_function(
                        &function_info, "CreateSemaphoreExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateWaitableTimerExW) try_get_CreateWaitableTimerExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateWaitableTimerExW))try_get_function(
                        &function_info, "CreateWaitableTimerExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InitializeSRWLock) try_get_InitializeSRWLock()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InitializeSRWLock))try_get_function(
                        &function_info, "InitializeSRWLock",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_AcquireSRWLockExclusive) try_get_AcquireSRWLockExclusive()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_AcquireSRWLockExclusive))try_get_function(
                        &function_info, "AcquireSRWLockExclusive",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_TryAcquireSRWLockExclusive) try_get_TryAcquireSRWLockExclusive()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_TryAcquireSRWLockExclusive))try_get_function(
                        &function_info, "TryAcquireSRWLockExclusive",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_ReleaseSRWLockExclusive) try_get_ReleaseSRWLockExclusive()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_ReleaseSRWLockExclusive))try_get_function(
                        &function_info, "ReleaseSRWLockExclusive",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_AcquireSRWLockShared) try_get_AcquireSRWLockShared()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_AcquireSRWLockShared))try_get_function(
                        &function_info, "AcquireSRWLockShared",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_TryAcquireSRWLockShared) try_get_TryAcquireSRWLockShared()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_TryAcquireSRWLockShared))try_get_function(
                        &function_info, "TryAcquireSRWLockShared",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_ReleaseSRWLockShared) try_get_ReleaseSRWLockShared()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_ReleaseSRWLockShared))try_get_function(
                        &function_info, "ReleaseSRWLockShared",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InitializeConditionVariable) try_get_InitializeConditionVariable()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InitializeConditionVariable))try_get_function(
                        &function_info, "InitializeConditionVariable",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SleepConditionVariableCS) try_get_SleepConditionVariableCS()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SleepConditionVariableCS))try_get_function(
                        &function_info, "SleepConditionVariableCS",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SleepConditionVariableSRW) try_get_SleepConditionVariableSRW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SleepConditionVariableSRW))try_get_function(
                        &function_info, "SleepConditionVariableSRW",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_WakeConditionVariable) try_get_WakeConditionVariable()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WakeConditionVariable))try_get_function(
                        &function_info, "WakeConditionVariable",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_WakeAllConditionVariable) try_get_WakeAllConditionVariable()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WakeAllConditionVariable))try_get_function(
                        &function_info, "WakeAllConditionVariable",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_InitializeSynchronizationBarrier) try_get_InitializeSynchronizationBarrier()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InitializeSynchronizationBarrier))try_get_function(
                        &function_info, "InitializeSynchronizationBarrier",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_EnterSynchronizationBarrier) try_get_EnterSynchronizationBarrier()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_EnterSynchronizationBarrier))try_get_function(
                        &function_info, "EnterSynchronizationBarrier",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_DeleteSynchronizationBarrier) try_get_DeleteSynchronizationBarrier()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_DeleteSynchronizationBarrier))try_get_function(
                        &function_info, "DeleteSynchronizationBarrier",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_WaitOnAddress) try_get_WaitOnAddress()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WaitOnAddress))try_get_function(
                        &function_info, "WaitOnAddress",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_synch_l1_2_0);
            }

            decltype(&YY::Thunks::wp_WakeByAddressSingle) try_get_WakeByAddressSingle()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WakeByAddressSingle))try_get_function(
                        &function_info, "WakeByAddressSingle",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_synch_l1_2_0);
            }

            decltype(&YY::Thunks::wp_WakeByAddressAll) try_get_WakeByAddressAll()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WakeByAddressAll))try_get_function(
                        &function_info, "WakeByAddressAll",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_synch_l1_2_0);
            }

            decltype(&YY::Thunks::wp_SetWaitableTimerEx) try_get_SetWaitableTimerEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetWaitableTimerEx))try_get_function(
                        &function_info, "SetWaitableTimerEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetTickCount64) try_get_GetTickCount64()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetTickCount64))try_get_function(
                        &function_info, "GetTickCount64",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetSystemTimePreciseAsFileTime) try_get_GetSystemTimePreciseAsFileTime()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetSystemTimePreciseAsFileTime))try_get_function(
                        &function_info, "GetSystemTimePreciseAsFileTime",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetLogicalProcessorInformation) try_get_GetLogicalProcessorInformation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetLogicalProcessorInformation))try_get_function(
                        &function_info, "GetLogicalProcessorInformation",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetLogicalProcessorInformationEx) try_get_GetLogicalProcessorInformationEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetLogicalProcessorInformationEx))try_get_function(
                        &function_info, "GetLogicalProcessorInformationEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNativeSystemInfo) try_get_GetNativeSystemInfo()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNativeSystemInfo))try_get_function(
                        &function_info, "GetNativeSystemInfo",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetProductInfo) try_get_GetProductInfo()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetProductInfo))try_get_function(
                        &function_info, "GetProductInfo",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumaNodeProcessorMask) try_get_GetNumaNodeProcessorMask()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumaNodeProcessorMask))try_get_function(
                        &function_info, "GetNumaNodeProcessorMask",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumaNodeProcessorMaskEx) try_get_GetNumaNodeProcessorMaskEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumaNodeProcessorMaskEx))try_get_function(
                        &function_info, "GetNumaNodeProcessorMaskEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetThreadGroupAffinity) try_get_GetThreadGroupAffinity()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetThreadGroupAffinity))try_get_function(
                        &function_info, "GetThreadGroupAffinity",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetThreadGroupAffinity) try_get_SetThreadGroupAffinity()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetThreadGroupAffinity))try_get_function(
                        &function_info, "SetThreadGroupAffinity",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumaHighestNodeNumber) try_get_GetNumaHighestNodeNumber()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumaHighestNodeNumber))try_get_function(
                        &function_info, "GetNumaHighestNodeNumber",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumaProximityNodeEx) try_get_GetNumaProximityNodeEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumaProximityNodeEx))try_get_function(
                        &function_info, "GetNumaProximityNodeEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateThreadpoolWork) try_get_CreateThreadpoolWork()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateThreadpoolWork))try_get_function(
                        &function_info, "CreateThreadpoolWork",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CloseThreadpoolWork) try_get_CloseThreadpoolWork()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CloseThreadpoolWork))try_get_function(
                        &function_info, "CloseThreadpoolWork",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SubmitThreadpoolWork) try_get_SubmitThreadpoolWork()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SubmitThreadpoolWork))try_get_function(
                        &function_info, "SubmitThreadpoolWork",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_WaitForThreadpoolWorkCallbacks) try_get_WaitForThreadpoolWorkCallbacks()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WaitForThreadpoolWorkCallbacks))try_get_function(
                        &function_info, "WaitForThreadpoolWorkCallbacks",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateThreadpoolTimer) try_get_CreateThreadpoolTimer()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateThreadpoolTimer))try_get_function(
                        &function_info, "CreateThreadpoolTimer",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetThreadpoolTimer) try_get_SetThreadpoolTimer()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetThreadpoolTimer))try_get_function(
                        &function_info, "SetThreadpoolTimer",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_WaitForThreadpoolTimerCallbacks) try_get_WaitForThreadpoolTimerCallbacks()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WaitForThreadpoolTimerCallbacks))try_get_function(
                        &function_info, "WaitForThreadpoolTimerCallbacks",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CloseThreadpoolTimer) try_get_CloseThreadpoolTimer()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CloseThreadpoolTimer))try_get_function(
                        &function_info, "CloseThreadpoolTimer",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetEventWhenCallbackReturns) try_get_SetEventWhenCallbackReturns()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetEventWhenCallbackReturns))try_get_function(
                        &function_info, "SetEventWhenCallbackReturns",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_ReleaseSemaphoreWhenCallbackReturns) try_get_ReleaseSemaphoreWhenCallbackReturns()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_ReleaseSemaphoreWhenCallbackReturns))try_get_function(
                        &function_info, "ReleaseSemaphoreWhenCallbackReturns",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_ReleaseMutexWhenCallbackReturns) try_get_ReleaseMutexWhenCallbackReturns()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_ReleaseMutexWhenCallbackReturns))try_get_function(
                        &function_info, "ReleaseMutexWhenCallbackReturns",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_LeaveCriticalSectionWhenCallbackReturns) try_get_LeaveCriticalSectionWhenCallbackReturns()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_LeaveCriticalSectionWhenCallbackReturns))try_get_function(
                        &function_info, "LeaveCriticalSectionWhenCallbackReturns",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_FreeLibraryWhenCallbackReturns) try_get_FreeLibraryWhenCallbackReturns()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_FreeLibraryWhenCallbackReturns))try_get_function(
                        &function_info, "FreeLibraryWhenCallbackReturns",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_TrySubmitThreadpoolCallback) try_get_TrySubmitThreadpoolCallback()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_TrySubmitThreadpoolCallback))try_get_function(
                        &function_info, "TrySubmitThreadpoolCallback",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CreateThreadpoolWait) try_get_CreateThreadpoolWait()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateThreadpoolWait))try_get_function(
                        &function_info, "CreateThreadpoolWait",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_CloseThreadpoolWait) try_get_CloseThreadpoolWait()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CloseThreadpoolWait))try_get_function(
                        &function_info, "CloseThreadpoolWait",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetThreadpoolWait) try_get_SetThreadpoolWait()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetThreadpoolWait))try_get_function(
                        &function_info, "SetThreadpoolWait",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_WaitForThreadpoolWaitCallbacks) try_get_WaitForThreadpoolWaitCallbacks()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WaitForThreadpoolWaitCallbacks))try_get_function(
                        &function_info, "WaitForThreadpoolWaitCallbacks",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetDynamicTimeZoneInformation) try_get_GetDynamicTimeZoneInformation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetDynamicTimeZoneInformation))try_get_function(
                        &function_info, "GetDynamicTimeZoneInformation",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_SetDynamicTimeZoneInformation) try_get_SetDynamicTimeZoneInformation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetDynamicTimeZoneInformation))try_get_function(
                        &function_info, "SetDynamicTimeZoneInformation",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_TzSpecificLocalTimeToSystemTimeEx) try_get_TzSpecificLocalTimeToSystemTimeEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_TzSpecificLocalTimeToSystemTimeEx))try_get_function(
                        &function_info, "TzSpecificLocalTimeToSystemTimeEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_TzSpecificLocalTimeToSystemTime) try_get_TzSpecificLocalTimeToSystemTime()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_TzSpecificLocalTimeToSystemTime))try_get_function(
                        &function_info, "TzSpecificLocalTimeToSystemTime",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_DecodePointer) try_get_DecodePointer()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_DecodePointer))try_get_function(
                        &function_info, "DecodePointer",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_EncodePointer) try_get_EncodePointer()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_EncodePointer))try_get_function(
                        &function_info, "EncodePointer",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetFileVersionInfoExW) try_get_GetFileVersionInfoExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetFileVersionInfoExW))try_get_function(
                        &function_info, "GetFileVersionInfoExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdVersion);
            }

            decltype(&YY::Thunks::wp_GetFileVersionInfoExA) try_get_GetFileVersionInfoExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetFileVersionInfoExA))try_get_function(
                        &function_info, "GetFileVersionInfoExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdVersion);
            }

            decltype(&YY::Thunks::wp_GetFileVersionInfoSizeExW) try_get_GetFileVersionInfoSizeExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetFileVersionInfoSizeExW))try_get_function(
                        &function_info, "GetFileVersionInfoSizeExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdVersion);
            }

            decltype(&YY::Thunks::wp_GetFileVersionInfoSizeExA) try_get_GetFileVersionInfoSizeExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetFileVersionInfoSizeExA))try_get_function(
                        &function_info, "GetFileVersionInfoSizeExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdVersion);
            }

            decltype(&YY::Thunks::wp_RoOriginateError) try_get_RoOriginateError()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoOriginateError))try_get_function(
                        &function_info, "RoOriginateError",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_error_l1_1_0);
            }

            decltype(&YY::Thunks::wp_RoOriginateErrorW) try_get_RoOriginateErrorW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoOriginateErrorW))try_get_function(
                        &function_info, "RoOriginateErrorW",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_error_l1_1_0);
            }

            decltype(&YY::Thunks::wp_WindowsCreateString) try_get_WindowsCreateString()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WindowsCreateString))try_get_function(
                        &function_info, "WindowsCreateString",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_string_l1_1_0);
            }

            decltype(&YY::Thunks::wp_WindowsCreateStringReference) try_get_WindowsCreateStringReference()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WindowsCreateStringReference))try_get_function(
                        &function_info, "WindowsCreateStringReference",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_string_l1_1_0);
            }

            decltype(&YY::Thunks::wp_WindowsDeleteString) try_get_WindowsDeleteString()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WindowsDeleteString))try_get_function(
                        &function_info, "WindowsDeleteString",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_string_l1_1_0);
            }

            decltype(&YY::Thunks::wp_WindowsDuplicateString) try_get_WindowsDuplicateString()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WindowsDuplicateString))try_get_function(
                        &function_info, "WindowsDuplicateString",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_string_l1_1_0);
            }

            decltype(&YY::Thunks::wp_WindowsGetStringLen) try_get_WindowsGetStringLen()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WindowsGetStringLen))try_get_function(
                        &function_info, "WindowsGetStringLen",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_string_l1_1_0);
            }

            decltype(&YY::Thunks::wp_WindowsGetStringRawBuffer) try_get_WindowsGetStringRawBuffer()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WindowsGetStringRawBuffer))try_get_function(
                        &function_info, "WindowsGetStringRawBuffer",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_string_l1_1_0);
            }

            decltype(&YY::Thunks::wp_WindowsIsStringEmpty) try_get_WindowsIsStringEmpty()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WindowsIsStringEmpty))try_get_function(
                        &function_info, "WindowsIsStringEmpty",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_string_l1_1_0);
            }

            decltype(&YY::Thunks::wp_WindowsStringHasEmbeddedNull) try_get_WindowsStringHasEmbeddedNull()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WindowsStringHasEmbeddedNull))try_get_function(
                        &function_info, "WindowsStringHasEmbeddedNull",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_string_l1_1_0);
            }

            decltype(&YY::Thunks::wp_WindowsCompareStringOrdinal) try_get_WindowsCompareStringOrdinal()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WindowsCompareStringOrdinal))try_get_function(
                        &function_info, "WindowsCompareStringOrdinal",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_string_l1_1_0);
            }

            decltype(&YY::Thunks::wp_RoInitialize) try_get_RoInitialize()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoInitialize))try_get_function(
                        &function_info, "RoInitialize",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_l1_1_0);
            }

            decltype(&YY::Thunks::wp_RoUninitialize) try_get_RoUninitialize()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoUninitialize))try_get_function(
                        &function_info, "RoUninitialize",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_l1_1_0);
            }

            decltype(&YY::Thunks::wp_RoActivateInstance) try_get_RoActivateInstance()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoActivateInstance))try_get_function(
                        &function_info, "RoActivateInstance",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_l1_1_0);
            }

            decltype(&YY::Thunks::wp_RoRegisterActivationFactories) try_get_RoRegisterActivationFactories()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoRegisterActivationFactories))try_get_function(
                        &function_info, "RoRegisterActivationFactories",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_l1_1_0);
            }

            decltype(&YY::Thunks::wp_RoRevokeActivationFactories) try_get_RoRevokeActivationFactories()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoRevokeActivationFactories))try_get_function(
                        &function_info, "RoRevokeActivationFactories",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_l1_1_0);
            }

            decltype(&YY::Thunks::wp_RoGetActivationFactory) try_get_RoGetActivationFactory()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoGetActivationFactory))try_get_function(
                        &function_info, "RoGetActivationFactory",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_l1_1_0);
            }

            decltype(&YY::Thunks::wp_RoRegisterForApartmentShutdown) try_get_RoRegisterForApartmentShutdown()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoRegisterForApartmentShutdown))try_get_function(
                        &function_info, "RoRegisterForApartmentShutdown",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_l1_1_0);
            }

            decltype(&YY::Thunks::wp_RoUnregisterForApartmentShutdown) try_get_RoUnregisterForApartmentShutdown()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoUnregisterForApartmentShutdown))try_get_function(
                        &function_info, "RoUnregisterForApartmentShutdown",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_l1_1_0);
            }

            decltype(&YY::Thunks::wp_RoGetApartmentIdentifier) try_get_RoGetApartmentIdentifier()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RoGetApartmentIdentifier))try_get_function(
                        &function_info, "RoGetApartmentIdentifier",
                        WinPolyfillModuleId::WinPolyfillModuleIdApi_ms_win_core_winrt_l1_1_0);
            }

            decltype(&YY::Thunks::wp_Wow64DisableWow64FsRedirection) try_get_Wow64DisableWow64FsRedirection()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_Wow64DisableWow64FsRedirection))try_get_function(
                        &function_info, "Wow64DisableWow64FsRedirection",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_Wow64RevertWow64FsRedirection) try_get_Wow64RevertWow64FsRedirection()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_Wow64RevertWow64FsRedirection))try_get_function(
                        &function_info, "Wow64RevertWow64FsRedirection",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_Wow64EnableWow64FsRedirection) try_get_Wow64EnableWow64FsRedirection()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_Wow64EnableWow64FsRedirection))try_get_function(
                        &function_info, "Wow64EnableWow64FsRedirection",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_IsWow64Process) try_get_IsWow64Process()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_IsWow64Process))try_get_function(
                        &function_info, "IsWow64Process",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_IsWow64Process2) try_get_IsWow64Process2()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_IsWow64Process2))try_get_function(
                        &function_info, "IsWow64Process2",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_IsWow64GuestMachineSupported) try_get_IsWow64GuestMachineSupported()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_IsWow64GuestMachineSupported))try_get_function(
                        &function_info, "IsWow64GuestMachineSupported",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_EventSetInformation) try_get_EventSetInformation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_EventSetInformation))try_get_function(
                        &function_info, "EventSetInformation",
                        WinPolyfillModuleId::WinPolyfillModuleIdAdvapi32);
            }

            decltype(&YY::Thunks::wp_PowerDeterminePlatformRoleEx) try_get_PowerDeterminePlatformRoleEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PowerDeterminePlatformRoleEx))try_get_function(
                        &function_info, "PowerDeterminePlatformRoleEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdPowrprof);
            }

            decltype(&YY::Thunks::wp_PowerRegisterSuspendResumeNotification) try_get_PowerRegisterSuspendResumeNotification()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PowerRegisterSuspendResumeNotification))try_get_function(
                        &function_info, "PowerRegisterSuspendResumeNotification",
                        WinPolyfillModuleId::WinPolyfillModuleIdPowrprof);
            }

            decltype(&YY::Thunks::wp_PowerUnregisterSuspendResumeNotification) try_get_PowerUnregisterSuspendResumeNotification()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PowerUnregisterSuspendResumeNotification))try_get_function(
                        &function_info, "PowerUnregisterSuspendResumeNotification",
                        WinPolyfillModuleId::WinPolyfillModuleIdPowrprof);
            }

            decltype(&YY::Thunks::wp_BCryptOpenAlgorithmProvider) try_get_BCryptOpenAlgorithmProvider()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BCryptOpenAlgorithmProvider))try_get_function(
                        &function_info, "BCryptOpenAlgorithmProvider",
                        WinPolyfillModuleId::WinPolyfillModuleIdBcrypt);
            }

            decltype(&YY::Thunks::wp_BCryptCloseAlgorithmProvider) try_get_BCryptCloseAlgorithmProvider()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BCryptCloseAlgorithmProvider))try_get_function(
                        &function_info, "BCryptCloseAlgorithmProvider",
                        WinPolyfillModuleId::WinPolyfillModuleIdBcrypt);
            }

            decltype(&YY::Thunks::wp_BCryptGenRandom) try_get_BCryptGenRandom()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BCryptGenRandom))try_get_function(
                        &function_info, "BCryptGenRandom",
                        WinPolyfillModuleId::WinPolyfillModuleIdBcrypt);
            }

            decltype(&YY::Thunks::wp_BluetoothGATTGetCharacteristicValue) try_get_BluetoothGATTGetCharacteristicValue()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BluetoothGATTGetCharacteristicValue))try_get_function(
                        &function_info, "BluetoothGATTGetCharacteristicValue",
                        WinPolyfillModuleId::WinPolyfillModuleIdBluetoothapis);
            }

            decltype(&YY::Thunks::wp_BluetoothGATTGetCharacteristics) try_get_BluetoothGATTGetCharacteristics()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BluetoothGATTGetCharacteristics))try_get_function(
                        &function_info, "BluetoothGATTGetCharacteristics",
                        WinPolyfillModuleId::WinPolyfillModuleIdBluetoothapis);
            }

            decltype(&YY::Thunks::wp_BluetoothGATTGetDescriptors) try_get_BluetoothGATTGetDescriptors()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BluetoothGATTGetDescriptors))try_get_function(
                        &function_info, "BluetoothGATTGetDescriptors",
                        WinPolyfillModuleId::WinPolyfillModuleIdBluetoothapis);
            }

            decltype(&YY::Thunks::wp_BluetoothGATTGetServices) try_get_BluetoothGATTGetServices()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BluetoothGATTGetServices))try_get_function(
                        &function_info, "BluetoothGATTGetServices",
                        WinPolyfillModuleId::WinPolyfillModuleIdBluetoothapis);
            }

            decltype(&YY::Thunks::wp_BluetoothGATTRegisterEvent) try_get_BluetoothGATTRegisterEvent()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BluetoothGATTRegisterEvent))try_get_function(
                        &function_info, "BluetoothGATTRegisterEvent",
                        WinPolyfillModuleId::WinPolyfillModuleIdBluetoothapis);
            }

            decltype(&YY::Thunks::wp_BluetoothGATTSetCharacteristicValue) try_get_BluetoothGATTSetCharacteristicValue()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BluetoothGATTSetCharacteristicValue))try_get_function(
                        &function_info, "BluetoothGATTSetCharacteristicValue",
                        WinPolyfillModuleId::WinPolyfillModuleIdBluetoothapis);
            }

            decltype(&YY::Thunks::wp_BluetoothGATTSetDescriptorValue) try_get_BluetoothGATTSetDescriptorValue()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BluetoothGATTSetDescriptorValue))try_get_function(
                        &function_info, "BluetoothGATTSetDescriptorValue",
                        WinPolyfillModuleId::WinPolyfillModuleIdBluetoothapis);
            }

            decltype(&YY::Thunks::wp_BluetoothGATTUnregisterEvent) try_get_BluetoothGATTUnregisterEvent()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_BluetoothGATTUnregisterEvent))try_get_function(
                        &function_info, "BluetoothGATTUnregisterEvent",
                        WinPolyfillModuleId::WinPolyfillModuleIdBluetoothapis);
            }

            decltype(&YY::Thunks::wp_DwmEnableBlurBehindWindow) try_get_DwmEnableBlurBehindWindow()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_DwmEnableBlurBehindWindow))try_get_function(
                        &function_info, "DwmEnableBlurBehindWindow",
                        WinPolyfillModuleId::WinPolyfillModuleIdDwmapi);
            }

            decltype(&YY::Thunks::wp_RegisterSuspendResumeNotification) try_get_RegisterSuspendResumeNotification()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegisterSuspendResumeNotification))try_get_function(
                        &function_info, "RegisterSuspendResumeNotification",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_UnregisterSuspendResumeNotification) try_get_UnregisterSuspendResumeNotification()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_UnregisterSuspendResumeNotification))try_get_function(
                        &function_info, "UnregisterSuspendResumeNotification",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_SetCoalescableTimer) try_get_SetCoalescableTimer()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetCoalescableTimer))try_get_function(
                        &function_info, "SetCoalescableTimer",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_GetIfTable2) try_get_GetIfTable2()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetIfTable2))try_get_function(
                        &function_info, "GetIfTable2",
                        WinPolyfillModuleId::WinPolyfillModuleIdIphlpapi);
            }

            decltype(&YY::Thunks::wp_GetIfTable2Ex) try_get_GetIfTable2Ex()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetIfTable2Ex))try_get_function(
                        &function_info, "GetIfTable2Ex",
                        WinPolyfillModuleId::WinPolyfillModuleIdIphlpapi);
            }

            decltype(&YY::Thunks::wp_GetIfEntry2) try_get_GetIfEntry2()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetIfEntry2))try_get_function(
                        &function_info, "GetIfEntry2",
                        WinPolyfillModuleId::WinPolyfillModuleIdIphlpapi);
            }

            decltype(&YY::Thunks::wp_GetIfEntry2Ex) try_get_GetIfEntry2Ex()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetIfEntry2Ex))try_get_function(
                        &function_info, "GetIfEntry2Ex",
                        WinPolyfillModuleId::WinPolyfillModuleIdIphlpapi);
            }

            decltype(&YY::Thunks::wp_FreeMibTable) try_get_FreeMibTable()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_FreeMibTable))try_get_function(
                        &function_info, "FreeMibTable",
                        WinPolyfillModuleId::WinPolyfillModuleIdIphlpapi);
            }

            decltype(&YY::Thunks::wp_WTSGetActiveConsoleSessionId) try_get_WTSGetActiveConsoleSessionId()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WTSGetActiveConsoleSessionId))try_get_function(
                        &function_info, "WTSGetActiveConsoleSessionId",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumaProcessorNode) try_get_GetNumaProcessorNode()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumaProcessorNode))try_get_function(
                        &function_info, "GetNumaProcessorNode",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumaNodeNumberFromHandle) try_get_GetNumaNodeNumberFromHandle()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumaNodeNumberFromHandle))try_get_function(
                        &function_info, "GetNumaNodeNumberFromHandle",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumaProcessorNodeEx) try_get_GetNumaProcessorNodeEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumaProcessorNodeEx))try_get_function(
                        &function_info, "GetNumaProcessorNodeEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumaAvailableMemoryNode) try_get_GetNumaAvailableMemoryNode()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumaAvailableMemoryNode))try_get_function(
                        &function_info, "GetNumaAvailableMemoryNode",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumaAvailableMemoryNodeEx) try_get_GetNumaAvailableMemoryNodeEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumaAvailableMemoryNodeEx))try_get_function(
                        &function_info, "GetNumaAvailableMemoryNodeEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetNumaProximityNode) try_get_GetNumaProximityNode()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetNumaProximityNode))try_get_function(
                        &function_info, "GetNumaProximityNode",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_MapViewOfFileExNuma) try_get_MapViewOfFileExNuma()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_MapViewOfFileExNuma))try_get_function(
                        &function_info, "MapViewOfFileExNuma",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_GetFirmwareType) try_get_GetFirmwareType()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetFirmwareType))try_get_function(
                        &function_info, "GetFirmwareType",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_IsNativeVhdBoot) try_get_IsNativeVhdBoot()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_IsNativeVhdBoot))try_get_function(
                        &function_info, "IsNativeVhdBoot",
                        WinPolyfillModuleId::WinPolyfillModuleIdKernel32);
            }

            decltype(&YY::Thunks::wp_MFCreateDXGIDeviceManager) try_get_MFCreateDXGIDeviceManager()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_MFCreateDXGIDeviceManager))try_get_function(
                        &function_info, "MFCreateDXGIDeviceManager",
                        WinPolyfillModuleId::WinPolyfillModuleIdMfplat);
            }

            decltype(&YY::Thunks::wp_MFCreateDXGISurfaceBuffer) try_get_MFCreateDXGISurfaceBuffer()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_MFCreateDXGISurfaceBuffer))try_get_function(
                        &function_info, "MFCreateDXGISurfaceBuffer",
                        WinPolyfillModuleId::WinPolyfillModuleIdMfplat);
            }

            decltype(&YY::Thunks::wp_MFLockDXGIDeviceManager) try_get_MFLockDXGIDeviceManager()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_MFLockDXGIDeviceManager))try_get_function(
                        &function_info, "MFLockDXGIDeviceManager",
                        WinPolyfillModuleId::WinPolyfillModuleIdMfplat);
            }

            decltype(&YY::Thunks::wp_MFUnlockDXGIDeviceManager) try_get_MFUnlockDXGIDeviceManager()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_MFUnlockDXGIDeviceManager))try_get_function(
                        &function_info, "MFUnlockDXGIDeviceManager",
                        WinPolyfillModuleId::WinPolyfillModuleIdMfplat);
            }

            decltype(&YY::Thunks::wp_NetGetAadJoinInformation) try_get_NetGetAadJoinInformation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_NetGetAadJoinInformation))try_get_function(
                        &function_info, "NetGetAadJoinInformation",
                        WinPolyfillModuleId::WinPolyfillModuleIdNetapi32);
            }

            decltype(&YY::Thunks::wp_NetFreeAadJoinInformation) try_get_NetFreeAadJoinInformation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_NetFreeAadJoinInformation))try_get_function(
                        &function_info, "NetFreeAadJoinInformation",
                        WinPolyfillModuleId::WinPolyfillModuleIdNetapi32);
            }

            decltype(&YY::Thunks::wp_NtCancelIoFileEx) try_get_NtCancelIoFileEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_NtCancelIoFileEx))try_get_function(
                        &function_info, "NtCancelIoFileEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdNtdll);
            }

            decltype(&YY::Thunks::wp_PdhAddEnglishCounterW) try_get_PdhAddEnglishCounterW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PdhAddEnglishCounterW))try_get_function(
                        &function_info, "PdhAddEnglishCounterW",
                        WinPolyfillModuleId::WinPolyfillModuleIdPdh);
            }

            decltype(&YY::Thunks::wp_PdhAddEnglishCounterA) try_get_PdhAddEnglishCounterA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PdhAddEnglishCounterA))try_get_function(
                        &function_info, "PdhAddEnglishCounterA",
                        WinPolyfillModuleId::WinPolyfillModuleIdPdh);
            }

            decltype(&YY::Thunks::wp_PowerDeterminePlatformRole) try_get_PowerDeterminePlatformRole()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_PowerDeterminePlatformRole))try_get_function(
                        &function_info, "PowerDeterminePlatformRole",
                        WinPolyfillModuleId::WinPolyfillModuleIdPowrprof);
            }

            decltype(&YY::Thunks::wp_EnumProcessModulesEx) try_get_EnumProcessModulesEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_EnumProcessModulesEx))try_get_function(
                        &function_info, "EnumProcessModulesEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdPsapi);
            }

            decltype(&YY::Thunks::wp_GetWsChangesEx) try_get_GetWsChangesEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetWsChangesEx))try_get_function(
                        &function_info, "GetWsChangesEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdPsapi);
            }

            decltype(&YY::Thunks::wp_QueryWorkingSetEx) try_get_QueryWorkingSetEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_QueryWorkingSetEx))try_get_function(
                        &function_info, "QueryWorkingSetEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdPsapi);
            }

            decltype(&YY::Thunks::wp_SetupDiGetDevicePropertyW) try_get_SetupDiGetDevicePropertyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetupDiGetDevicePropertyW))try_get_function(
                        &function_info, "SetupDiGetDevicePropertyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdSetupapi);
            }

            decltype(&YY::Thunks::wp_SetupDiSetDevicePropertyW) try_get_SetupDiSetDevicePropertyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetupDiSetDevicePropertyW))try_get_function(
                        &function_info, "SetupDiSetDevicePropertyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdSetupapi);
            }

            decltype(&YY::Thunks::wp_SetupDiGetClassPropertyW) try_get_SetupDiGetClassPropertyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetupDiGetClassPropertyW))try_get_function(
                        &function_info, "SetupDiGetClassPropertyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdSetupapi);
            }

            decltype(&YY::Thunks::wp_SetupDiGetClassPropertyExW) try_get_SetupDiGetClassPropertyExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetupDiGetClassPropertyExW))try_get_function(
                        &function_info, "SetupDiGetClassPropertyExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdSetupapi);
            }

            decltype(&YY::Thunks::wp_SetupDiSetClassPropertyW) try_get_SetupDiSetClassPropertyW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetupDiSetClassPropertyW))try_get_function(
                        &function_info, "SetupDiSetClassPropertyW",
                        WinPolyfillModuleId::WinPolyfillModuleIdSetupapi);
            }

            decltype(&YY::Thunks::wp_SetupDiSetClassPropertyExW) try_get_SetupDiSetClassPropertyExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetupDiSetClassPropertyExW))try_get_function(
                        &function_info, "SetupDiSetClassPropertyExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdSetupapi);
            }

            decltype(&YY::Thunks::wp_GetDpiForMonitor) try_get_GetDpiForMonitor()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetDpiForMonitor))try_get_function(
                        &function_info, "GetDpiForMonitor",
                        WinPolyfillModuleId::WinPolyfillModuleIdShcore);
            }

            decltype(&YY::Thunks::wp_SetProcessDpiAwareness) try_get_SetProcessDpiAwareness()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetProcessDpiAwareness))try_get_function(
                        &function_info, "SetProcessDpiAwareness",
                        WinPolyfillModuleId::WinPolyfillModuleIdShcore);
            }

            decltype(&YY::Thunks::wp_SHGetKnownFolderPath) try_get_SHGetKnownFolderPath()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHGetKnownFolderPath))try_get_function(
                        &function_info, "SHGetKnownFolderPath",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHSetKnownFolderPath) try_get_SHSetKnownFolderPath()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHSetKnownFolderPath))try_get_function(
                        &function_info, "SHSetKnownFolderPath",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHGetKnownFolderIDList) try_get_SHGetKnownFolderIDList()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHGetKnownFolderIDList))try_get_function(
                        &function_info, "SHGetKnownFolderIDList",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHBindToFolderIDListParent) try_get_SHBindToFolderIDListParent()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHBindToFolderIDListParent))try_get_function(
                        &function_info, "SHBindToFolderIDListParent",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHBindToFolderIDListParentEx) try_get_SHBindToFolderIDListParentEx()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHBindToFolderIDListParentEx))try_get_function(
                        &function_info, "SHBindToFolderIDListParentEx",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHBindToObject) try_get_SHBindToObject()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHBindToObject))try_get_function(
                        &function_info, "SHBindToObject",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHCreateItemFromIDList) try_get_SHCreateItemFromIDList()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHCreateItemFromIDList))try_get_function(
                        &function_info, "SHCreateItemFromIDList",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHCreateItemWithParent) try_get_SHCreateItemWithParent()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHCreateItemWithParent))try_get_function(
                        &function_info, "SHCreateItemWithParent",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHCreateItemFromRelativeName) try_get_SHCreateItemFromRelativeName()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHCreateItemFromRelativeName))try_get_function(
                        &function_info, "SHCreateItemFromRelativeName",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHGetNameFromIDList) try_get_SHGetNameFromIDList()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHGetNameFromIDList))try_get_function(
                        &function_info, "SHGetNameFromIDList",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHCreateShellItem) try_get_SHCreateShellItem()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHCreateShellItem))try_get_function(
                        &function_info, "SHCreateShellItem",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_SHCreateItemFromParsingName) try_get_SHCreateItemFromParsingName()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SHCreateItemFromParsingName))try_get_function(
                        &function_info, "SHCreateItemFromParsingName",
                        WinPolyfillModuleId::WinPolyfillModuleIdShell32);
            }

            decltype(&YY::Thunks::wp_StrToInt64ExA) try_get_StrToInt64ExA()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_StrToInt64ExA))try_get_function(
                        &function_info, "StrToInt64ExA",
                        WinPolyfillModuleId::WinPolyfillModuleIdShlwapi);
            }

            decltype(&YY::Thunks::wp_StrToInt64ExW) try_get_StrToInt64ExW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_StrToInt64ExW))try_get_function(
                        &function_info, "StrToInt64ExW",
                        WinPolyfillModuleId::WinPolyfillModuleIdShlwapi);
            }

            decltype(&YY::Thunks::wp_IsWow64Message) try_get_IsWow64Message()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_IsWow64Message))try_get_function(
                        &function_info, "IsWow64Message",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_IsProcessDPIAware) try_get_IsProcessDPIAware()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_IsProcessDPIAware))try_get_function(
                        &function_info, "IsProcessDPIAware",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_SetProcessDPIAware) try_get_SetProcessDPIAware()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetProcessDPIAware))try_get_function(
                        &function_info, "SetProcessDPIAware",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_SetProcessDpiAwarenessContext) try_get_SetProcessDpiAwarenessContext()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetProcessDpiAwarenessContext))try_get_function(
                        &function_info, "SetProcessDpiAwarenessContext",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_GetDpiForSystem) try_get_GetDpiForSystem()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetDpiForSystem))try_get_function(
                        &function_info, "GetDpiForSystem",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_GetDpiForWindow) try_get_GetDpiForWindow()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetDpiForWindow))try_get_function(
                        &function_info, "GetDpiForWindow",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_GetSystemMetricsForDpi) try_get_GetSystemMetricsForDpi()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetSystemMetricsForDpi))try_get_function(
                        &function_info, "GetSystemMetricsForDpi",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_AdjustWindowRectExForDpi) try_get_AdjustWindowRectExForDpi()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_AdjustWindowRectExForDpi))try_get_function(
                        &function_info, "AdjustWindowRectExForDpi",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_SystemParametersInfoForDpi) try_get_SystemParametersInfoForDpi()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SystemParametersInfoForDpi))try_get_function(
                        &function_info, "SystemParametersInfoForDpi",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_GetWindowDisplayAffinity) try_get_GetWindowDisplayAffinity()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetWindowDisplayAffinity))try_get_function(
                        &function_info, "GetWindowDisplayAffinity",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_SetWindowDisplayAffinity) try_get_SetWindowDisplayAffinity()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_SetWindowDisplayAffinity))try_get_function(
                        &function_info, "SetWindowDisplayAffinity",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_RegisterTouchWindow) try_get_RegisterTouchWindow()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_RegisterTouchWindow))try_get_function(
                        &function_info, "RegisterTouchWindow",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_UnregisterTouchWindow) try_get_UnregisterTouchWindow()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_UnregisterTouchWindow))try_get_function(
                        &function_info, "UnregisterTouchWindow",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_IsTouchWindow) try_get_IsTouchWindow()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_IsTouchWindow))try_get_function(
                        &function_info, "IsTouchWindow",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_GetTouchInputInfo) try_get_GetTouchInputInfo()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetTouchInputInfo))try_get_function(
                        &function_info, "GetTouchInputInfo",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_CloseTouchInputHandle) try_get_CloseTouchInputHandle()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CloseTouchInputHandle))try_get_function(
                        &function_info, "CloseTouchInputHandle",
                        WinPolyfillModuleId::WinPolyfillModuleIdUser32);
            }

            decltype(&YY::Thunks::wp_CreateAppContainerProfile) try_get_CreateAppContainerProfile()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_CreateAppContainerProfile))try_get_function(
                        &function_info, "CreateAppContainerProfile",
                        WinPolyfillModuleId::WinPolyfillModuleIdUserenv);
            }

            decltype(&YY::Thunks::wp_DeleteAppContainerProfile) try_get_DeleteAppContainerProfile()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_DeleteAppContainerProfile))try_get_function(
                        &function_info, "DeleteAppContainerProfile",
                        WinPolyfillModuleId::WinPolyfillModuleIdUserenv);
            }

            decltype(&YY::Thunks::wp_DeriveAppContainerSidFromAppContainerName) try_get_DeriveAppContainerSidFromAppContainerName()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_DeriveAppContainerSidFromAppContainerName))try_get_function(
                        &function_info, "DeriveAppContainerSidFromAppContainerName",
                        WinPolyfillModuleId::WinPolyfillModuleIdUserenv);
            }

            decltype(&YY::Thunks::wp_GetAppContainerFolderPath) try_get_GetAppContainerFolderPath()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetAppContainerFolderPath))try_get_function(
                        &function_info, "GetAppContainerFolderPath",
                        WinPolyfillModuleId::WinPolyfillModuleIdUserenv);
            }

            decltype(&YY::Thunks::wp_GetAppContainerRegistryLocation) try_get_GetAppContainerRegistryLocation()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_GetAppContainerRegistryLocation))try_get_function(
                        &function_info, "GetAppContainerRegistryLocation",
                        WinPolyfillModuleId::WinPolyfillModuleIdUserenv);
            }

            decltype(&YY::Thunks::wp_inet_pton) try_get_inet_pton()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_inet_pton))try_get_function(
                        &function_info, "inet_pton",
                        WinPolyfillModuleId::WinPolyfillModuleIdWs2_32);
            }

            decltype(&YY::Thunks::wp_InetPtonW) try_get_InetPtonW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InetPtonW))try_get_function(
                        &function_info, "InetPtonW",
                        WinPolyfillModuleId::WinPolyfillModuleIdWs2_32);
            }

            decltype(&YY::Thunks::wp_inet_ntop) try_get_inet_ntop()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_inet_ntop))try_get_function(
                        &function_info, "inet_ntop",
                        WinPolyfillModuleId::WinPolyfillModuleIdWs2_32);
            }

            decltype(&YY::Thunks::wp_InetNtopW) try_get_InetNtopW()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_InetNtopW))try_get_function(
                        &function_info, "InetNtopW",
                        WinPolyfillModuleId::WinPolyfillModuleIdWs2_32);
            }

            decltype(&YY::Thunks::wp_WSAPoll) try_get_WSAPoll()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&YY::Thunks::wp_WSAPoll))try_get_function(
                        &function_info, "WSAPoll",
                        WinPolyfillModuleId::WinPolyfillModuleIdWs2_32);
            }
        }
    }
}

#define NtCreateFile try_get_NtCreateFile()
#define NtClose try_get_NtClose()
#define NtQueryDirectoryFile try_get_NtQueryDirectoryFile()
#define NtQueryInformationFile try_get_NtQueryInformationFile()
#define NtQuerySystemInformation try_get_NtQuerySystemInformation()
#define NtSetInformationFile try_get_NtSetInformationFile()
#define RtlNtStatusToDosError try_get_RtlNtStatusToDosError()
#define RtlDetermineDosPathNameType_U try_get_RtlDetermineDosPathNameType_U()
#define RtlDosPathNameToNtPathName_U try_get_RtlDosPathNameToNtPathName_U()
#define RtlDosPathNameToNtPathName_U_WithStatus try_get_RtlDosPathNameToNtPathName_U_WithStatus()
#define RtlFreeUnicodeString try_get_RtlFreeUnicodeString()
#define NtQueryObject try_get_NtQueryObject()
#define NtQueryInformationThread try_get_NtQueryInformationThread()
#define NtSetInformationThread try_get_NtSetInformationThread()
#define NtQueryInformationProcess try_get_NtQueryInformationProcess()
#define NtSetInformationProcess try_get_NtSetInformationProcess()
#define NtOpenKeyedEvent try_get_NtOpenKeyedEvent()
#define NtWaitForKeyedEvent try_get_NtWaitForKeyedEvent()
#define NtReleaseKeyedEvent try_get_NtReleaseKeyedEvent()
#define RtlAdjustPrivilege try_get_RtlAdjustPrivilege()
#define RtlPcToFileHeader try_get_RtlPcToFileHeader()
#define LdrAddRefDll try_get_LdrAddRefDll()
#define RtlWow64EnableFsRedirectionEx try_get_RtlWow64EnableFsRedirectionEx()
#define LdrLoadDll try_get_LdrLoadDll()
#define RtlDllShutdownInProgress try_get_RtlDllShutdownInProgress()
#define RtlCutoverTimeToSystemTime try_get_RtlCutoverTimeToSystemTime()
#define NtCancelIoFile try_get_NtCancelIoFile()
#define AddDllDirectory try_get_AddDllDirectory()
#define SystemFunction036 try_get_SystemFunction036()
#define GetDeviceCaps try_get_GetDeviceCaps()
#define GetMessageW try_get_GetMessageW()
#define TranslateMessage try_get_TranslateMessage()
#define DispatchMessageW try_get_DispatchMessageW()
#define SendMessageW try_get_SendMessageW()
#define PostMessageW try_get_PostMessageW()
#define DefWindowProcW try_get_DefWindowProcW()
#define PostQuitMessage try_get_PostQuitMessage()
#define RegisterClassW try_get_RegisterClassW()
#define CreateWindowExW try_get_CreateWindowExW()
#define DestroyWindow try_get_DestroyWindow()
#define SetTimer try_get_SetTimer()
#define GetSystemMetrics try_get_GetSystemMetrics()
#define GetDC try_get_GetDC()
#define ReleaseDC try_get_ReleaseDC()
#define AdjustWindowRectEx try_get_AdjustWindowRectEx()
#define GetWindowLongW try_get_GetWindowLongW()
#define SetWindowLongW try_get_SetWindowLongW()
#define SystemParametersInfoW try_get_SystemParametersInfoW()
#define MonitorFromWindow try_get_MonitorFromWindow()
#define EnumProcessModules try_get_EnumProcessModules()
#define GetModuleFileNameExA try_get_GetModuleFileNameExA()
#define GetModuleFileNameExW try_get_GetModuleFileNameExW()
#define GetWsChanges try_get_GetWsChanges()
#define GetProcessImageFileNameA try_get_GetProcessImageFileNameA()
#define GetProcessImageFileNameW try_get_GetProcessImageFileNameW()
#define RegCloseKey try_get_RegCloseKey()
#define RegCreateKeyExA try_get_RegCreateKeyExA()
#define RegCreateKeyExW try_get_RegCreateKeyExW()
#define RegDeleteKeyA try_get_RegDeleteKeyA()
#define RegDeleteKeyW try_get_RegDeleteKeyW()
#define RegDeleteValueA try_get_RegDeleteValueA()
#define RegDeleteValueW try_get_RegDeleteValueW()
#define RegEnumKeyW try_get_RegEnumKeyW()
#define RegOpenKeyExA try_get_RegOpenKeyExA()
#define RegOpenKeyExW try_get_RegOpenKeyExW()
#define RegQueryValueExA try_get_RegQueryValueExA()
#define RegQueryValueExW try_get_RegQueryValueExW()
#define RegSetValueExA try_get_RegSetValueExA()
#define RegSetValueExW try_get_RegSetValueExW()
#define GetFileVersionInfoSizeA try_get_GetFileVersionInfoSizeA()
#define GetFileVersionInfoSizeW try_get_GetFileVersionInfoSizeW()
#define GetFileVersionInfoA try_get_GetFileVersionInfoA()
#define GetFileVersionInfoW try_get_GetFileVersionInfoW()
#define CoUninitialize try_get_CoUninitialize()
#define CoInitializeEx try_get_CoInitializeEx()
#define CoGetContextToken try_get_CoGetContextToken()
#define CoTaskMemAlloc try_get_CoTaskMemAlloc()
#define CoTaskMemFree try_get_CoTaskMemFree()
#define GetIfEntry try_get_GetIfEntry()
#define GetIfTable try_get_GetIfTable()
#define PdhAddCounterW try_get_PdhAddCounterW()
#define PdhAddCounterA try_get_PdhAddCounterA()
#define SHDeleteKeyA try_get_SHDeleteKeyA()
#define SHDeleteKeyW try_get_SHDeleteKeyW()
#define SHQueryValueExA try_get_SHQueryValueExA()
#define SHQueryValueExW try_get_SHQueryValueExW()
#define SHCopyKeyA try_get_SHCopyKeyA()
#define SHCopyKeyW try_get_SHCopyKeyW()
#define SetupDiGetDeviceRegistryPropertyW try_get_SetupDiGetDeviceRegistryPropertyW()
#define SetupDiGetClassRegistryPropertyW try_get_SetupDiGetClassRegistryPropertyW()
#define SetupDiSetDeviceRegistryPropertyW try_get_SetupDiSetDeviceRegistryPropertyW()
#define SetupDiSetClassRegistryPropertyW try_get_SetupDiSetClassRegistryPropertyW()
#define ILClone try_get_ILClone()
#define ILFree try_get_ILFree()
#define ILFindLastID try_get_ILFindLastID()
#define ILRemoveLastID try_get_ILRemoveLastID()
#define SHGetFolderPathW try_get_SHGetFolderPathW()
#define SHGetFolderLocation try_get_SHGetFolderLocation()
#define SHSetFolderPathW try_get_SHSetFolderPathW()
#define SHGetDesktopFolder try_get_SHGetDesktopFolder()
#define SHCoCreateInstance try_get_SHCoCreateInstance()
#define SHParseDisplayName try_get_SHParseDisplayName()
#define __WSAFDIsSet try_get___WSAFDIsSet()
#define select try_get_select()
#define WSASetLastError try_get_WSASetLastError()

#define CoGetApartmentType wp_CoGetApartmentType
#define GetDateFormatEx wp_GetDateFormatEx
#define GetTimeFormatEx wp_GetTimeFormatEx
#define RaiseFailFastException wp_RaiseFailFastException
#define SetThreadErrorMode wp_SetThreadErrorMode
#define GetThreadErrorMode wp_GetThreadErrorMode
#define GetErrorMode wp_GetErrorMode
#define FlsAlloc wp_FlsAlloc
#define FlsGetValue wp_FlsGetValue
#define FlsSetValue wp_FlsSetValue
#define FlsFree wp_FlsFree
#define IsThreadAFiber wp_IsThreadAFiber
#define ConvertThreadToFiberEx wp_ConvertThreadToFiberEx
#define GetFileInformationByHandleEx wp_GetFileInformationByHandleEx
#define SetFileInformationByHandle wp_SetFileInformationByHandle
#define GetFinalPathNameByHandleW wp_GetFinalPathNameByHandleW
#define GetFinalPathNameByHandleA wp_GetFinalPathNameByHandleA
#define CreateFile2 wp_CreateFile2
#define OpenFileById wp_OpenFileById
#define CreateSymbolicLinkW wp_CreateSymbolicLinkW
#define CreateSymbolicLinkA wp_CreateSymbolicLinkA
#define ReOpenFile wp_ReOpenFile
#define SetFilePointerEx wp_SetFilePointerEx
#define FindFirstFileExW wp_FindFirstFileExW
#define FindFirstFileExA wp_FindFirstFileExA
#define InterlockedCompareExchange64 wp_InterlockedCompareExchange64
#define InitializeSListHead wp_InitializeSListHead
#define InterlockedFlushSList wp_InterlockedFlushSList
#define QueryDepthSList wp_QueryDepthSList
#define InterlockedPushEntrySList wp_InterlockedPushEntrySList
#define InterlockedPopEntrySList wp_InterlockedPopEntrySList
#define CancelIoEx wp_CancelIoEx
#define CancelSynchronousIo wp_CancelSynchronousIo
#define GetQueuedCompletionStatusEx wp_GetQueuedCompletionStatusEx
#define PowerCreateRequest wp_PowerCreateRequest
#define PowerSetRequest wp_PowerSetRequest
#define PowerClearRequest wp_PowerClearRequest
#define SetFileCompletionNotificationModes wp_SetFileCompletionNotificationModes
#define GetModuleHandleExA wp_GetModuleHandleExA
#define GetModuleHandleExW wp_GetModuleHandleExW
#define LoadLibraryExW wp_LoadLibraryExW
#define LoadLibraryExA wp_LoadLibraryExA
#define EnumResourceLanguagesExW wp_EnumResourceLanguagesExW
#define EnumResourceLanguagesExA wp_EnumResourceLanguagesExA
#define LocaleNameToLCID wp_LocaleNameToLCID
#define LCIDToLocaleName wp_LCIDToLocaleName
#define GetLocaleInfoEx wp_GetLocaleInfoEx
#define GetNumberFormatEx wp_GetNumberFormatEx
#define GetCurrencyFormatEx wp_GetCurrencyFormatEx
#define GetUserDefaultLocaleName wp_GetUserDefaultLocaleName
#define GetSystemDefaultLocaleName wp_GetSystemDefaultLocaleName
#define EnumCalendarInfoExEx wp_EnumCalendarInfoExEx
#define EnumDateFormatsExEx wp_EnumDateFormatsExEx
#define LCMapStringEx wp_LCMapStringEx
#define EnumSystemLocalesEx wp_EnumSystemLocalesEx
#define GetThreadPreferredUILanguages wp_GetThreadPreferredUILanguages
#define GetThreadUILanguage wp_GetThreadUILanguage
#define ResolveLocaleName wp_ResolveLocaleName
#define GetMemoryErrorHandlingCapabilities wp_GetMemoryErrorHandlingCapabilities
#define AllocateUserPhysicalPagesNuma wp_AllocateUserPhysicalPagesNuma
#define VirtualAllocFromApp wp_VirtualAllocFromApp
#define VirtualAllocExNuma wp_VirtualAllocExNuma
#define VirtualAlloc2 wp_VirtualAlloc2
#define VirtualAlloc2FromApp wp_VirtualAlloc2FromApp
#define CreateFileMappingNumaW wp_CreateFileMappingNumaW
#define CreateFileMappingNumaA wp_CreateFileMappingNumaA
#define CreateFileMappingFromApp wp_CreateFileMappingFromApp
#define CreateFileMapping2 wp_CreateFileMapping2
#define MapViewOfFileFromApp wp_MapViewOfFileFromApp
#define UnmapViewOfFileEx wp_UnmapViewOfFileEx
#define VirtualProtectFromApp wp_VirtualProtectFromApp
#define OpenFileMappingFromApp wp_OpenFileMappingFromApp
#define GetLargePageMinimum wp_GetLargePageMinimum
#define DiscardVirtualMemory wp_DiscardVirtualMemory
#define OfferVirtualMemory wp_OfferVirtualMemory
#define ReclaimVirtualMemory wp_ReclaimVirtualMemory
#define PrefetchVirtualMemory wp_PrefetchVirtualMemory
#define PathIsUNCEx wp_PathIsUNCEx
#define PathCchIsRoot wp_PathCchIsRoot
#define PathCchAddBackslashEx wp_PathCchAddBackslashEx
#define PathCchAddBackslash wp_PathCchAddBackslash
#define PathCchRemoveBackslashEx wp_PathCchRemoveBackslashEx
#define PathCchRemoveBackslash wp_PathCchRemoveBackslash
#define PathCchSkipRoot wp_PathCchSkipRoot
#define PathCchStripToRoot wp_PathCchStripToRoot
#define PathCchRemoveFileSpec wp_PathCchRemoveFileSpec
#define PathCchFindExtension wp_PathCchFindExtension
#define PathCchAddExtension wp_PathCchAddExtension
#define PathCchRenameExtension wp_PathCchRenameExtension
#define PathCchRemoveExtension wp_PathCchRemoveExtension
#define PathCchCanonicalizeEx wp_PathCchCanonicalizeEx
#define PathCchCanonicalize wp_PathCchCanonicalize
#define PathCchCombineEx wp_PathCchCombineEx
#define PathCchCombine wp_PathCchCombine
#define PathCchAppendEx wp_PathCchAppendEx
#define PathCchAppend wp_PathCchAppend
#define PathCchStripPrefix wp_PathCchStripPrefix
#define PathAllocCombine wp_PathAllocCombine
#define PathAllocCanonicalize wp_PathAllocCanonicalize
#define GetCurrentProcessorNumber wp_GetCurrentProcessorNumber
#define GetCurrentProcessorNumberEx wp_GetCurrentProcessorNumberEx
#define GetThreadId wp_GetThreadId
#define GetProcessIdOfThread wp_GetProcessIdOfThread
#define GetProcessId wp_GetProcessId
#define FlushProcessWriteBuffers wp_FlushProcessWriteBuffers
#define InitializeProcThreadAttributeList wp_InitializeProcThreadAttributeList
#define DeleteProcThreadAttributeList wp_DeleteProcThreadAttributeList
#define UpdateProcThreadAttribute wp_UpdateProcThreadAttribute
#define SetThreadStackGuarantee wp_SetThreadStackGuarantee
#define GetProcessMitigationPolicy wp_GetProcessMitigationPolicy
#define SetProcessMitigationPolicy wp_SetProcessMitigationPolicy
#define SetProcessInformation wp_SetProcessInformation
#define SetThreadInformation wp_SetThreadInformation
#define GetThreadInformation wp_GetThreadInformation
#define GetMaximumProcessorCount wp_GetMaximumProcessorCount
#define GetActiveProcessorCount wp_GetActiveProcessorCount
#define GetActiveProcessorGroupCount wp_GetActiveProcessorGroupCount
#define GetMaximumProcessorGroupCount wp_GetMaximumProcessorGroupCount
#define QueryFullProcessImageNameW wp_QueryFullProcessImageNameW
#define QueryFullProcessImageNameA wp_QueryFullProcessImageNameA
#define QueryThreadCycleTime wp_QueryThreadCycleTime
#define QueryProcessCycleTime wp_QueryProcessCycleTime
#define RegDeleteKeyExW wp_RegDeleteKeyExW
#define RegDeleteKeyExA wp_RegDeleteKeyExA
#define RegSetKeyValueW wp_RegSetKeyValueW
#define RegSetKeyValueA wp_RegSetKeyValueA
#define RegDeleteKeyValueW wp_RegDeleteKeyValueW
#define RegDeleteKeyValueA wp_RegDeleteKeyValueA
#define RegDeleteTreeW wp_RegDeleteTreeW
#define RegDeleteTreeA wp_RegDeleteTreeA
#define RegGetValueW wp_RegGetValueW
#define RegGetValueA wp_RegGetValueA
#define RegCopyTreeW wp_RegCopyTreeW
#define RegCopyTreeA wp_RegCopyTreeA
#define RtlCaptureStackBackTrace wp_RtlCaptureStackBackTrace
#define CompareStringEx wp_CompareStringEx
#define CompareStringOrdinal wp_CompareStringOrdinal
#define CompareStringA wp_CompareStringA
#define CompareStringW wp_CompareStringW
#define InitializeCriticalSectionEx wp_InitializeCriticalSectionEx
#define InitOnceInitialize wp_InitOnceInitialize
#define InitOnceBeginInitialize wp_InitOnceBeginInitialize
#define InitOnceComplete wp_InitOnceComplete
#define InitOnceExecuteOnce wp_InitOnceExecuteOnce
#define CreateEventExW wp_CreateEventExW
#define CreateEventExA wp_CreateEventExA
#define CreateMutexExW wp_CreateMutexExW
#define CreateMutexExA wp_CreateMutexExA
#define CreateSemaphoreExW wp_CreateSemaphoreExW
#define CreateWaitableTimerExW wp_CreateWaitableTimerExW
#define InitializeSRWLock wp_InitializeSRWLock
#define AcquireSRWLockExclusive wp_AcquireSRWLockExclusive
#define TryAcquireSRWLockExclusive wp_TryAcquireSRWLockExclusive
#define ReleaseSRWLockExclusive wp_ReleaseSRWLockExclusive
#define AcquireSRWLockShared wp_AcquireSRWLockShared
#define TryAcquireSRWLockShared wp_TryAcquireSRWLockShared
#define ReleaseSRWLockShared wp_ReleaseSRWLockShared
#define InitializeConditionVariable wp_InitializeConditionVariable
#define SleepConditionVariableCS wp_SleepConditionVariableCS
#define SleepConditionVariableSRW wp_SleepConditionVariableSRW
#define WakeConditionVariable wp_WakeConditionVariable
#define WakeAllConditionVariable wp_WakeAllConditionVariable
#define InitializeSynchronizationBarrier wp_InitializeSynchronizationBarrier
#define EnterSynchronizationBarrier wp_EnterSynchronizationBarrier
#define DeleteSynchronizationBarrier wp_DeleteSynchronizationBarrier
#define WaitOnAddress wp_WaitOnAddress
#define WakeByAddressSingle wp_WakeByAddressSingle
#define WakeByAddressAll wp_WakeByAddressAll
#define SetWaitableTimerEx wp_SetWaitableTimerEx
#define GetTickCount64 wp_GetTickCount64
#define GetSystemTimePreciseAsFileTime wp_GetSystemTimePreciseAsFileTime
#define GetLogicalProcessorInformation wp_GetLogicalProcessorInformation
#define GetLogicalProcessorInformationEx wp_GetLogicalProcessorInformationEx
#define GetNativeSystemInfo wp_GetNativeSystemInfo
#define GetProductInfo wp_GetProductInfo
#define GetNumaNodeProcessorMask wp_GetNumaNodeProcessorMask
#define GetNumaNodeProcessorMaskEx wp_GetNumaNodeProcessorMaskEx
#define GetThreadGroupAffinity wp_GetThreadGroupAffinity
#define SetThreadGroupAffinity wp_SetThreadGroupAffinity
#define GetNumaHighestNodeNumber wp_GetNumaHighestNodeNumber
#define GetNumaProximityNodeEx wp_GetNumaProximityNodeEx
#define CreateThreadpoolWork wp_CreateThreadpoolWork
#define CloseThreadpoolWork wp_CloseThreadpoolWork
#define SubmitThreadpoolWork wp_SubmitThreadpoolWork
#define WaitForThreadpoolWorkCallbacks wp_WaitForThreadpoolWorkCallbacks
#define CreateThreadpoolTimer wp_CreateThreadpoolTimer
#define SetThreadpoolTimer wp_SetThreadpoolTimer
#define WaitForThreadpoolTimerCallbacks wp_WaitForThreadpoolTimerCallbacks
#define CloseThreadpoolTimer wp_CloseThreadpoolTimer
#define SetEventWhenCallbackReturns wp_SetEventWhenCallbackReturns
#define ReleaseSemaphoreWhenCallbackReturns wp_ReleaseSemaphoreWhenCallbackReturns
#define ReleaseMutexWhenCallbackReturns wp_ReleaseMutexWhenCallbackReturns
#define LeaveCriticalSectionWhenCallbackReturns wp_LeaveCriticalSectionWhenCallbackReturns
#define FreeLibraryWhenCallbackReturns wp_FreeLibraryWhenCallbackReturns
#define TrySubmitThreadpoolCallback wp_TrySubmitThreadpoolCallback
#define CreateThreadpoolWait wp_CreateThreadpoolWait
#define CloseThreadpoolWait wp_CloseThreadpoolWait
#define SetThreadpoolWait wp_SetThreadpoolWait
#define WaitForThreadpoolWaitCallbacks wp_WaitForThreadpoolWaitCallbacks
#define GetDynamicTimeZoneInformation wp_GetDynamicTimeZoneInformation
#define SetDynamicTimeZoneInformation wp_SetDynamicTimeZoneInformation
#define TzSpecificLocalTimeToSystemTimeEx wp_TzSpecificLocalTimeToSystemTimeEx
#define TzSpecificLocalTimeToSystemTime wp_TzSpecificLocalTimeToSystemTime
#define DecodePointer wp_DecodePointer
#define EncodePointer wp_EncodePointer
#define GetFileVersionInfoExW wp_GetFileVersionInfoExW
#define GetFileVersionInfoExA wp_GetFileVersionInfoExA
#define GetFileVersionInfoSizeExW wp_GetFileVersionInfoSizeExW
#define GetFileVersionInfoSizeExA wp_GetFileVersionInfoSizeExA
#define RoOriginateError wp_RoOriginateError
#define RoOriginateErrorW wp_RoOriginateErrorW
#define WindowsCreateString wp_WindowsCreateString
#define WindowsCreateStringReference wp_WindowsCreateStringReference
#define WindowsDeleteString wp_WindowsDeleteString
#define WindowsDuplicateString wp_WindowsDuplicateString
#define WindowsGetStringLen wp_WindowsGetStringLen
#define WindowsGetStringRawBuffer wp_WindowsGetStringRawBuffer
#define WindowsIsStringEmpty wp_WindowsIsStringEmpty
#define WindowsStringHasEmbeddedNull wp_WindowsStringHasEmbeddedNull
#define WindowsCompareStringOrdinal wp_WindowsCompareStringOrdinal
#define RoInitialize wp_RoInitialize
#define RoUninitialize wp_RoUninitialize
#define RoActivateInstance wp_RoActivateInstance
#define RoRegisterActivationFactories wp_RoRegisterActivationFactories
#define RoRevokeActivationFactories wp_RoRevokeActivationFactories
#define RoGetActivationFactory wp_RoGetActivationFactory
#define RoRegisterForApartmentShutdown wp_RoRegisterForApartmentShutdown
#define RoUnregisterForApartmentShutdown wp_RoUnregisterForApartmentShutdown
#define RoGetApartmentIdentifier wp_RoGetApartmentIdentifier
#define Wow64DisableWow64FsRedirection wp_Wow64DisableWow64FsRedirection
#define Wow64RevertWow64FsRedirection wp_Wow64RevertWow64FsRedirection
#define Wow64EnableWow64FsRedirection wp_Wow64EnableWow64FsRedirection
#define IsWow64Process wp_IsWow64Process
#define IsWow64Process2 wp_IsWow64Process2
#define IsWow64GuestMachineSupported wp_IsWow64GuestMachineSupported
#define EventSetInformation wp_EventSetInformation
#define PowerDeterminePlatformRoleEx wp_PowerDeterminePlatformRoleEx
#define PowerRegisterSuspendResumeNotification wp_PowerRegisterSuspendResumeNotification
#define PowerUnregisterSuspendResumeNotification wp_PowerUnregisterSuspendResumeNotification
#define BCryptOpenAlgorithmProvider wp_BCryptOpenAlgorithmProvider
#define BCryptCloseAlgorithmProvider wp_BCryptCloseAlgorithmProvider
#define BCryptGenRandom wp_BCryptGenRandom
#define BluetoothGATTGetCharacteristicValue wp_BluetoothGATTGetCharacteristicValue
#define BluetoothGATTGetCharacteristics wp_BluetoothGATTGetCharacteristics
#define BluetoothGATTGetDescriptors wp_BluetoothGATTGetDescriptors
#define BluetoothGATTGetServices wp_BluetoothGATTGetServices
#define BluetoothGATTRegisterEvent wp_BluetoothGATTRegisterEvent
#define BluetoothGATTSetCharacteristicValue wp_BluetoothGATTSetCharacteristicValue
#define BluetoothGATTSetDescriptorValue wp_BluetoothGATTSetDescriptorValue
#define BluetoothGATTUnregisterEvent wp_BluetoothGATTUnregisterEvent
#define DwmEnableBlurBehindWindow wp_DwmEnableBlurBehindWindow
#define RegisterSuspendResumeNotification wp_RegisterSuspendResumeNotification
#define UnregisterSuspendResumeNotification wp_UnregisterSuspendResumeNotification
#define SetCoalescableTimer wp_SetCoalescableTimer
#define GetIfTable2 wp_GetIfTable2
#define GetIfTable2Ex wp_GetIfTable2Ex
#define GetIfEntry2 wp_GetIfEntry2
#define GetIfEntry2Ex wp_GetIfEntry2Ex
#define FreeMibTable wp_FreeMibTable
#define WTSGetActiveConsoleSessionId wp_WTSGetActiveConsoleSessionId
#define GetNumaProcessorNode wp_GetNumaProcessorNode
#define GetNumaNodeNumberFromHandle wp_GetNumaNodeNumberFromHandle
#define GetNumaProcessorNodeEx wp_GetNumaProcessorNodeEx
#define GetNumaAvailableMemoryNode wp_GetNumaAvailableMemoryNode
#define GetNumaAvailableMemoryNodeEx wp_GetNumaAvailableMemoryNodeEx
#define GetNumaProximityNode wp_GetNumaProximityNode
#define MapViewOfFileExNuma wp_MapViewOfFileExNuma
#define GetFirmwareType wp_GetFirmwareType
#define IsNativeVhdBoot wp_IsNativeVhdBoot
#define MFCreateDXGIDeviceManager wp_MFCreateDXGIDeviceManager
#define MFCreateDXGISurfaceBuffer wp_MFCreateDXGISurfaceBuffer
#define MFLockDXGIDeviceManager wp_MFLockDXGIDeviceManager
#define MFUnlockDXGIDeviceManager wp_MFUnlockDXGIDeviceManager
#define NetGetAadJoinInformation wp_NetGetAadJoinInformation
#define NetFreeAadJoinInformation wp_NetFreeAadJoinInformation
#define NtCancelIoFileEx wp_NtCancelIoFileEx
#define PdhAddEnglishCounterW wp_PdhAddEnglishCounterW
#define PdhAddEnglishCounterA wp_PdhAddEnglishCounterA
#define PowerDeterminePlatformRole wp_PowerDeterminePlatformRole
#define EnumProcessModulesEx wp_EnumProcessModulesEx
#define GetWsChangesEx wp_GetWsChangesEx
#define QueryWorkingSetEx wp_QueryWorkingSetEx
#define SetupDiGetDevicePropertyW wp_SetupDiGetDevicePropertyW
#define SetupDiSetDevicePropertyW wp_SetupDiSetDevicePropertyW
#define SetupDiGetClassPropertyW wp_SetupDiGetClassPropertyW
#define SetupDiGetClassPropertyExW wp_SetupDiGetClassPropertyExW
#define SetupDiSetClassPropertyW wp_SetupDiSetClassPropertyW
#define SetupDiSetClassPropertyExW wp_SetupDiSetClassPropertyExW
#define GetDpiForMonitor wp_GetDpiForMonitor
#define SetProcessDpiAwareness wp_SetProcessDpiAwareness
#define SHGetKnownFolderPath wp_SHGetKnownFolderPath
#define SHSetKnownFolderPath wp_SHSetKnownFolderPath
#define SHGetKnownFolderIDList wp_SHGetKnownFolderIDList
#define SHBindToFolderIDListParent wp_SHBindToFolderIDListParent
#define SHBindToFolderIDListParentEx wp_SHBindToFolderIDListParentEx
#define SHBindToObject wp_SHBindToObject
#define SHCreateItemFromIDList wp_SHCreateItemFromIDList
#define SHCreateItemWithParent wp_SHCreateItemWithParent
#define SHCreateItemFromRelativeName wp_SHCreateItemFromRelativeName
#define SHGetNameFromIDList wp_SHGetNameFromIDList
#define SHCreateShellItem wp_SHCreateShellItem
#define SHCreateItemFromParsingName wp_SHCreateItemFromParsingName
#define StrToInt64ExA wp_StrToInt64ExA
#define StrToInt64ExW wp_StrToInt64ExW
#define IsWow64Message wp_IsWow64Message
#define IsProcessDPIAware wp_IsProcessDPIAware
#define SetProcessDPIAware wp_SetProcessDPIAware
#define SetProcessDpiAwarenessContext wp_SetProcessDpiAwarenessContext
#define GetDpiForSystem wp_GetDpiForSystem
#define GetDpiForWindow wp_GetDpiForWindow
#define GetSystemMetricsForDpi wp_GetSystemMetricsForDpi
#define AdjustWindowRectExForDpi wp_AdjustWindowRectExForDpi
#define SystemParametersInfoForDpi wp_SystemParametersInfoForDpi
#define GetWindowDisplayAffinity wp_GetWindowDisplayAffinity
#define SetWindowDisplayAffinity wp_SetWindowDisplayAffinity
#define RegisterTouchWindow wp_RegisterTouchWindow
#define UnregisterTouchWindow wp_UnregisterTouchWindow
#define IsTouchWindow wp_IsTouchWindow
#define GetTouchInputInfo wp_GetTouchInputInfo
#define CloseTouchInputHandle wp_CloseTouchInputHandle
#define CreateAppContainerProfile wp_CreateAppContainerProfile
#define DeleteAppContainerProfile wp_DeleteAppContainerProfile
#define DeriveAppContainerSidFromAppContainerName wp_DeriveAppContainerSidFromAppContainerName
#define GetAppContainerFolderPath wp_GetAppContainerFolderPath
#define GetAppContainerRegistryLocation wp_GetAppContainerRegistryLocation
#define inet_pton wp_inet_pton
#define InetPtonW wp_InetPtonW
#define inet_ntop wp_inet_ntop
#define InetNtopW wp_InetNtopW
#define WSAPoll wp_WSAPoll
