get_cmake_property(_variableNames_begin VARIABLES)
# message(STATUS "${_variableNames_begin}")
if ("${FIND_PACKAGE_MESSAGE_DETAILS_${THIS_PACKAGE_NAME}}" STREQUAL "")
  set(CPK_SETUP_DUMP_END_VARIABLES_SHOW_MESSAGE ON)
else()
  set(CPK_SETUP_DUMP_END_VARIABLES_SHOW_MESSAGE OFF)
endif()

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE PARENT_SCOPE)
      endif()
    endif()
  endforeach()
endmacro()

# MAIN is this is the main library
# TARGET_NAME the object filename main part if present.
# TARGET_TYPE 'shared' 'static' 'executable' 'interface', default to 'interface'
# TARGET_LIBRARY_PREFIX 'lib', default to CMAKE_SHARED_LIBRARY_PREFIX or CMAKE_STATIC_LIBRARY_PREFIX according to TARGET_TYPE
# TARGET_NAME_SUFFIX 'd', default to '', may setting to d or _debug or something alike to install both debug/release version binary at the same folder
# interface means header only library

# TARGET_COMPILE_DEFINITIONS such as "-DENABLE_SOMETHING=1"
# TARGET_LINK_LIBRARIES such as "-lglib-2.0"
function(cpk_setup_target CPK_SETUP_NAME)
  # Prepare the args
  cmake_parse_arguments(CPK_SETUP "MAIN" "TARGET_TYPE;TARGET_NAME;TARGET_LIBRARY_PREFIX;TARGET_NAME_SUFFIX" "TARGET_COMPILE_DEFINITIONS;TARGET_LINK_LIBRARIES" "${ARGN}")

  if ("${CPK_SETUP_TARGET_NAME}" STREQUAL "")
    set(CPK_SETUP_TARGET_NAME "${CPK_SETUP_NAME}")
  endif()
  if ("${CPK_SETUP_TARGET_TYPE}" STREQUAL "")
    set(CPK_SETUP_TARGET_TYPE "interface")
  endif()

  # Prepare target name and sub package name
  set(TARGET_NAME ${THIS_PACKAGE_NAME}::${CPK_SETUP_TARGET_NAME})
  set(SUB_PACKAGE_NAME ${THIS_PACKAGE_NAME}_${CPK_SETUP_TARGET_NAME})

  message(STATUS "${TARGET_NAME} setup with: CPK_SETUP_MAIN:${CPK_SETUP_MAIN} CPK_SETUP_TARGET_NAME:${CPK_SETUP_TARGET_NAME} CPK_SETUP_TARGET_TYPE:${CPK_SETUP_TARGET_TYPE}")

  # Prepare the IMPORTED_LOCATION
  if (CPK_SETUP_TARGET_TYPE STREQUAL "shared")
    if ("${CPK_SETUP_TARGET_LIBRARY_PREFIX}" STREQUAL "")
      set(CPK_SETUP_TARGET_LIBRARY_PREFIX "${CMAKE_IMPORT_LIBRARY_PREFIX}")
    endif()
    set(IMPORTED_LOCATION "${PACKAGE_PREFIX_DIR}/lib/${CPK_SETUP_TARGET_LIBRARY_PREFIX}${CPK_SETUP_TARGET_NAME}${CPK_SETUP_TARGET_NAME_SUFFIX}${CMAKE_IMPORT_LIBRARY_SUFFIX}")
  elseif (CPK_SETUP_TARGET_TYPE STREQUAL "static")
    if ("${CPK_SETUP_TARGET_LIBRARY_PREFIX}" STREQUAL "")
      set(CPK_SETUP_TARGET_LIBRARY_PREFIX "${CMAKE_STATIC_LIBRARY_PREFIX}")
    endif()
    set(IMPORTED_LOCATION "${PACKAGE_PREFIX_DIR}/lib/${CPK_SETUP_TARGET_LIBRARY_PREFIX}${CPK_SETUP_TARGET_NAME}${CPK_SETUP_TARGET_NAME_SUFFIX}${CMAKE_STATIC_LIBRARY_SUFFIX}")
  elseif (CPK_SETUP_TARGET_TYPESTREQUAL "executable")
    set(IMPORTED_LOCATION "${PACKAGE_PREFIX_DIR}/bin/${CPK_SETUP_TARGET_NAME}${CPK_SETUP_TARGET_NAME_SUFFIX}${CMAKE_EXECUTABLE_SUFFIX}")
  elseif (CPK_SETUP_TARGET_TYPE STREQUAL "interface")
    set(IMPORTED_LOCATION "")
  else()
    message(FATAL "None valid ${target_type} for ${TARGET_NAME} with ${CPK_SETUP_TARGET_NAME}")
  endif()

  set(INTERFACE_COMPILE_DEFINITIONS "${CPK_SETUP_TARGET_COMPILE_DEFINITIONS}")
  set(INTERFACE_LINK_LIBRARIES "${CPK_SETP_TARGET_LINK_LIBRARIES}")
  set(INTERFACE_INCLUDE_DIRECTORIES "${PACKAGE_PREFIX_DIR}/include/")
  if (EXISTS "${PACKAGE_PREFIX_DIR}/include/${THIS_PACKAGE_NAME}/")
    list(APPEND INTERFACE_INCLUDE_DIRECTORIES "${PACKAGE_PREFIX_DIR}/include/${THIS_PACKAGE_NAME}/")
  endif()
  if (NOT ("${CPK_SETUP_TARGET_TYPE}" STREQUAL "interface"))
    set(_IMPORT_CHECK_FILES_FOR_${TARGET_NAME} ${IMPORTED_LOCATION} PARENT_SCOPE)
    list(APPEND _IMPORT_CHECK_TARGETS "${TARGET_NAME}")
    list(APPEND INTERFACE_LINK_LIBRARIES "${IMPORTED_LOCATION}")
  endif()

  set_target_properties(${TARGET_NAME} PROPERTIES
    INTERFACE_COMPILE_DEFINITIONS "${INTERFACE_COMPILE_DEFINITIONS}"
    INTERFACE_INCLUDE_DIRECTORIES "${INTERFACE_INCLUDE_DIRECTORIES}"
    INTERFACE_LINK_LIBRARIES "${INTERFACE_LINK_LIBRARIES}"
  )

  if ("${CPK_SETUP_MAIN}" STREQUAL "TRUE")
    set(${THIS_PACKAGE_NAME}_LIBRARY "${IMPORTED_LOCATION}" PARENT_SCOPE)
    set(${THIS_PACKAGE_NAME}_LIBRARIES "${IMPORTED_LOCATION}" PARENT_SCOPE)
    set(${THIS_PACKAGE_NAME}_INCLUDE_DIR "${INTERFACE_INCLUDE_DIRECTORIES}" PARENT_SCOPE)
    set(${THIS_PACKAGE_NAME}_INCLUDE_DIRS "${INTERFACE_INCLUDE_DIRECTORIES}" PARENT_SCOPE)
    if (NOT ("${CPK_SETUP_TARGET_TYPE}" STREQUAL "interface"))
      list(APPEND _IMPORT_CHECK_REQUIRED_VARS
      "${THIS_PACKAGE_NAME}_LIBRARY"
      "${THIS_PACKAGE_NAME}_LIBRARIES"
      )
    endif()
    list(APPEND _IMPORT_CHECK_REQUIRED_VARS
      "${THIS_PACKAGE_NAME}_INCLUDE_DIR"
      "${THIS_PACKAGE_NAME}_INCLUDE_DIRS"
    )
  endif()

  set(${SUB_PACKAGE_NAME}_LIBRARY "${IMPORTED_LOCATION}" PARENT_SCOPE)
  set(${SUB_PACKAGE_NAME}_LIBRARIES "${IMPORTED_LOCATION}" PARENT_SCOPE)
  set(${SUB_PACKAGE_NAME}_INCLUDE_DIR "${INTERFACE_INCLUDE_DIRECTORIES}" PARENT_SCOPE)
  set(${SUB_PACKAGE_NAME}_INCLUDE_DIRS "${INTERFACE_INCLUDE_DIRECTORIES}" PARENT_SCOPE)
  set(${SUB_PACKAGE_NAME}_FOUND ON PARENT_SCOPE)
  if (NOT ("${CPK_SETUP_TARGET_TYPE}" STREQUAL "interface"))
    list(APPEND _IMPORT_CHECK_REQUIRED_VARS
      "${SUB_PACKAGE_NAME}_LIBRARY"
      "${SUB_PACKAGE_NAME}_LIBRARIES"
    )
  endif()
  list(APPEND _IMPORT_CHECK_REQUIRED_VARS
    "${SUB_PACKAGE_NAME}_INCLUDE_DIR"
    "${SUB_PACKAGE_NAME}_INCLUDE_DIRS"
    "${SUB_PACKAGE_NAME}_FOUND"
  )

  set(_IMPORT_CHECK_TARGETS "${_IMPORT_CHECK_TARGETS}" PARENT_SCOPE)
  set(_IMPORT_CHECK_REQUIRED_VARS "${_IMPORT_CHECK_REQUIRED_VARS}" PARENT_SCOPE)
