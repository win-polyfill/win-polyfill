﻿#pragma once

#undef NTDDI_VERSION
#undef WINVER
#undef _WIN32_WINNT

#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00

#include <sdkddkver.h>

#ifndef WP_SUPPORT_VERSION
#define WP_SUPPORT_VERSION NTDDI_WINXP
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN_POLYFILL_EXPORT_STATIC
#define WIN_POLYFILL_EXPORT_STATIC
#endif
