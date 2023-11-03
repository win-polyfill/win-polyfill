#undef WIN_POLYFILL_DISABLE_SOCKET
#include "win-polyfill-shared.h"

#define _Disallow_YY_KM_Namespace
#include "win-polyfill-km.h"

//展开函数的所有的 声明 以及 try_get_ 函数
#define __DEFINE_THUNK(_MODULE, _SIZE, _RETURN_, _CONVENTION_, _FUNCTION, ...)                     \
    EXTERN_C _RETURN_ _CONVENTION_ wp_##_FUNCTION(__VA_ARGS__);                                    \
    __if_not_exists(CreateFileW)

#include "win-polyfill-list.h"

#undef __DEFINE_THUNK

#pragma warning(push)
#pragma warning(disable: 4483)

#if defined(_M_IX86)
/* x86的符号存在@ 我们使用 identifier 特性解决 */
#define _LCRT_DEFINE_IAT_SYMBOL(_FUNCTION, _SIZE)                                                  \
    extern "C" __declspec(selectany) void const *const __identifier(_CRT_STRINGIZE_(               \
        _imp__##_FUNCTION##@##_SIZE)) = reinterpret_cast<void const *>(YY::Thunks::wp_##_FUNCTION)
#else
#define _LCRT_DEFINE_IAT_SYMBOL(_FUNCTION, _SIZE)                                                  \
    extern "C" __declspec(selectany) void const *const _CRT_CONCATENATE(__imp_, _FUNCTION) =       \
        reinterpret_cast<void const *>(YY::Thunks::wp_##_FUNCTION)
#endif

/* 展开函数的重定向 */
#define __DEFINE_THUNK(_MODULE, _SIZE, _RETURN_, _CONVENTION_, _FUNCTION, ...)                     \
    _LCRT_DEFINE_IAT_SYMBOL(_FUNCTION, _SIZE);                                                     \
    __if_not_exists(CreateFileW)

#include "win-polyfill-list.h"

#undef __DEFINE_THUNK
#pragma warning(pop)