endfunction(cpk_setup_target)

function(cpk_dump_vars)
  get_cmake_property(_variableNames_end VARIABLES)
  list(REMOVE_ITEM _variableNames_end
    ${_variableNames_begin}
    ARGC ARGN ARGV
    CMAKE_CURRENT_FUNCTION CMAKE_CURRENT_FUNCTION_LIST_DIR CMAKE_CURRENT_FUNCTION_LIST_FILE CMAKE_CURRENT_FUNCTION_LIST_LINE

    _variableNames_begin
    THIS_PACKAGE_NAME FIND_PACKAGE_MESSAGE_DETAILS_${THIS_PACKAGE_NAME}
    PACKAGE_PREFIX_DIR
    CPK_SETUP_DUMP_END_VARIABLES_SHOW_MESSAGE
  )
  if (CPK_SETUP_DUMP_END_VARIABLES_SHOW_MESSAGE)
    message(STATUS "Found ${THIS_PACKAGE_NAME} vars: ${_variableNames_end}")
    message(STATUS "Found ${THIS_PACKAGE_NAME} at ${PACKAGE_PREFIX_DIR}")
  endif()
  unset(_variableNames_begin PARENT_SCOPE)
  unset(THIS_PACKAGE_NAME PARENT_SCOPE)
  unset(PACKAGE_PREFIX_DIR PARENT_SCOPE)
  unset(CPK_SETUP_DUMP_END_VARIABLES_SHOW_MESSAGE PARENT_SCOPE)
