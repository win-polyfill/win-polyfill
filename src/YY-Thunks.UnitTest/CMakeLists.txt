
cpk_add_test(
  NAME win-polyfill-basic
  SOURCES
    win-polyfill-basic.UnitTest.c
    ../Thunks/win-polyfill-override-all.cpp
  LINK_LIBRARIES win-polyfill
  COMPILE_DEFINITIONS -DWIN_POLYFILL_DISABLE_SOCKET
)

cpk_add_test(
  NAME win-polyfill-basic-static
  SOURCES
    win-polyfill-basic.UnitTest.c
    ../Thunks/win-polyfill-override-all.cpp
    weak.c
  LINK_LIBRARIES win-polyfill-static
)

cpk_add_test(
  NAME win-polyfill-font
  SOURCES
    win-polyfill-font.UnitTest.c
    ../Thunks/win-polyfill-override-all.cpp
    weak.c
  LINK_LIBRARIES win-polyfill-static gdi32
)

cpk_add_test(
  NAME win-polyfill-font-cpp
  SOURCES
    win-polyfill-font.UnitTest.cpp
    ../Thunks/win-polyfill-override-all.cpp
  LINK_LIBRARIES win-polyfill gdi32
)
