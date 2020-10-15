add_executable(all_unit_tests 
                all_unit_tests.t.cpp
                ../../src/config.cpp
                ../../src/data-models/task.cpp)

target_link_libraries(all_unit_tests gtest_main Boost::date_time)

target_include_directories(all_unit_tests PRIVATE 
    ../../src
    ../../src/data-models)


add_test(NAME all_unit_tests COMMAND all_unit_tests)