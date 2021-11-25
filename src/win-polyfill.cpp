

#define _WP_APPLY_TO_LATE_BOUND_MODULES(_APPLY)                                                    \
    _APPLY(ntdll, "ntdll", USING_UNSAFE_LOAD)                                                      \
    _APPLY(kernel32, "kernel32", USING_UNSAFE_LOAD)                                                \
    _APPLY(psapi, "psapi", USING_UNSAFE_LOAD)                                                      \
    _APPLY(version, "version", USING_UNSAFE_LOAD)                                                  \
    _APPLY(advapi32, "advapi32", USING_UNSAFE_LOAD)                                                \
    _APPLY(d3d11, "d3d11", USING_UNSAFE_LOAD)                                                      \
    _APPLY(d3d9, "d3d9", USING_UNSAFE_LOAD)                                                        \
    _APPLY(dbghelp, "dbghelp", USING_UNSAFE_LOAD)                                                  \
    _APPLY(dwmapi, "dwmapi", USING_UNSAFE_LOAD)                                                    \
    _APPLY(dwrite, "dwrite", USING_UNSAFE_LOAD)                                                    \
    _APPLY(dxgi, "dxgi", USING_UNSAFE_LOAD)                                                        \
    _APPLY(gdi32, "gdi32", USING_UNSAFE_LOAD)                                                      \
    _APPLY(iphlpapi, "iphlpapi", USING_UNSAFE_LOAD)                                                \
    _APPLY(ncrypt, "ncrypt", USING_UNSAFE_LOAD)                                                    \
    _APPLY(user32, "user32", USING_UNSAFE_LOAD)                                                    \
    _APPLY(uxtheme, "uxtheme", USING_UNSAFE_LOAD)                                                  \
    _APPLY(ws2_32, "ws2_32", USING_UNSAFE_LOAD)                                                    \
    _APPLY(shell32, "shell32", USING_UNSAFE_LOAD)                                                  \
    _APPLY(shcore, "shcore", USING_UNSAFE_LOAD)                                                    \
    _APPLY(shlwapi, "shlwapi", USING_UNSAFE_LOAD)                                                  \
    _APPLY(setupapi, "setupapi", USING_UNSAFE_LOAD)                                                \
    _APPLY(api_ms_win_core_winrt_l1_1_0, "api-ms-win-core-winrt-l1-1-0", 0)                        \
    _APPLY(api_ms_win_core_winrt_string_l1_1_0, "api-ms-win-core-winrt-string-l1-1-0", 0)          \
    _APPLY(api_ms_win_core_winrt_error_l1_1_0, "api-ms-win-core-winrt-error-l1-1-0", 0)            \
    _APPLY(api_ms_win_core_path_l1_1_0, "api-ms-win-core-path-l1-1-0", 0)                          \
    _APPLY(api_ms_win_core_synch_l1_2_0, "api-ms-win-core-synch-l1-2-0", 0)

#include "win-polyfill.h"

/* Basic function getter */
#define __wp_expand_function(_MODULE, _FUNCTION, _SIZE)                                            \
    EXTERN_C decltype(_FUNCTION) *_CRT_CONCATENATE(                                                \
        wp_get_,                                                                                   \
        _FUNCTION)() noexcept WP_GET_FUNCTION_APPLY(_MODULE, _FUNCTION, decltype(_FUNCTION) *)

#include "polyfill/basic.hpp"

#undef __wp_expand_function

#if (WP_SUPPORT_VERSION < NTDDI_WS03SP1)
#pragma comment(lib, "Advapi32.lib")
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
#pragma comment(lib, "Shlwapi.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "version.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "shell32.lib")
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN7)
#pragma comment(lib, "psapi.lib")
#endif

