#pragma once

#include <sdkddkver.h>

#ifndef WP_SUPPORT_VERSION
#if defined(_M_IX86)
#define WP_SUPPORT_VERSION NTDDI_WIN2K
#else
#define WP_SUPPORT_VERSION NTDDI_WINXP
#endif
#endif
