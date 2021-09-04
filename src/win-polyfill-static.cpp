
#define _WINBASE_
#define _WINGDI_
#define _WINUSER_
#define _WINCON_
#define VER_H
#define _WINREG_
#define _WINNETWK_
#define WIN32_LEAN_AND_MEAN
#define __STRALIGN_H_
#define _WINSVC_
#define _MCX_H_
#define _IMM_
#define _WINSOCKAPI_

#define WIN32_NO_STATUS
#include <windows.h>
/* winnt.h included */

#include <errhandlingapi.h>
#include <handleapi.h>

#define _Disallow_WP_KM_Namespace
#include "win-polyfill-km.h"

#undef WIN32_NO_STATUS
#include <ntstatus.h>

#pragma comment(lib, "ntdll.lib")
#include "win-polyfill-runonce-inc.h"

#include "win-polyfill-abi.h"
#include <stdio.h>

/**
 * @brief Thread-safe one-time initialization in C++11
 * https://gist.github.com/alexeiz/3371541
 */
static ULONG __stdcall load_module(
    _Inout_ PRTL_RUN_ONCE RunOnce,
    _Inout_opt_ PVOID Parameter,
    _Inout_opt_ PVOID *Context)
{
    HMODULE module = LoadLibraryW(L"win-polyfill.dll");
    if (module == NULL)
    {
        return STATUS_DLL_NOT_FOUND;
    }
    *Context = GetProcAddress(module, "load_identifier");
    return STATUS_SUCCESS;
}

/* https://docs.microsoft.com/en-us/windows/win32/sync/using-one-time-initialization */
void *wp_load_identifier(enum win_polyfill_identifier id)
{
    static RTL_RUN_ONCE once = {0};
    static wp_load_identifier_function lower_load_identifer = NULL;
    void *result = NULL;
    NTSTATUS status = RtlRunOnceExecuteOnce(
        &once,       // One-time initialization structure
        load_module, // Pointer to initialization callback function
        NULL,        // Optional parameter to callback function (not used)
        (void **)&lower_load_identifer);

    if (STATUS_SUCCESS != status)
    {
        /* fatal error */
        RaiseStatus(status);
    }
    else
    {
        result = lower_load_identifer(id);
    }
    return result;
}

#if defined(_M_IX86)
#define LCRT_DEFINE_IAT_SYMBOL(_FUNCTION, _SIZE) _CRT_STRINGIZE_(_FUNCTION##@##_SIZE)
#else
#define LCRT_DEFINE_IAT_SYMBOL(_FUNCTION, _SIZE) _CRT_STRINGIZE_(_FUNCTION)
#endif

#define _Args(...) __VA_ARGS__
#define STRIP_PARENS(X) X
#define PASS_PARAMETERS(X) STRIP_PARENS(_Args X)

#define DEFINE_THUNK(                                                                              \
    _FUNCTION,                                                                                     \
    _SIZE,                                                                                         \
    _CONVENTION_,                                                                                  \
    NT_API_VERSION,                                                                                \
    _RETURN_,                                                                                      \
    _RETURN_DEFAULT,                                                                               \
    DECL_ARGS,                                                                                     \
    CALL_ARGS)                                                                                     \
    __pragma(warning(push));                                                                       \
    __pragma(warning(disable : 4483));                                                             \
    typedef _RETURN_(_CONVENTION_ *_CRT_CONCATENATE(wp_function_, _FUNCTION))(                     \
        PASS_PARAMETERS(DECL_ARGS));                                                               \
    static _RETURN_ _CONVENTION_ forwared_##_FUNCTION(PASS_PARAMETERS(DECL_ARGS));                 \
    extern "C" const void *__identifier(LCRT_DEFINE_IAT_SYMBOL(_FUNCTION, _SIZE)) =                \
        forwared_##_FUNCTION;                                                                      \
    static _RETURN_ _CONVENTION_ forwared_##_FUNCTION(PASS_PARAMETERS(DECL_ARGS))                  \
    {                                                                                              \
        /* Once loaded, then modify the function pointer and execute it */                         \
        _CRT_CONCATENATE(wp_function_, _FUNCTION) func;                                            \
        func = (_CRT_CONCATENATE(wp_function_, _FUNCTION))wp_load_identifier(wp_id_##_FUNCTION);   \
        if (func != NULL)                                                                          \
        {                                                                                          \
            __identifier(LCRT_DEFINE_IAT_SYMBOL(_FUNCTION, _SIZE)) = func;                         \
            return func(PASS_PARAMETERS(CALL_ARGS));                                               \
        }                                                                                          \
        return _RETURN_DEFAULT;                                                                    \
    }                                                                                              \
    __pragma(warning(pop));

DEFINE_THUNK(
    SystemParametersInfoForDpi,
    20,
    WINAPI,
    NTDDI_WIN6,
    BOOL,
    FALSE,
    (_In_ UINT uiAction,
     _In_ UINT uiParam,
     _Pre_maybenull_ _Post_valid_ PVOID pvParam,
     _In_ UINT fWinIni,
     _In_ UINT dpi),
    (uiAction, uiParam, pvParam, fWinIni, dpi))
