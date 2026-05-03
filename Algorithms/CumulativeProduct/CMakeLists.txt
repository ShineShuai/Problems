get_filename_component(TARGET_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Gather all .hpp files in this directory
file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# --- Library (for tests to link against) ---
foreach(header ${HEADERS})
    get_filename_component(lib_name ${header} NAME_WE)
    add_library(${lib_name}Lib ${lib_name}.cpp ${lib_name}.hpp)
    target_include_directories(${lib_name}Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 
endforeach(header)

# Create executable
file(GLOB MAINFILES "${CMAKE_CURRENT_SOURCE_DIR}/*_Main.cpp")
foreach(mainfile ${MAINFILES})
    get_filename_component(target_name ${mainfile} NAME_WE)
    # filter target_name to remove "Main" suffix if present
    string(REPLACE "_Main" "" target_name ${target_name})
    add_executable(${target_name} ${mainfile})
    target_link_libraries(${target_name} PRIVATE ${target_name}Lib)

    # Output binary to local build/ folder
    set_target_properties(${target_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/build/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/build/release"
    )
endforeach(mainfile)
