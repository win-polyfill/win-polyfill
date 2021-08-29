#pragma once

#include "win-polyfill-export.h"

#define _Disallow_WP_KM_Namespace
#include "win-polyfill-km.h"

#ifdef __WP_Thunks_Unit_Test
#define __APPLY_UNIT_TEST_BOOL(_FUNCTION)                                                          \
    bool _CRT_CONCATENATE(aways_null_wp_get_, _FUNCTION) = false
#define __CHECK_UNIT_TEST_BOOL(_FUNCTION)                                                          \
    if (_CRT_CONCATENATE(aways_null_wp_get_, _FUNCTION))                                           \
    return nullptr
#else
#define __APPLY_UNIT_TEST_BOOL(_FUNCTION)
#define __CHECK_UNIT_TEST_BOOL(_FUNCTION)
#endif

#pragma section(".YYThu$AAA", long, read, write) // win-polyfill模块缓存节点
#pragma section(".YYThu$AAB", long, read, write) // win-polyfill函数缓存节点
#pragma section(".YYThu$AAC", long, read, write) // 保留，暂时用于边界结束

#pragma section(".YYThr$AAA", long, read) // win-polyfill函数缓存初始化函数
#pragma section(".YYThr$AAB", long, read) // win-polyfill函数反初始化函数
#pragma section(".YYThr$AAC", long, read) // 保留，暂时用于边界结束

#pragma comment(linker, "/merge:.YYThu=.data")
#pragma comment(linker, "/merge:.YYThr=.rdata")

__declspec(allocate(".YYThu$AAA")) static void *__WP_THUNKS_MODULE_START[] = {nullptr};
__declspec(allocate(".YYThu$AAB")) static void *__WP_THUNKS_FUN_START[] = {
    nullptr}; // win-polyfill指针缓存开始位置
__declspec(allocate(".YYThu$AAC")) static void *__WP_THUNKS_FUN_END[] = {
    nullptr}; // win-polyfill指针缓存结束位置

__declspec(allocate(".YYThr$AAA")) static void *__WP_THUNKS_INIT_FUN_START[] = {
    nullptr}; // win-polyfill函数初始化开始位置
#define __WP_THUNKS_INIT_FUN_END __WP_THUNKS_UNINIT_FUN_START // win-polyfill函数初始化结束位置

__declspec(allocate(".YYThr$AAB")) static void *__WP_THUNKS_UNINIT_FUN_START[] = {
    nullptr}; // win-polyfill函数反初始化函数开始
__declspec(allocate(".YYThr$AAC")) static void *__WP_THUNKS_UNINIT_FUN_END[] = {
    nullptr}; // win-polyfill函数反初始化函数结束位置

typedef void *(__cdecl *InitFunType)();
typedef void(__cdecl *UninitFunType)();

#pragma detect_mismatch("win-polyfill-Mode", "ver:" _CRT_STRINGIZE(WP_SUPPORT_VERSION))

/*
导出一个外部符号，指示当前win-polyfillThunks等级。
1. 方便外部检测是否使用了win-polyfill。
2. 当调用者同时使用多个win-polyfill时，使其链接失败！

//自行定义为 C 弱符号，C++支持不佳！
EXTERN_C const DWORD __WP_Thunks_Installed;

if(__WP_Thunks_Installed)
    wprintf(L"检测到使用win-polyfill，Thunks级别=0x%.8X\n", __WP_Thunks_Installed);
else
    wprintf(L"没有使用win-polyfill！\n");

*/
EXTERN_C const DWORD __WP_Thunks_Installed = WP_SUPPORT_VERSION;

/*
导出一个外部弱符号，指示当前是否处于强行卸载模式。

EXTERN_C BOOL __WP_Thunks_Process_Terminating;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    swtich(dwReason)
    {
        case DLL_PROCESS_DETACH:
        //我们可以通过 lpReserved != NULL 判断，当前是否处于强行卸载模式。
        __WP_Thunks_Process_Terminating = lpReserved != NULL;

        ……
        break;
    ……
*/
#if (WP_SUPPORT_VERSION < NTDDI_WINXP)
// Windows 2000不支持RtlDllShutdownInProgress，因此依然引入__WP_Thunks_Process_Terminating
EXTERN_C extern BOOL __WP_Thunks_Process_Terminating;
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
static HANDLE _GlobalKeyedEventHandle;
#endif

