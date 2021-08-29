#ifndef _WIN_POLYFILL_EXPORT_H_
#define _WIN_POLYFILL_EXPORT_H_

#pragma once

#include "win-polyfill-export-shared.h"

/* 展开函数的所有的 声明 以及 wp_get_ 函数 */
#define __DEFINE_THUNK(_MODULE, _SIZE, _RETURN_, _CONVENTION_, _FUNCTION, ...)                     \
    typedef _RETURN_(_CONVENTION_ *_CRT_CONCATENATE(wp_function_, _FUNCTION))(__VA_ARGS__);        \
    WP_EXTERN_C _RETURN_ _CONVENTION_ _CRT_CONCATENATE(wp_, _FUNCTION)(__VA_ARGS__);               \
    WP_EXTERN_C _CRT_CONCATENATE(wp_function_, _FUNCTION) _CRT_CONCATENATE(wp_get_, _FUNCTION)();

#pragma push_macro("InterlockedCompareExchange64")
#undef InterlockedCompareExchange64
/* The following parted are generated from header files, please do not modify it manually */
