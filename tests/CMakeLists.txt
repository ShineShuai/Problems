set(TARGET_NAME cpptests)
# Single test executable for ALL tests
add_executable(${TARGET_NAME} Tests.cpp)

# Link Boost.UT — try lowercase if the alias doesn't work
# Use SYSTEM to suppress warnings from Boost.UT headers
if(TARGET boost::ut)
    target_link_libraries(${TARGET_NAME} PRIVATE SYSTEM boost::ut)
elseif(TARGET Boost::ut)
    target_link_libraries(${TARGET_NAME} PRIVATE SYSTEM Boost::ut)
else()
    message(FATAL_ERROR "Boost.UT target not found. Check FetchContent.")
endif()

# Auto-discover all *.test.cpp files recursively
file(GLOB_RECURSE TEST_FILES
    "${CMAKE_SOURCE_DIR}/**/*.test.cpp"
)

# Add all discovered test files
target_sources(${TARGET_NAME} PRIVATE ${TEST_FILES})

# Link every *Lib target and add include paths for test files
foreach(test_file ${TEST_FILES})
    get_filename_component(test_dir ${test_file} DIRECTORY)
    get_filename_component(file_dir ${test_dir} DIRECTORY)
    get_filename_component(folder_name ${file_dir} NAME)
    set(lib_name ${folder_name}Lib)
    
    if(TARGET ${lib_name})
        # SYSTEM the same style is used for the same target
        target_link_libraries(${TARGET_NAME} PRIVATE SYSTEM ${lib_name})
    endif()

    target_include_directories(${TARGET_NAME} PRIVATE "${file_dir}")
endforeach()

# Output binary to build/tests/
set_target_properties(${TARGET_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)

# Optional: register with CTest
add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})