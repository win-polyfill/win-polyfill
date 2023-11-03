#pragma once

#include "win-polyfill.h"

#pragma push_macro("InterlockedCompareExchange64")
#undef InterlockedCompareExchange64
#include "win-polyfill-get.h"
#pragma pop_macro("InterlockedCompareExchange64")

using namespace YY::Thunks::TryGet;
using YY::Thunks::internal::WinPolyfillOnce;

#pragma detect_mismatch("YY-Thunks-Mode", "ver:" _CRT_STRINGIZE(YY_Thunks_Support_Version))

/*
导出一个外部符号，指示当前鸭船Thunks等级。
1. 方便外部检测是否使用了鸭船。
2. 当调用者同时使用多个鸭船时，使其链接失败！

//自行定义为 C 弱符号，C++支持不佳！
EXTERN_C const DWORD __YY_Thunks_Installed;

if(__YY_Thunks_Installed)
    wprintf(L"检测到使用YY-Thunks，Thunks级别=0x%.8X\n", __YY_Thunks_Installed);
else
    wprintf(L"没有使用YY-Thunks！\n");

*/
EXTERN_C const DWORD __YY_Thunks_Installed = YY_Thunks_Support_Version;

/*
导出一个外部弱符号，指示当前是否处于强行卸载模式。

EXTERN_C BOOL __YY_Thunks_Process_Terminating;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    switch(dwReason)
    {
        case DLL_PROCESS_DETACH:
        //我们可以通过 lpReserved != NULL 判断，当前是否处于强行卸载模式。
        __YY_Thunks_Process_Terminating = lpReserved != NULL;

        ……
        break;
    ……
*/
#if (YY_Thunks_Support_Version < NTDDI_WINXP)
//Windows 2000不支持RtlDllShutdownInProgress，因此依然引入__YY_Thunks_Process_Terminating
#ifdef WIN_POLYFILL_BUILD_SHARED
static BOOL __YY_Thunks_Process_Terminating;
#else
EXTERN_C extern BOOL __YY_Thunks_Process_Terminating;
#endif // WIN_POLYFILL_BUILD_SHARED
#endif

static uintptr_t __security_cookie_yy_thunks;

