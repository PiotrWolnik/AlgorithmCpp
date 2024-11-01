enable_testing()

set(TEST_SOURCE_FILES
    sample.cpp
)

add_executable(PSO_Tests ${TEST_SOURCE_FILES})
target_link_libraries(PSO_Tests PRIVATE GTest::gtest_main GTest::gmock_main)
target_compile_features(PSO_Tests PRIVATE cxx_std_20)

include(GoogleTest)
gtest_discover_tests(PSO_Tests)
