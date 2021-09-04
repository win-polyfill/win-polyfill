#define _WINBASE_
#define _WINGDI_
#define _WINUSER_
#define _WINCON_
#define VER_H
#define _WINREG_
#define _WINNETWK_
#define WIN32_LEAN_AND_MEAN
#define __STRALIGN_H_
#define _WINSVC_
#define _MCX_H_
#define _IMM_
#define _WINSOCKAPI_

#define WIN32_NO_STATUS
#include <windows.h>
/* winnt.h included */

#include <errhandlingapi.h>
#include <handleapi.h>

#undef WIN32_NO_STATUS
#include <ntstatus.h>