namespace internal {
// 代码块，分割任务
template <class Callback, typename... Params>
auto __forceinline Block(Callback &&_Callback, Params &&...args) -> decltype(_Callback(args...))
{
    return _Callback(args...);
}

static DWORD __fastcall NtStatusToDosError(_In_ NTSTATUS Status)
{
    if (STATUS_TIMEOUT == Status)
    {
        /*
        https://github.com/Chuyu-Team/win-polyfill/issues/10

        用户报告，Windows XP 无法转换 STATUS_TIMEOUT。实际结果也是rubin，因此，特殊处理一下。
        */
        return ERROR_TIMEOUT;
    }
    else if (auto pRtlNtStatusToDosError = wp_get_RtlNtStatusToDosError())
    {
        return pRtlNtStatusToDosError(Status);
    }
    else
    {
        // 如果没有RtlNtStatusToDosError就直接设置Status代码吧，反正至少比没有错误代码强
        return Status;
    }
}

static DWORD __fastcall BaseSetLastNTError(_In_ NTSTATUS Status)
{
    auto lStatus = NtStatusToDosError(Status);
    SetLastError(lStatus);
    return lStatus;
}

static __analysis_noreturn void __fastcall RaiseStatus(NTSTATUS Status)
{
    RaiseException(Status, EXCEPTION_NONCONTINUABLE, 0, NULL);
}

static LARGE_INTEGER *__fastcall BaseFormatTimeOut(LARGE_INTEGER *Timeout, DWORD dwMilliseconds)
{
    if (dwMilliseconds == INFINITE)
        return nullptr;

    Timeout->QuadPart = -10000ll * dwMilliseconds;

    return Timeout;
}

static LSTATUS __fastcall Basep8BitStringToStaticUnicodeString(UNICODE_STRING *pDst, LPCSTR Src)
{
    const UINT CodePage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;

    auto cchDst = MultiByteToWideChar(
        CodePage,
        MB_ERR_INVALID_CHARS,
        Src,
        -1,
        pDst->Buffer,
        pDst->MaximumLength / sizeof(wchar_t));
    if (cchDst == 0)
    {
        return GetLastError();
    }

    pDst->Length = cchDst * sizeof(wchar_t);

    return ERROR_SUCCESS;
}

static BOOL __fastcall BasepGetVolumeGUIDFromNTName(
    const UNICODE_STRING *NtName,
    wchar_t szVolumeGUID[MAX_PATH])
{
#define __szVolumeMountPointPrefix__ L"\\\\?\\GLOBALROOT"

    // 一个设备名称 512 长度够多了吧？
    wchar_t szVolumeMountPoint[512];

    // 检查缓冲区是否充足
    auto cbBufferNeed = sizeof(__szVolumeMountPointPrefix__) + NtName->Length;

    if (cbBufferNeed > sizeof(szVolumeMountPoint))
    {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return FALSE;
    }

    memcpy(
        szVolumeMountPoint,
        __szVolumeMountPointPrefix__,
        sizeof(__szVolumeMountPointPrefix__) - sizeof(__szVolumeMountPointPrefix__[0]));
    memcpy(
        (char *)szVolumeMountPoint + sizeof(__szVolumeMountPointPrefix__) -
            sizeof(__szVolumeMountPointPrefix__[0]),
        NtName->Buffer,
        NtName->Length);

    szVolumeMountPoint[cbBufferNeed / 2 - 1] = L'\0';

    return GetVolumeNameForVolumeMountPointW(szVolumeMountPoint, szVolumeGUID, MAX_PATH);

#undef __szVolumeMountPointPrefix__
}

static BOOL __fastcall BasepGetVolumeDosLetterNameFromNTName(
    const UNICODE_STRING *NtName,
    wchar_t szVolumeDosLetter[MAX_PATH])
{
    wchar_t szVolumeName[MAX_PATH];

    if (!BasepGetVolumeGUIDFromNTName(NtName, szVolumeName))
    {
        return FALSE;
    }

    DWORD cchVolumePathName = 0;

    if (!GetVolumePathNamesForVolumeNameW(
            szVolumeName, szVolumeDosLetter + 4, MAX_PATH - 4, &cchVolumePathName))
    {
        return FALSE;
    }

    szVolumeDosLetter[0] = L'\\';
    szVolumeDosLetter[1] = L'\\';
    szVolumeDosLetter[2] = L'?';
    szVolumeDosLetter[3] = L'\\';

    return TRUE;
}

static UINT __fastcall GetDpiForSystemDownlevel();

} // namespace internal
// 导入实际的实现
#define WP_Thunks_Implemented
#define __DEFINE_THUNK(_MODULE, _SIZE, _RETURN_, _CONVENTION_, _FUNCTION, ...)                     \
    WP_EXTERN_C _CRT_CONCATENATE(wp_function_, _FUNCTION) _CRT_CONCATENATE(wp_get_, _FUNCTION)()   \
        WP_GET_FUNCTION_APPLY(_MODULE, _FUNCTION, _CRT_CONCATENATE(wp_function_, _FUNCTION));      \
    WP_EXTERN_C _RETURN_ _CONVENTION_ _CRT_CONCATENATE(wp_, _FUNCTION)(__VA_ARGS__)

#include "win-polyfill-list.inc.h"

#undef __DEFINE_THUNK
#undef WP_Thunks_Implemented
