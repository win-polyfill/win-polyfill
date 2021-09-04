#include "win-polyfill-export-shared.h"

#define _Disallow_WP_KM_Namespace
#include "win-polyfill-km.h"

#pragma comment(lib, "ntdll.lib")
#include "win-polyfill-runonce-inc.h"

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
void *wp_load_identifier(const void **identifer, enum win_polyfill_identifier id)
{
    static RTL_RUN_ONCE once = {0};
    static wp_load_identifier_function lower_load_identifer = NULL;
    NTSTATUS status = RtlRunOnceExecuteOnce(
        &once,       // One-time initialization structure
        load_module, // Pointer to initialization callback function
        NULL,        // Optional parameter to callback function (not used)
        (void **)&lower_load_identifer);

    if (STATUS_SUCCESS != status)
    {
        /* If debugger mode, debug break */
        return NULL;
    }
    else
    {
        return lower_load_identifer(identifer, id);
    }
}

#define _Args(...) __VA_ARGS__
#define STRIP_PARENS(X) X
#define PASS_PARAMETERS(X) STRIP_PARENS(_Args X)

#define DEFINE_THUNK(                                                                              \
    _FUNCTION,                                                                                     \
    _CONVENTION_,                                                                                  \
    _NT_API_VERSION,                                                                               \
    _RETURN_,                                                                                      \
    _RETURN_DEFAULT,                                                                               \
    _DECLARE_ARGS,                                                                                 \
    _CALLING_ARGS)                                                                                 \
    __pragma(warning(push));                                                                       \
    __pragma(warning(disable : 4483 4273));                                                        \
    typedef _RETURN_(_CONVENTION_ *_CRT_CONCATENATE(wp_function_, _FUNCTION))(                     \
        PASS_PARAMETERS(_DECLARE_ARGS));                                                           \
    static _RETURN_ _CONVENTION_ _CRT_CONCATENATE(wp_function_default_, _FUNCTION)(                \
        PASS_PARAMETERS(_DECLARE_ARGS));                                                           \
    static _CRT_CONCATENATE(wp_function_, _FUNCTION)                                               \
        _CRT_CONCATENATE(wp_function_private_, _FUNCTION) =                                        \
            _CRT_CONCATENATE(wp_function_default_, _FUNCTION);                                     \
    static _RETURN_ _CONVENTION_ _CRT_CONCATENATE(wp_function_default_, _FUNCTION)(                \
        PASS_PARAMETERS(_DECLARE_ARGS))                                                            \
    {                                                                                              \
        /* Once loaded, then modify the function pointer and execute it */                         \
        _CRT_CONCATENATE(wp_function_, _FUNCTION)                                                  \
        func = (_CRT_CONCATENATE(wp_function_, _FUNCTION))wp_load_identifier(                      \
            (const void **)&_CRT_CONCATENATE(wp_function_private_, _FUNCTION), wp_id_##_FUNCTION); \
        if (func != NULL)                                                                          \
        {                                                                                          \
            return func(PASS_PARAMETERS(_CALLING_ARGS));                                           \
        }                                                                                          \
        return _RETURN_DEFAULT;                                                                    \
    }                                                                                              \
    EXTERN_C _RETURN_ _CONVENTION_ _FUNCTION(PASS_PARAMETERS(_DECLARE_ARGS))                       \
    {                                                                                              \
        return _CRT_CONCATENATE(wp_function_private_, _FUNCTION)(PASS_PARAMETERS(_CALLING_ARGS));  \
    }                                                                                              \
    __pragma(warning(pop));

DEFINE_THUNK(
    SystemParametersInfoForDpi,
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
