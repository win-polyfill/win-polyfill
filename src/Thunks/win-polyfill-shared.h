#pragma once
#include <sal.h>

/* 支持到 Windows 2000 */
#define YY_Thunks_Support_Version NTDDI_WIN2K

//YY-Thunks保证STDIO新老模式兼容
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

#include <crtdbg.h>
#include <intrin.h>
#include <strsafe.h>

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

#include <bluetoothleapis.h>
#include <d3d11.h>
#include <d3d9.h>
#include <dbghelp.h>
#include <dwmapi.h>
#include <dxgi.h>
#include <evntprov.h>
#include <mfapi.h>
#include <ncrypt.h>
#include <pathcch.h>
#include <pdh.h>
#include <powrprof.h>
#include <psapi.h>
#include <roapi.h>
#include <roerrorapi.h>
#include <setupapi.h>
#include <shellapi.h>
#include <shellscalingapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <threadpoolapiset.h>
#include <timezoneapi.h>
#include <userenv.h>
#include <uxtheme.h>
#include <winnls.h>
#include <winstring.h>

#ifdef __cplusplus
#include <dwrite.h>
#endif

/* iphlpapi should after them all */
#include <iphlpapi.h>

/* lmjoin should after iphlpapi */
#include <lmjoin.h>