endfunction(cpk_dump_vars)

include(FindPackageHandleStandardArgs)
macro(cpk_config_finalize)
  set("${THIS_PACKAGE_NAME}_FOUND" ON)
  list(APPEND _IMPORT_CHECK_REQUIRED_VARS ${THIS_PACKAGE_NAME}_FOUND)

  # Loop over all imported files and verify that they actually exist
  foreach(target ${_IMPORT_CHECK_TARGETS} )
    foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
      if(NOT EXISTS "${file}")
        message(FATAL_ERROR "The imported target \"${target}\" references the file
    \"${file}\"
  but this file does not exist.  Possible reasons include:
  * The file was deleted, renamed, or moved to another location.
  * An install or uninstall procedure did not complete successfully.
  * The installation package was faulty and contained
    \"${CMAKE_CURRENT_LIST_FILE}\"
  but not all the files it references.
  ")
      endif()
    endforeach()
    unset(_IMPORT_CHECK_FILES_FOR_${target})
  endforeach()
  unset(target)
  unset(file)
  unset(_IMPORT_CHECK_TARGETS)

  foreach(var_name ${_IMPORT_CHECK_REQUIRED_VARS})
    string(TOUPPER "${var_name}" var_name_upper)
    set(${var_name_upper} ${${var_name}})
    list(APPEND _IMPORT_CHECK_REQUIRED_VARS "${var_name_upper}")
  endforeach(var_name)
  unset(var_name)
  unset(var_name_upper)

  # Check if require components are found
  check_required_components(${THIS_PACKAGE_NAME})
  unset(comp)
  find_package_handle_standard_args(${THIS_PACKAGE_NAME}
    REQUIRED_VARS ${_IMPORT_CHECK_REQUIRED_VARS}
    VERSION_VAR ${THIS_PACKAGE_NAME}_VERSION
  )
  unset(_IMPORT_CHECK_REQUIRED_VARS)
endmacro(cpk_config_finalize)
