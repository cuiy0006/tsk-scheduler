add_executable(all_unit_tests 
                all_unit_tests.t.cpp
                ../../src/config.cpp)

target_link_libraries(all_unit_tests gtest_main)

target_include_directories(all_unit_tests PRIVATE ../../include)

add_test(NAME all_unit_tests COMMAND all_unit_tests)