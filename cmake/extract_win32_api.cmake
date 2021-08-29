# cmake process file to generate Win32 API list from sources
# Parameters
#   HEADER_FILE_BEGIN          - The path of source file to fill the begin section of the output header
#   HEADER_DIR                 - The directory contains the headers
#   HEADER_FILES               - The path of source files whose contents will be used to extract APIs.
#   HEADER_FILE_END            - The path of source file to fill the end section of the output header
#   OUTPUT_HEADER_FILE         - The path of header file to storaget API list.
#   OUTPUT_LIST_FILE           - The path of header file to include all headers
# Usage:
# cmake -DHEADER_FILE_BEGIN=begin.h -DHEADER_DIR=. -DHEADER_FILES=a.hpp;b.hpp  -DHEADER_FILE_END=end.h \
# -DOUTPUT_HEADER_FILE=api.h -DOUTPUT_LIST_FILE=header-list.h -P extract_win32_api.cmake

# { = \x7B

# reads source file contents as hex string
file(READ ${HEADER_FILE_BEGIN} headerBeginString)
string(RANDOM TMP_NAME)

set(OUTPUT_HEADER_FILE_TMP "${OUTPUT_HEADER_FILE}-${TMP_NAME}.tmp")
set(OUTPUT_LIST_FILE_TMP "${OUTPUT_LIST_FILE}-${TMP_NAME}.tmp")
file(WRITE ${OUTPUT_HEADER_FILE_TMP} "${headerBeginString}\n")
file(WRITE ${OUTPUT_LIST_FILE_TMP} "/* Auto generated include list */\n")
foreach(HEADER_FILE IN LISTS HEADER_FILES)
    file(READ ${HEADER_DIR}/${HEADER_FILE} headerString)
    string(REGEX MATCH "/\\* Extract begin open \\*/.*/\\* Extract begin close \\*/" EXTRACTED_BEGIN ${headerString})
    file(APPEND ${OUTPUT_HEADER_FILE_TMP} "${EXTRACTED_BEGIN}\n")
    string(REGEX MATCHALL "__DEFINE_THUNK[^\\{]*" EXTRACTED_APIS ${headerString})
    foreach(EXTRACTED_API IN LISTS EXTRACTED_APIS)
        # message(STATUS "EXTRACTED_API=${EXTRACTED_API}")
        file(APPEND ${OUTPUT_HEADER_FILE_TMP} "\n${EXTRACTED_API}\n")
    endforeach()
    string(REGEX MATCH "/\\* Extract end open \\*/.*/\\* Extract end close \\*/" EXTRACTED_END ${headerString})
    file(APPEND ${OUTPUT_HEADER_FILE_TMP} "${EXTRACTED_END}\n")
    file(APPEND ${OUTPUT_LIST_FILE_TMP} "#include \"${HEADER_FILE}\"\n")
endforeach()
file(READ ${HEADER_FILE_END} headerBeginString)
file(APPEND ${OUTPUT_HEADER_FILE_TMP} "${headerBeginString}")
file(RENAME ${OUTPUT_HEADER_FILE_TMP} ${OUTPUT_HEADER_FILE})
file(RENAME ${OUTPUT_LIST_FILE_TMP} ${OUTPUT_LIST_FILE})
