#ifndef _WIN_POLYFILL_EXPORT_SHARED_H_
#define _WIN_POLYFILL_EXPORT_SHARED_H_

/* This file should be included before any windows header when possible */

#pragma once

#if defined(_WIN32)

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
#define INITKNOWNFOLDERS
#endif /* (WP_SUPPORT_VERSION < NTDDI_WIN6) */

/* win-polyfill 保证STDIO新老模式兼容 */
#define _CRT_STDIO_ARBITRARY_WIDE_SPECIFIERS

/* Disable include of sockets from Windows.h */
#if defined(_WINSOCKAPI_) || defined(_INC_WINDOWS)
#define _WIN_POLYFILL_WINDOWS_ALREADY_INCLUDED
#define WIN_POLYFILL_DISABLE_SOCKET
#else
#define _WINSOCKAPI_
#endif

#ifndef PSAPI_VERSION
#define PSAPI_VERSION 1
#endif

#define PATHCCH_NO_DEPRECATE

#ifndef UMDF_USING_NTSTATUS
#define UMDF_USING_NTSTATUS
#endif

#include "win-polyfill-version.h"

#include <crtdbg.h>
#include <intrin.h>

#if !defined(WIN_POLYFILL_DISABLE_SOCKET)
#include <winsock2.h>
#include <ws2def.h>
#include <ws2tcpip.h>
#endif

#include <windows.h>

#if !defined(_WIN_POLYFILL_WINDOWS_ALREADY_INCLUDED)
#include <ntstatus.h>
#include <winnt.h>
#endif

#include <d3d11.h>
#include <d3d9.h>
#include <dbghelp.h>
#include <dwmapi.h>
#include <dxgi.h>
#include <evntprov.h>
#include <ncrypt.h>
#include <pathcch.h>
#include <psapi.h>
#include <roapi.h>
#include <roerrorapi.h>
#include <setupapi.h>
#include <shellapi.h>
#include <shellscalingapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <strsafe.h>
#include <threadpoolapiset.h>
#include <timezoneapi.h>
#include <uxtheme.h>
#include <winnls.h>
#include <winstring.h>

/* iphlpapi should after them all */
#include <iphlpapi.h>

#ifdef __cplusplus
#include <dwrite.h>
#endif

#if !defined(WIN_POLYFILL_EXPORT_SHARED) && !defined(WIN_POLYFILL_EXPORT_STATIC)
#if defined(_DLL)
#define WIN_POLYFILL_EXPORT_SHARED_INFERRED
#else
#define WIN_POLYFILL_EXPORT_STATIC
#define WIN_POLYFILL_EXPORT_STATIC_INFERRED
#endif /* defined(_DLL) */
#endif

#if defined(WIN_POLYFILL_EXPORT_STATIC)
#define WP_EXPORT
#elif defined(WIN_POLYFILL_EXPORT_SHARED)
#define WP_EXPORT __declspec(dllexport)
#else
#define WP_EXPORT __declspec(dllimport)
#pragma comment(lib, "win-polyfill.lib")
#endif

#define WP_EXTERN_C EXTERN_C WP_EXPORT

#endif /* defined(_WIN32) */

#endif /* _WIN_POLYFILL_EXPORT_SHARED_H_ */
