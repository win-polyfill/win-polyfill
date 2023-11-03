cmake_minimum_required (VERSION 3.1)
message(STATUS "Host:${CMAKE_HOST_SYSTEM_NAME}; Guest:${CMAKE_SYSTEM_NAME}; File:${CPK_TEST_FILE} CPK_TEST_RESULT_VARIABLE:${CPK_TEST_RESULT_VARIABLE}")

macro(temp_name fname)
  if(${ARGC} GREATER 1) # Have to escape ARGC to correctly compare
    set(_base ${ARGV1})
  else(${ARGC} GREATER 1)
    set(_base ".cmake-tmp")
  endif(${ARGC} GREATER 1)
  set(_counter 0)
  while(EXISTS "${_base}${_counter}")
    math(EXPR _counter "${_counter} + 1")
  endwhile(EXISTS "${_base}${_counter}")
  set(${fname} "${_base}${_counter}")
endmacro(temp_name)

if (CMAKE_SYSTEM_NAME STREQUAL CMAKE_HOST_SYSTEM_NAME)
  message(STATUS "Testing natively on ${CMAKE_SYSTEM_NAME}")
  set(CPK_TEST_FINAL_CMD ${CPK_TEST_FILE})
  if (NOT "${CPK_TEST_COMMAND_ARGS}" STREQUAL "")
    list(APPEND CPK_TEST_FINAL_CMD ${CPK_TEST_COMMAND_ARGS})
  endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "IOS")
  message(STATUS "Testing on cross IOS environment")

  set(IOS_DECICE_ID $ENV{IOS_DECICE_ID})
  get_filename_component(CPK_TEST_IOS_INSTALL_BUNDLE ${CPK_TEST_CMD} DIRECTORY)
  message("CPK_TEST_IOS_INSTALL_BUNDLE ${CPK_TEST_IOS_INSTALL_BUNDLE}")
  set(CPK_TEST_IOS_INSTALL_SCRIPT "${CMAKE_CURRENT_LIST_DIR}/scripts/install-ios.sh")
  set(CPK_TEST_IOS_INSTALL_COMMAND bash -l -c "sh ${CPK_TEST_IOS_INSTALL_SCRIPT} ${IOS_DECICE_ID} ${CPK_TEST_IOS_INSTALL_BUNDLE}" )

  execute_process(COMMAND ${CPK_TEST_IOS_INSTALL_COMMAND}
    TIMEOUT 30000
    RESULT_VARIABLE IOS_INSTALL_RETURN_VAL
  )
  if (NOT(IOS_INSTALL_RETURN_VAL EQUAL 0))
    message (FATAL_ERROR "Installing ${CPK_TEST_IOS_INSTALL_COMMAND} failed with:\n${IOS_INSTALL_RETURN_VAL}")
  endif()

  set(CPK_TEST_FINAL_CMD xcrun simctl launch --console ${IOS_DECICE_ID} com.example)
elseif(CMAKE_SYSTEM_NAME STREQUAL "VxWorks")
  message(STATUS "Testing on cross VxWorks environment")

  set(WIND_BASE $ENV{WIND_BASE})
  set(CPK_TEST_VXWROKS_INSTALL_SCRIPT "${CMAKE_CURRENT_LIST_DIR}/scripts/install-vxworks.bat")
    temp_name(CPK_TEST_VXWROKS_GDB_INSTALL_SCRIPT ".cmake.vxworks/gdb")
    file(WRITE ${CPK_TEST_VXWROKS_GDB_INSTALL_SCRIPT} "target wtx target\nload ${CPK_TEST_CMD}\nq\n")

    set(CPK_TEST_VXWORKS_INSTALL_COMMAND
      gdbi86 --command "${CPK_TEST_VXWROKS_GDB_INSTALL_SCRIPT}"
    )

    execute_process (COMMAND ${CPK_TEST_VXWORKS_INSTALL_COMMAND}
      TIMEOUT 10000
      RESULT_VARIABLE VXWORKS_INSTALL_RETURN_VAL
    )
    if (NOT(VXWORKS_INSTALL_RETURN_VAL EQUAL 0))
      message (FATAL_ERROR "Installing ${CPK_TEST_VXWORKS_INSTALL_COMMAND} failed with:\n${VXWORKS_INSTALL_RETURN_VAL}")
    endif ()

    temp_name(CPK_TEST_VXWROKS_WINDSH_RUN_SCRIPT ".cmake.vxworks/windsh")
    file(WRITE ${CPK_TEST_VXWROKS_WINDSH_RUN_SCRIPT} "main()\nexit\n")

    set(CPK_TEST_FINAL_CMD windsh target -poll 1 -q -s "${CPK_TEST_VXWROKS_WINDSH_RUN_SCRIPT}")
    # TODO: make sure the CPK_TEST_FINAL_CMD return the valid value
endif()

message ("Running test ${CPK_TEST_FINAL_CMD}")
execute_process(
  COMMAND ${CPK_TEST_FINAL_CMD}
  OUTPUT_VARIABLE CPK_TEST_OUTPUT_TEXT
  ERROR_VARIABLE CPK_TEST_ERROR_TEXT
  RESULT_VARIABLE CPK_TEST_RESULT
)

set(CPK_TEST_RESULT_STRING "${CPK_TEST_OUTPUT_TEXT}\nstderr:${CPK_TEST_ERROR_TEXT}")

if (CPK_TEST_RESULT STREQUAL CPK_TEST_RESULT_VARIABLE)
  message ("Tests passed with:\n${CPK_TEST_RESULT_STRING}")
else ()
  message (FATAL_ERROR "Tests failed with ${CPK_TEST_RESULT} not equal expected:${CPK_TEST_RESULT_VARIABLE}\n${CPK_TEST_RESULT_STRING}")
endif()