static uintptr_t __security_cookie_yy_thunks;

#define _APPLY(_SYMBOL, _NAME, ...)                                                                \
    constexpr const wchar_t *_CRT_CONCATENATE(module_name_, _SYMBOL) = _CRT_WIDE(_NAME);
_WP_APPLY_TO_LATE_BOUND_MODULES(_APPLY)
#undef _APPLY

// Implements wcsncpmp for ASCII chars only.
// NOTE: We can't use wcsncmp in this context because we may end up trying to modify
// locale data structs or even calling the same function in NLS code.
static int _fastcall __wcsnicmp_ascii(
    const wchar_t *string1,
    const wchar_t *string2,
    size_t count) noexcept
{
    wchar_t f, l;
    int result = 0;

    if (count)
    {
        /* validation section */
        do
        {
            f = __ascii_towlower(*string1);
            l = __ascii_towlower(*string2);
            string1++;
            string2++;
        } while ((--count) && f && (f == l));

        result = (int)(f - l);
    }

    return result;
}

enum : int
{
    __crt_maximum_pointer_shift = sizeof(uintptr_t) * 8
};

static __forceinline unsigned int __fastcall __crt_rotate_pointer_value(
    unsigned int const value,
    int const shift) noexcept
{
    return RotateRight32(value, shift);
}

static __forceinline unsigned __int64 __fastcall __crt_rotate_pointer_value(
    unsigned __int64 const value,
    int const shift) noexcept
{
    return RotateRight64(value, shift);
}

#ifdef _WIN64
#define __foreinclude(p)                                                                           \
    __pragma(warning(suppress : 6031)) _bittest64(reinterpret_cast<LONG_PTR *>(&p), 0)
#else
#define __foreinclude(p)                                                                           \
    __pragma(warning(suppress : 6031)) _bittest(reinterpret_cast<LONG_PTR *>(&p), 0)
#endif

static PVOID __fastcall __CRT_DecodePointer(PVOID Ptr)
{
    return reinterpret_cast<PVOID>(__crt_rotate_pointer_value(
        reinterpret_cast<uintptr_t>(Ptr) ^ __security_cookie_yy_thunks,
        __security_cookie_yy_thunks % __crt_maximum_pointer_shift));
}

static PVOID __fastcall __CRT_EncodePointer(PVOID const Ptr)
{
    return reinterpret_cast<PVOID>(
        __crt_rotate_pointer_value(
            reinterpret_cast<uintptr_t>(Ptr),
            __crt_maximum_pointer_shift -
                (__security_cookie_yy_thunks % __crt_maximum_pointer_shift)) ^
        __security_cookie_yy_thunks);
}

template <typename T>
static __forceinline T __fastcall __crt_fast_decode_pointer(T const p) noexcept
{
    return reinterpret_cast<T>(__CRT_DecodePointer(p));
}

template <typename T>
static __forceinline T __fastcall __crt_fast_encode_pointer(T const p) noexcept
{
    return reinterpret_cast<T>(__CRT_EncodePointer(p));
}

template <typename T, typename V>
static __forceinline T *__fastcall __crt_interlocked_exchange_pointer(
    T *const volatile *target,
    V const value) noexcept
{
    // This is required to silence a spurious unreferenced formal parameter
    // warning.
    UNREFERENCED_PARAMETER(value);

    return reinterpret_cast<T *>(_InterlockedExchangePointer((void **)target, (void *)value));
}

template <typename T, typename E, typename C>
static __forceinline T *__fastcall __crt_interlocked_compare_exchange_pointer(
    T *const volatile *target,
    E const exchange,
    C const comparand) noexcept
{
    UNREFERENCED_PARAMETER(exchange);  // These are required to silence spurious
    UNREFERENCED_PARAMETER(comparand); // unreferenced formal parameter warnings.

    return reinterpret_cast<T *>(
        _InterlockedCompareExchangePointer((void **)target, (void *)exchange, (void *)comparand));
}

template <typename T>
static __forceinline T *__fastcall __crt_interlocked_read_pointer(
    T *const volatile *target) noexcept
{
    return __crt_interlocked_compare_exchange_pointer(target, nullptr, nullptr);
}

