#ifndef __DEFINE_THUNK
#include "win-polyfill-export-shared.h"
#define __DEFINE_THUNK(_MODULE, _SIZE, _RETURN_, _CONVENTION_, _FUNCTION, ...)                     \
    WP_EXTERN_C _RETURN_ _CONVENTION_ _CRT_CONCATENATE(wp_, _FUNCTION)(__VA_ARGS__)

#endif
