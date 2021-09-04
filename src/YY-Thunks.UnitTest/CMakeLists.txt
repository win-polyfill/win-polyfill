
cpk_add_test(
  NAME win-polyfill-basic
  SOURCES win-polyfill-basic.UnitTest.c
  LINK_LIBRARIES win-polyfill
  COMPILE_DEFINITIONS -DWIN_POLYFILL_DISABLE_SOCKET
)

cpk_add_test(
  NAME win-polyfill-static.UnitTest
  SOURCES
    win-polyfill-static.UnitTest.c
  LINK_LIBRARIES gdi32 win-polyfill-static
)

cpk_add_test(
  NAME win-polyfill-static-cpp.UnitTes
  SOURCES
    win-polyfill-static-cpp.UnitTest.cpp
  LINK_LIBRARIES gdi32 win-polyfill-static
)
