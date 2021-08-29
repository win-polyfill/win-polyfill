
cpk_add_test(
  NAME win-polyfill-basic
  SOURCES win-polyfill-basic.UnitTest.c
  LINK_LIBRARIES win-polyfill
  COMPILE_DEFINITIONS -DWIN_POLYFILL_DISABLE_SOCKET
)

cpk_add_test(
  NAME win-polyfill-basic-static
  SOURCES win-polyfill-basic.UnitTest.c
  LINK_LIBRARIES win-polyfill-static
)
