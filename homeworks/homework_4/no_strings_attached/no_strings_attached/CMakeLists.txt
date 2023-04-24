add_library(string_split string_split.cpp)
target_link_libraries(string_split PUBLIC cxx_setup)

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)
    add_executable(test_string_split test_string_split.cpp)
    target_link_libraries(test_string_split PRIVATE string_split GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(test_string_split)
endif()