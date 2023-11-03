cmake_minimum_required(VERSION 3.17)
include(cmake/CpkHelpers.cmake)

if ("${CMAKE_MSVC_RUNTIME_LIBRARY}" STREQUAL "")
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

if ("${CMAKE_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_BINARY_DIR}")
  project(win-polyfill VERSION 0.1.0.0 LANGUAGES C CXX)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

add_subdirectory(src/Thunks)

if(BUILD_TESTING)
  include(CTest)
  enable_testing()
  add_subdirectory(src/YY-Thunks.UnitTest)
endif()
