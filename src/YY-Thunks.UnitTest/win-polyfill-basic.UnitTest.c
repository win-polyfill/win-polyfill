#include <win-polyfill-export-shared.h>

#include <stdio.h>

int main(int argc, char **argv)
{
    HANDLE hFile = INVALID_HANDLE_VALUE;
    FILE_INFO_BY_HANDLE_CLASS FileInformationClass = FileBasicInfo;
    LPVOID lpFileInformation = NULL;
    DWORD dwBufferSize = 0;
    ULONGLONG wp_tick64bit = GetTickCount64();
    DWORD tick32bit = GetTickCount();
    ULONGLONG tick64Bit = GetTickCount64();
    printf("tick32bit: %u tick64Bit:%llu wp_tick64bit:%llu\n", tick32bit, tick64Bit, wp_tick64bit);
    GetFileInformationByHandleEx(hFile, FileInformationClass, lpFileInformation, dwBufferSize);
    return 0;
}
