# win-polyfill - A shared library to getting new software compatible with old Windows

## About win-polyfill

As we know, most newly released software are only compatible with Windows 7 and upper, and even
only compatible with Windows 10. And this getting most software doesn't compatible with Windows XP RTM SP4 or
other old Windows. So we create this project to fixes the gap. As a fork of [YY-Thunks](https://github.com/Chuyu-Team/YY-Thunks), the philosophy of this project are creating a single shared library, so we can upgrading `win-polyfill.dll`
independently， and document it in English for receiving broader usage.

## Design

Using `LoadLibrary` and `GetProcAddress` to loading Win32 API dynamically, if there is possibility to
polyfill the new Win32 API and old Windows, then we polyfill it as much as possible. If polyfill is not
possible, for Windows have native support for the API we use it directly, otherwise we return Win32 errorcode
`ERROR_NOT_SUPPORTED`

### Highlights

* Faster and safer. `win-polyfill` have embed 2 layered cache, loading Win32 API when necessary, and encrypt all function pointer for avoid memory brute force attack. Reduce the calling to `LoadLibrary` and `GetProcAddress`.
* Easily compatible with `Windows XP RTM`, getting the software developer focus on functional.
* PR are welcome, looks like create a `Wine` on old Windows.

### Usage

Download the released binary, include `wp_export.h` or `wp_export_clean.h`, then prefix
the called Win32 API function that need polyfill with `wp_`. Also we can use
`wp_get_${Win32_API_Name}` to test if a specific Win32 API are available on current
running Windows OS when using MSVC 2015 C++ and upper.

### Contribution

Suggest use vscode, vscode-cpptools, and vscode-cmake-tools to developing win-polyfill.
PR are welcome.

### Supported compilers

Following compilers are supported, always need the newest Windows SDK:

* VS2015
* VS2017
* VS2019

### Polyfill list

Refer to [PolyfillList.md](PolyfillList.md)

## Update log

Refer to [Changelog.md](Changelog.md)
