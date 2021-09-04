
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
    "${WIN_POLYFILL_ROOT_DIR}/src/win-polyfill-static.cpp"
  LINK_LIBRARIES gdi32
)

cpk_add_test(
  NAME win-polyfill-static-cpp.UnitTes
  SOURCES
    win-polyfill-static-cpp.UnitTest.cpp
    "${WIN_POLYFILL_ROOT_DIR}/src/win-polyfill-static.cpp"
  LINK_LIBRARIES gdi32
)
