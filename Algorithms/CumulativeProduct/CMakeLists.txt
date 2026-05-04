get_filename_component(TARGET_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Gather all .hpp files in this directory
file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
# Exclude the main source file from the library
# (file containing main() is named after the folder: e.g., CumulativeProduct.cpp)
list(FILTER SOURCES EXCLUDE REGEX "${TARGET_NAME}\\.cpp$")

# --- Library (for tests to link against) ---
add_library(${TARGET_NAME}Lib ${SOURCES} ${HEADERS})
target_include_directories(${TARGET_NAME}Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 

# --- Executable (only if folder-named .cpp exists) ---
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${TARGET_NAME}.cpp")
    add_executable(${TARGET_NAME} ${TARGET_NAME}.cpp)
    target_link_libraries(${TARGET_NAME} PRIVATE ${TARGET_NAME}Lib)

    # Output binary to local build/ folder
    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/build/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/build/release"
    )
endif()