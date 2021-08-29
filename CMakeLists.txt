cmake_minimum_required(VERSION 3.17)

if ("${CMAKE_MSVC_RUNTIME_LIBRARY}" STREQUAL "")
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

if ("${CMAKE_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_BINARY_DIR}")
  project(win-polyfill VERSION 0.1.0.0 LANGUAGES C CXX)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

set(win_polyfill_public_headers
  win-polyfill-export.h
  win-polyfill-export-clean.h
  win-polyfill-export-shared.h
  win-polyfill-version.h
)
set(win_polyfill_api_public_headers
  api-ms-win-core-datetime.hpp
  api-ms-win-core-errorhandling.hpp
  api-ms-win-core-file.hpp
  api-ms-win-core-interlocked.hpp
  api-ms-win-core-io.hpp
  api-ms-win-core-libraryloader.hpp
  api-ms-win-core-localization.hpp
  api-ms-win-core-processthreads.hpp
  api-ms-win-core-psapi.hpp
  api-ms-win-core-realtime.hpp
  api-ms-win-core-registry.hpp
  api-ms-win-core-string.hpp
  api-ms-win-core-synch.hpp
  api-ms-win-core-sysinfo.hpp
  api-ms-win-core-systemtopology.hpp
  api-ms-win-core-util.hpp
  api-ms-win-core-version.hpp
  api-ms-win-core-winrt-error.hpp
  api-ms-win-core-winrt-string.hpp
  api-ms-win-core-winrt.hpp
  api-ms-win-core-wow64.hpp
)
list(APPEND win_polyfill_api_public_headers
  SetupAPI.hpp
  WS2_32.hpp
  advapi32.hpp
  d3d9.hpp
  d3d11.hpp
  dbghelp.hpp
  dwmapi.hpp
  dwrite.hpp
  dxgi.hpp
  gdi32.hpp
  iphlpapi.hpp
  kernel32-polyfill.hpp
  kernel32.hpp
  ncrypt.hpp
  psapi.hpp
  shcore.hpp
  shell32-polyfill.hpp
  shell32.hpp
  shlwapi.hpp
  user32.hpp
  user32-polyfill.hpp
  uxtheme.hpp
)

list(TRANSFORM win_polyfill_public_headers PREPEND ${CMAKE_CURRENT_LIST_DIR}/src/)
list(TRANSFORM win_polyfill_api_public_headers PREPEND polyfill/)
set(win_polyfill_api_public_headers_raw ${win_polyfill_api_public_headers})
list(TRANSFORM win_polyfill_api_public_headers PREPEND ${CMAKE_CURRENT_LIST_DIR}/src/)

add_custom_command(
  OUTPUT
    "${CMAKE_CURRENT_LIST_DIR}/src/win-polyfill-export.h"
  COMMAND ${CMAKE_COMMAND}
    "-DHEADER_FILE_BEGIN=${CMAKE_CURRENT_LIST_DIR}/src/win-polyfill-export-begin.inc.h"
    "-DHEADER_FILES=${win_polyfill_api_public_headers_raw}"
    "-DHEADER_DIR=${CMAKE_CURRENT_LIST_DIR}/src"
    "-DHEADER_FILE_END=${CMAKE_CURRENT_LIST_DIR}/src/win-polyfill-export-end.inc.h"
    "-DOUTPUT_HEADER_FILE=${CMAKE_CURRENT_LIST_DIR}/src/win-polyfill-export.h"
    "-DOUTPUT_LIST_FILE=${CMAKE_CURRENT_LIST_DIR}/src/win-polyfill-list.inc.h"
    -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/extract_win32_api.cmake
  DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/extract_win32_api.cmake
    ${win_polyfill_api_public_headers}
    ${CMAKE_CURRENT_LIST_DIR}/src/win-polyfill-export-begin.inc.h
    ${CMAKE_CURRENT_LIST_DIR}/src/win-polyfill-export-end.inc.h
)

add_library(win-polyfill-static STATIC
  "${CMAKE_CURRENT_LIST_DIR}/src/win-polyfill-export.h"
  src/win-polyfill.cpp
)
target_compile_definitions(win-polyfill-static PUBLIC -DWIN_POLYFILL_EXPORT_STATIC)
target_compile_definitions(win-polyfill-static PRIVATE
  -DWIN32_LEAN_AND_MEAN
)
target_include_directories(win-polyfill-static PUBLIC src)

add_library(win-polyfill SHARED
  "${CMAKE_CURRENT_LIST_DIR}/src/win-polyfill-export.h"
  src/win-polyfill.cpp
)
target_compile_definitions(win-polyfill PUBLIC -DWIN_POLYFILL_EXPORT_SHARED)
target_include_directories(win-polyfill PUBLIC src)
set_target_properties(win-polyfill PROPERTIES CPK_PUBLIC_FILES "${win_polyfill_public_headers}")

target_compile_definitions(win-polyfill-static PUBLIC -DUNICODE -D_UNICODE)
target_compile_definitions(win-polyfill PUBLIC -DUNICODE -D_UNICODE)

install(TARGETS win-polyfill)
if (MSVC)
  install(FILES $<TARGET_PDB_FILE:win-polyfill> DESTINATION bin)
endif()
install(TARGETS win-polyfill-static)

include(cmake/CpkHelpers.cmake)
cpk_install_public_files(
  win-polyfill
  DESTINATION_DIR include
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src/
)

if(BUILD_TESTING)
  include(CTest)
  enable_testing()
  add_subdirectory(src/YY-Thunks.UnitTest)
endif()
