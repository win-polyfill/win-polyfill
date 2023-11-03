
add_library(win-polyfill-static STATIC
  win-polyfill-shared.h
  win-polyfill-get.h
  win-polyfill.h
  win-polyfill.cpp
)
target_include_directories(win-polyfill-static PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/../Shared
)
set_target_properties(win-polyfill-static PROPERTIES
  CPK_PUBLIC_FILES
    "${CMAKE_CURRENT_LIST_DIR}/win-polyfill-shared.h"
)

target_compile_definitions(win-polyfill-static PUBLIC
  -DUNICODE
  -D_UNICODE
)
target_compile_options(win-polyfill-static PRIVATE
  -wd4731
)

add_library(win-polyfill SHARED
  win-polyfill-shared.h
  win-polyfill-get.h
  win-polyfill.h
  win-polyfill.cpp
  win-polyfill-override-inner.cpp
)

# https://learn.microsoft.com/en-us/cpp/c-runtime-library/crt-library-features?view=msvc-170
target_link_options(win-polyfill PRIVATE
  /DEF:${CMAKE_CURRENT_LIST_DIR}/win-polyfill.def
  /NODEFAULTLIB:kernel32.lib
  ${CMAKE_CURRENT_LIST_DIR}/kernel32.lib
)

target_include_directories(win-polyfill PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/../Shared
)
target_compile_definitions(win-polyfill PRIVATE
  -DUNICODE
  -D_UNICODE
  -DWIN_POLYFILL_BUILD_SHARED
)
target_compile_options(win-polyfill PRIVATE
  -wd4731
)
target_link_libraries(win-polyfill PRIVATE)

install(TARGETS win-polyfill-static)

cpk_install_public_files(
  win-polyfill-static
  DESTINATION_DIR include
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}
)