static HMODULE __fastcall try_load_library_from_system_directory(wchar_t const *const name) noexcept
{
    return LoadLibraryExW(name, nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
}

#define USING_UNSAFE_LOAD 0x00000001

template <int Flags>
static HMODULE __fastcall wp_get_module(
    volatile HMODULE *pModule,
    const wchar_t *module_name) noexcept
{
    // First check to see if we've cached the module handle:
    if (HMODULE const cached_handle = __crt_interlocked_read_pointer(pModule))
    {
        if (cached_handle == INVALID_HANDLE_VALUE)
        {
            return nullptr;
        }

        return cached_handle;
    }

    // If we haven't yet cached the module handle, try to load the library.  If
    // this fails, cache the sentinel handle value INVALID_HANDLE_VALUE so that
    // we don't attempt to load the module again:
    HMODULE const new_handle = (Flags & USING_UNSAFE_LOAD)
                                   ? LoadLibraryW(module_name)
                                   : try_load_library_from_system_directory(module_name);
    if (!new_handle)
    {
        if (HMODULE const cached_handle =
                __crt_interlocked_exchange_pointer(pModule, INVALID_HANDLE_VALUE))
        {
            _ASSERTE(cached_handle == INVALID_HANDLE_VALUE);
        }

        return nullptr;
    }

    // Swap the new handle into the cache.  If the cache no longer contained a
    // null handle, then some other thread loaded the module and cached the
    // handle while we were doing the same.  In that case, we free the handle
    // once to maintain the reference count:
    if (HMODULE const cached_handle = __crt_interlocked_exchange_pointer(pModule, new_handle))
    {
        _ASSERTE(cached_handle == new_handle);
        FreeLibrary(new_handle);
    }

    return new_handle;
}

#define _APPLY(_MODULE, _NAME, _FLAGS)                                                             \
    static volatile HMODULE __fastcall _CRT_CONCATENATE(wp_get_module_, _MODULE)() noexcept        \
    {                                                                                              \
        __declspec(allocate(".YYThu$AAA")) static volatile HMODULE hModule;                        \
        return wp_get_module<_FLAGS>(&hModule, _CRT_CONCATENATE(module_name_, _MODULE));           \
    }
_WP_APPLY_TO_LATE_BOUND_MODULES(_APPLY)
#undef _APPLY

typedef volatile HMODULE(__fastcall *wp_get_module_fun)();

static __forceinline void *__fastcall wp_get_proc_address_from_first_available_module(
    wp_get_module_fun get_module,
    char const *const name) noexcept
{
    HMODULE const module_handle = get_module();
    if (!module_handle)
    {
        return nullptr;
    }

    return reinterpret_cast<void *>(GetProcAddress(module_handle, name));
}

static __forceinline void *__cdecl invalid_function_sentinel() noexcept
{
    return reinterpret_cast<void *>(static_cast<uintptr_t>(-1));
}

static void *__fastcall wp_get_function(
    void **ppFunAddress,
    char const *const name,
    wp_get_module_fun get_module) noexcept
{
    // First check to see if we've cached the function pointer:
    {
        void *const cached_fp =
            __crt_fast_decode_pointer(__crt_interlocked_read_pointer(ppFunAddress));

        if (cached_fp == invalid_function_sentinel())
        {
            return nullptr;
        }

        if (cached_fp)
        {
            return cached_fp;
        }
    }

    // If we haven't yet cached the function pointer, try to import it from any
    // of the modules in which it might be defined.  If this fails, cache the
    // sentinel pointer so that we don't attempt to load this function again:
    void *const new_fp = wp_get_proc_address_from_first_available_module(get_module, name);
    if (!new_fp)
    {
        void *const cached_fp = __crt_fast_decode_pointer(__crt_interlocked_exchange_pointer(
            ppFunAddress, __crt_fast_encode_pointer(invalid_function_sentinel())));

        if (cached_fp)
        {
            _ASSERTE(cached_fp == invalid_function_sentinel());
        }

        return nullptr;
    }

    // Swap the newly obtained function pointer into the cache.  The cache may
    // no longer contain an encoded null pointer if another thread obtained the
    // function address while we were doing the same (both threads should have
    // gotten the same function pointer):
    {
        void *const cached_fp = __crt_fast_decode_pointer(
            __crt_interlocked_exchange_pointer(ppFunAddress, __crt_fast_encode_pointer(new_fp)));

        if (cached_fp)
        {
            _ASSERTE(cached_fp == new_fp);
        }
    }

    return new_fp;
}

#define WP_GET_FUNCTION_APPLY(_MODULE, _FUNCTION, _FUNCTION_TYPE)                                  \
    {                                                                                              \
        __CHECK_UNIT_TEST_BOOL(_FUNCTION);                                                         \
        __declspec(allocate(".YYThr$AAA")) static void *_CRT_CONCATENATE(pInit_, _FUNCTION) =      \
            reinterpret_cast<void *>(&_CRT_CONCATENATE(wp_get_, _FUNCTION));                       \
        /* In order to avoid the compiler optimize section YYThr$AAA out */                        \
        __foreinclude(_CRT_CONCATENATE(pInit_, _FUNCTION));                                        \
        __declspec(allocate(".YYThu$AAB")) static void *_CRT_CONCATENATE(pFun_, _FUNCTION);        \
        return reinterpret_cast<_FUNCTION_TYPE>(wp_get_function(                                   \
            &_CRT_CONCATENATE(pFun_, _FUNCTION),                                                   \
            _CRT_STRINGIZE(_FUNCTION),                                                             \
            &_CRT_CONCATENATE(wp_get_module_, _MODULE)));                                          \
    }

static void __cdecl __WP_uninitialize_winapi_thunks()
{
    // 当DLL被强行卸载时，我们什么都不做。
    if (auto pRtlDllShutdownInProgress = (decltype(RtlDllShutdownInProgress) *)GetProcAddress(
            wp_get_module_ntdll(), "RtlDllShutdownInProgress"))
    {
        if (pRtlDllShutdownInProgress())
            return;
    }
    __if_exists(__WP_Thunks_Process_Terminating)
    {
        else
        {
            if (__WP_Thunks_Process_Terminating)
                return;
        }
    }

    auto pModule = (HMODULE *)__WP_THUNKS_MODULE_START;
    auto pModuleEnd = (HMODULE *)__WP_THUNKS_FUN_START;

    for (; pModule != pModuleEnd; ++pModule)
    {
        auto &module = *pModule;
        if (module)
        {
            if (module != INVALID_HANDLE_VALUE)
            {
                FreeLibrary(module);
            }

            module = nullptr;
        }
    }
#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
    CloseHandle(_GlobalKeyedEventHandle);
#endif

    // 执行本库中所有的反初始化工作。
    for (auto p = (UninitFunType *)__WP_THUNKS_UNINIT_FUN_START;
         p != (UninitFunType *)__WP_THUNKS_UNINIT_FUN_END;
         ++p)
    {
        if (auto pUninitFun = *p)
            pUninitFun();
    }
}

static int __cdecl _WP_initialize_winapi_thunks()
{
    __security_cookie_yy_thunks = __security_cookie;

    void *const encoded_nullptr = __crt_fast_encode_pointer((void *)nullptr);

    for (auto p = __WP_THUNKS_FUN_START; p != __WP_THUNKS_FUN_END; ++p)
    {
        *p = encoded_nullptr;
    }

    /*
     * https://github.com/Chuyu-Team/win-polyfill/issues/7
     * 为了避免 wp_get 系列函数竞争 DLL load锁，因此我们将所有被Thunk的API都预先加载完毕。
     */
    for (auto p = (InitFunType *)__WP_THUNKS_INIT_FUN_START;
         p != (InitFunType *)__WP_THUNKS_INIT_FUN_END;
         ++p)
    {
        if (auto pInitFun = *p)
            pInitFun();
    }

    return 0;
}

static int __cdecl __WP_initialize_winapi_thunks()
{
    _WP_initialize_winapi_thunks();

    // 只在节点位置插入 atexit 流程，避免CRT还没完全初始化好出现问题。
    atexit(__WP_uninitialize_winapi_thunks);

    return 0;
}

typedef int(__cdecl *_PIFV)(void);

#pragma section(".CRT$XID", long, read) // CRT C Initializers

__declspec(allocate(".CRT$XID")) static _PIFV ___Initialization = __WP_initialize_winapi_thunks;
