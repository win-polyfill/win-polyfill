include(CMakePackageConfigHelpers)

function(cpk_install_pkg_config)
  string(TOLOWER ${CMAKE_PROJECT_NAME} CMAKE_PROJECT_NAME_LOWER)
  set(INCLUDE_INSTALL_DIR include/)
  set(CMAKE_LIB_INSTALL_DIR lib/cmake/${CMAKE_PROJECT_NAME}/)
  set(PKGCONFIG_LIB_INSTALL_DIR lib/pkgconfig/)
  set(SYSCONFIG_INSTALL_DIR etc/${CMAKE_PROJECT_NAME}/)
  configure_package_config_file(
    ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/${CMAKE_PROJECT_NAME}Config.in.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_LIB_INSTALL_DIR}
    PATH_VARS INCLUDE_INSTALL_DIR SYSCONFIG_INSTALL_DIR
  )
  configure_file(
    ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/${CMAKE_PROJECT_NAME_LOWER}.pc.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME_LOWER}.pc @ONLY
  )
  write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
    VERSION ${CMAKE_PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
  )
  install(
    FILES
      ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/ConfigHelpers.cmake
      ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
      ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_LIB_INSTALL_DIR}
  )
  install(
    FILES
      ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME_LOWER}.pc
    DESTINATION ${PKGCONFIG_LIB_INSTALL_DIR}
  )
endfunction(cpk_install_pkg_config)

function(cpk_add_test)
  cmake_parse_arguments(CPK_TEST "" "NAME;WORKING_DIRECTORY" "SOURCES;RESULT_VARIABLE;INCLUDE_DIRECTORIES;LINK_LIBRARIES;COMPILE_DEFINITIONS;COMMAND_ARGS" "${ARGN}")
  add_executable(${CPK_TEST_NAME} ${CPK_TEST_SOURCES})
  target_include_directories(${CPK_TEST_NAME} PRIVATE ${CPK_TEST_INCLUDE_DIRECTORIES})
  target_link_libraries(${CPK_TEST_NAME} ${CPK_TEST_LINK_LIBRARIES})
  target_compile_definitions(${CPK_TEST_NAME} PRIVATE ${CPK_TEST_COMPILE_DEFINITIONS})

  set(CPK_RUN_TEST_PATH "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/CpkRunTest.cmake")
  if (NOT DEFINED CPK_TEST_RESULT_VARIABLE)
    set(CPK_TEST_RESULT_VARIABLE "0")
  endif()

  add_test(
    NAME ${CPK_TEST_NAME}
    WORKING_DIRECTORY ${CPK_TEST_WORKING_DIRECTORY}
    COMMAND
      "${CMAKE_COMMAND}"
      "-DCMAKE_HOST_SYSTEM_NAME:STRING=${CMAKE_HOST_SYSTEM_NAME}"
      "-DCMAKE_SYSTEM_NAME:STRING=${CMAKE_SYSTEM_NAME}"
      "-DCPK_TEST_FILE:FILEPATH=$<TARGET_FILE:${CPK_TEST_NAME}>"
      "-DCPK_TEST_RESULT_VARIABLE:STRING=${CPK_TEST_RESULT_VARIABLE}"
      "-DCPK_TEST_COMMAND_ARGS:STRING=${CPK_TEST_COMMAND_ARGS}"
      "-P" "${CPK_RUN_TEST_PATH}"
  )
endfunction(cpk_add_test)

function(cpk_install_public_files CPK_TARGET)
  set(optionsArgs "")
  set(oneValueArgs "DESTINATION_DIR;SOURCE_DIR")
  cmake_parse_arguments(CPK "${optionsArgs}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
  get_target_property(CPK_TARGET_PUBLIC_FILES ${CPK_TARGET} CPK_PUBLIC_FILES)
  if (NOT CPK_TARGET_PUBLIC_FILES)
    message(WARNING "There is no public headers for ${CPK_TARGET}:${CPK_TARGET_PUBLIC_FILES}")
    return()
  endif()
  if (NOT CPK_DESTINATION_DIR)
    message(WARNING "DESTINATION_DIR not specified for ${CPK_TARGET} when calling cpk_install_public_files")
    return()
  endif()
  if (NOT CPK_SOURCE_DIR)
    message(WARNING "SOURCE_DIR not specified for ${CPK_TARGET} when calling cpk_install_public_files")
    return()
  endif()
  foreach(CPK_FILE ${CPK_TARGET_PUBLIC_FILES})
      get_filename_component(CPK_DIR ${CPK_FILE} DIRECTORY)
      file(RELATIVE_PATH CPK_DIR_RELATIVE ${CPK_SOURCE_DIR} ${CPK_DIR})
      install(FILES ${CPK_FILE} DESTINATION ${CPK_DESTINATION_DIR}/${CPK_DIR_RELATIVE})
  endforeach()
endfunction(cpk_install_public_files)
