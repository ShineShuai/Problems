set(TARGET_NAME cpptests)
# Single test executable for ALL tests
add_executable(${TARGET_NAME} TestsMain.cpp)

# Link Boost.UT — try lowercase if the alias doesn't work
if(TARGET boost::ut)
    target_link_libraries(${TARGET_NAME} PRIVATE boost::ut)
elseif(TARGET Boost::ut)
    target_link_libraries(${TARGET_NAME} PRIVATE Boost::ut)
else()
    message(FATAL_ERROR "Boost.UT target not found. Check FetchContent.")
endif()

# Auto-discover all *.test.cpp files recursively
file(GLOB_RECURSE TEST_FILES
    "${CMAKE_SOURCE_DIR}/Algorithms/**/*.test.cpp"
    "${CMAKE_SOURCE_DIR}/Probabilities/**/*.test.cpp"
)

# Add all discovered test files
target_sources(${TARGET_NAME} PRIVATE ${TEST_FILES})

# For each test file, link its library
foreach(test_file ${TEST_FILES})
    get_filename_component(test_name ${test_file} NAME_WE)
    set(lib_name ${test_name}Lib)
    
    # Check if the library target named with lib_name exists before linking
    if(TARGET ${lib_name})
        target_link_libraries(${TARGET_NAME} PRIVATE ${lib_name})
    endif()
endforeach()

# Output binary to build/tests/
set_target_properties(${TARGET_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)

# Register with CTest (once, not in the loop!)
add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})