// Implements wcsncpmp for ASCII chars only.
// NOTE: We can't use wcsncmp in this context because we may end up trying to modify
// locale data structs or even calling the same function in NLS code.
static int __fastcall __wcsnicmp_ascii(const wchar_t* string1, const wchar_t* string2, size_t count) noexcept
{
    wchar_t f, l;
    int result = 0;

    if (count)
    {
        /* validation section */
        do {
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

static __forceinline unsigned int __fastcall __crt_rotate_pointer_value(unsigned int const value, int const shift) noexcept
{
    return RotateRight32(value, shift);
}

static __forceinline unsigned __int64 __fastcall __crt_rotate_pointer_value(unsigned __int64 const value, int const shift) noexcept
{
    return RotateRight64(value, shift);
}

#ifdef _WIN64
#define __foreinclude(p)                          \
    __pragma(warning(suppress:6031))              \
    _bittest64(reinterpret_cast<LONG_PTR*>(&p), 0)
#else
#define __foreinclude(p)                          \
    __pragma(warning(suppress:6031))              \
    _bittest(reinterpret_cast<LONG_PTR*>(&p), 0)
#endif


static PVOID __fastcall __CRT_DecodePointer(
        PVOID Ptr
    )
{
    return reinterpret_cast<PVOID>(
        __crt_rotate_pointer_value(
            reinterpret_cast<uintptr_t>(Ptr) ^ __security_cookie_yy_thunks,
            __security_cookie_yy_thunks % __crt_maximum_pointer_shift
        )
        );
}

static PVOID __fastcall __CRT_EncodePointer(PVOID const Ptr)
{
    return reinterpret_cast<PVOID>(
        __crt_rotate_pointer_value(
            reinterpret_cast<uintptr_t>(Ptr),
            __crt_maximum_pointer_shift - (__security_cookie_yy_thunks % __crt_maximum_pointer_shift)
        ) ^ __security_cookie_yy_thunks
        );
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

static void __fastcall call_once_context(long *flag, void (*func)(void *context), void *context) noexcept
{
    WinPolyfillOnce onceCurrent = (WinPolyfillOnce)InterlockedCompareExchange(
        (LONG volatile *)flag, (long)WinPolyfillOnce::OnceLoading, (long)WinPolyfillOnce::OnceInit);
    switch (onceCurrent) {
    case WinPolyfillOnce::OnceInit:
        (func)(context);
        InterlockedExchange((LONG volatile *)flag, (long)WinPolyfillOnce::OnceFinished);
        break;
    case WinPolyfillOnce::OnceLoading:
        while (*flag != WinPolyfillOnce::OnceFinished)
        {
            // busy loop!
            YieldProcessor();
        }
        break;
    case WinPolyfillOnce::OnceFinished:
        // done
        break;
    default:
        break;
    }
}
struct WinPolyfillModuleContext {
    WinPolyfillModule *module_info;
    const wchar_t *name;
    WinPolyfillModuleId module_id;
};

static long win_polyfill_init_once;
static CRITICAL_SECTION win_polyfill_cs;
static void win_polyfill_init_once_callback(void *context) noexcept
{
    __security_cookie_yy_thunks = __security_cookie;
    InitializeCriticalSection(&win_polyfill_cs);
}

static void try_get_module_callback(void *context) noexcept
{
    call_once_context(&win_polyfill_init_once, win_polyfill_init_once_callback, nullptr);
    WinPolyfillModuleContext *module_context = (WinPolyfillModuleContext *)context;
    HMODULE h;
    EnterCriticalSection(&win_polyfill_cs);
    if (module_context->module_id < YY::Thunks::internal::WinPolyfillModuleIdPreloadCount) {
        h = GetModuleHandleW(module_context->name);
    } else {
        h = YY::Thunks::LoadLibraryExW(module_context->name, nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    }
    LeaveCriticalSection(&win_polyfill_cs);
    module_context->module_info->h = __crt_fast_encode_pointer(h);
}

static WinPolyfillModule winpolyfill_module_list[WinPolyfillModuleId::WinPolyfillModuleIdCount];

static HMODULE __fastcall try_get_module_by_name(WinPolyfillModuleId module_id, const wchar_t *name) noexcept
{
    WinPolyfillModule *module_info = winpolyfill_module_list + module_id;
    if (module_info->once != WinPolyfillOnce::OnceFinished)
    {
        WinPolyfillModuleContext context;
        context.module_info = module_info;
        context.name = name;
        context.module_id = module_id;
        call_once_context(&module_info->once, try_get_module_callback, &context);
    }
    return __crt_fast_decode_pointer(module_info->h);
}

struct WinPolyfillFunctionContext {
    WinPolyfillFunction *function_info;
    const char *name;
    WinPolyfillModuleId module_id;
};

static void try_get_function_callback(void *context) noexcept
{
    WinPolyfillFunctionContext *function_context = (WinPolyfillFunctionContext *)context;
    auto module_handle = try_get_module(function_context->module_id);
    auto new_fp = reinterpret_cast<void*>(GetProcAddress(module_handle, function_context->name));
    function_context->function_info->p = __crt_fast_encode_pointer(new_fp);
}

static void *__fastcall try_get_function(WinPolyfillFunction *function_info, const char *name, WinPolyfillModuleId module_id) noexcept
{
    if (function_info->once != WinPolyfillOnce::OnceFinished)
    {
        WinPolyfillFunctionContext context;
        context.function_info = function_info;
        context.name = name;
        context.module_id = module_id;
        call_once_context(&function_info->once, try_get_function_callback, &context);
    }
    return __crt_fast_decode_pointer(function_info->p);
}

#include "ThreadRunner.h"

//导入实际的实现
#define YY_Thunks_Implemented
#define __DEFINE_THUNK(_MODULE, _SIZE, _RETURN_, _CONVENTION_, _FUNCTION, ...)                     \
    EXTERN_C _RETURN_ _CONVENTION_ wp_##_FUNCTION(__VA_ARGS__)

#include "win-polyfill-list.h"

#undef __DEFINE_THUNK
#undef YY_Thunks_Implemented

static bool g_bUninitialize/* = false*/;

static void __cdecl __YY_uninitialize_winapi_thunks()
{
    // 值反初始化一次
    if (g_bUninitialize)
        return;

    g_bUninitialize = true;

    //当DLL被强行卸载时，我们什么都不做。
    if (auto pRtlDllShutdownInProgress = try_get_RtlDllShutdownInProgress())
    {
        if(pRtlDllShutdownInProgress())
            return;
    }
    __if_exists(__YY_Thunks_Process_Terminating)
    {
        else
        {
            if (__YY_Thunks_Process_Terminating)
                return;
        }
    }

    //预加载的dll不需要卸载，目前是 ntdll 和 kernel32
    for (int module_id = YY::Thunks::internal::WinPolyfillModuleIdPreloadCount;
         module_id < WinPolyfillModuleId::WinPolyfillModuleIdCount;
         module_id += 1)
    {
        auto module_info = winpolyfill_module_list + module_id;
        if (module_info->once == WinPolyfillOnce::OnceFinished) {
            auto h = __crt_fast_decode_pointer(module_info->h);
            if (h != nullptr) {
                FreeLibrary(h);
                module_info->h = nullptr;
            }
            module_info->once = WinPolyfillOnce::OnceInit;
        }
    }
#if (YY_Thunks_Support_Version < NTDDI_WIN6)
    auto keyed_handle = YY::Thunks::internal::GetGlobalKeyedEventHandle(true);
    if (keyed_handle != nullptr) {
        CloseHandle(keyed_handle);
    }
#endif

    //执行本库中所有的反初始化工作。
    YY::Thunks::Fallback::UninitPageVirtualProtect();
}


static int __cdecl _YY_initialize_winapi_thunks()
{
    call_once_context(&win_polyfill_init_once, win_polyfill_init_once_callback, nullptr);

    /*
     * https://github.com/Chuyu-Team/YY-Thunks/issues/7
     * 为了避免 try_get 系列函数竞争 DLL load锁，因此我们将所有dll加载完毕
     */
    for (WinPolyfillModuleId module_id = (WinPolyfillModuleId)0;
        module_id < YY::Thunks::internal::WinPolyfillModuleIdPreloadCount;
        module_id = (WinPolyfillModuleId)(module_id + 1))
    {
        try_get_module(module_id);
    }

    return 0;
}

// https://learn.microsoft.com/en-us/cpp/c-runtime-library/crt-library-features?view=msvc-170
#ifndef _DLL
// 外部weak符号，用于判断当前是否静态
EXTERN_C extern void* __acrt_atexit_table;
#endif

static int __cdecl __YY_initialize_winapi_thunks()
{
    _YY_initialize_winapi_thunks();
#ifndef _DLL
    // 如果 == null，那么有2种情况：
    //   1. 非UCRT，比如2008，VC6，这时，调用 atexit是安全的，因为atexit在 XIA初始化完成了。
    //   2. UCRT 并且处于MD状态。这时 atexit初始化 会提与 XIA，这时也是没有问题的。
    // 如果 != null：
    //   那么说明UCRT处于静态状态（CRT DLL其实也是静态的一种）
    //   这时，XTY是可以正确执行的，这时就不用调用atexit了
    //   由于XTY晚于onexit，所以它是可靠的。
    if (__acrt_atexit_table == nullptr)
    {
        atexit(__YY_uninitialize_winapi_thunks);
    }
#endif

    return 0;
}


typedef int(__cdecl* _PIFV)(void);
typedef void(__cdecl* _PVFV)(void);

// CRT C Initializers
#pragma section(".CRT$XID",    long, read)
// CRT C Terminators（仅稍微之后于XTZ），这是故意的。
// YY-Thunks属于API底层理应尽可能的滞后，且反初始化工作不依赖与CRT
#pragma section(".CRT$XTY",    long, read)

__declspec(allocate(".CRT$XID")) static _PIFV ___Initialization = __YY_initialize_winapi_thunks;
__declspec(allocate(".CRT$XTY")) static _PVFV ___Uninitialization = __YY_uninitialize_winapi_thunks;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    switch(dwReason)
    {
    case DLL_PROCESS_DETACH:
#if (YY_Thunks_Support_Version < NTDDI_WINXP)
        //我们可以通过 lpReserved != NULL 判断，当前是否处于强行卸载模式。
        __YY_Thunks_Process_Terminating = lpReserved != NULL;
#endif
        __YY_uninitialize_winapi_thunks();
        break;
    }
    return TRUE;
}
