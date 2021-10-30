#pragma once

#undef NTDDI_VERSION
#undef WINVER
#undef _WIN32_WINNT

#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00

#include <sdkddkver.h>

#ifndef WP_SUPPORT_VERSION
#define WP_SUPPORT_VERSION NTDDI_WINXP
#endif
