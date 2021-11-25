﻿
#include <roerrorapi.h>

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

		//Windows 8 [desktop apps | UWP apps]
		//Windows Server 2012 [desktop apps | UWP apps]
		__DEFINE_THUNK(
		api_ms_win_core_winrt_error_l1_1_0,
		8,
		BOOL,
		WINAPI,
		RoOriginateError,
			_In_ HRESULT error,
			_In_opt_ HSTRING message
			)
		{
			if (auto pRoOriginateError = wp_get_RoOriginateError())
			{
				return pRoOriginateError(error, message);
			}

			return FALSE;
		}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

		//Windows 8 [desktop apps | UWP apps]
		//Windows Server 2012 [desktop apps | UWP apps]
		__DEFINE_THUNK(
		api_ms_win_core_winrt_error_l1_1_0,
		12,
		BOOL,
		WINAPI,
		RoOriginateErrorW,
			_In_ HRESULT error,
			_In_ UINT cchMax,
			_When_(cchMax == 0, _In_reads_or_z_opt_(MAX_ERROR_MESSAGE_CHARS) ) 
					 _When_(cchMax > 0 && cchMax < MAX_ERROR_MESSAGE_CHARS, _In_reads_or_z_(cchMax) )
					 _When_(cchMax >= MAX_ERROR_MESSAGE_CHARS, _In_reads_or_z_(MAX_ERROR_MESSAGE_CHARS) ) PCWSTR message
			)
		{
			if (auto pRoOriginateErrorW = wp_get_RoOriginateErrorW())
			{
				return pRoOriginateErrorW(error, cchMax, message);
			}

			return FALSE;
		}
#endif

