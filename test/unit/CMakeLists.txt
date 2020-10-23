add_executable(all_unit_tests 
                all_unit_tests.t.cpp
                ../../src/config.cpp
                ../../src/data-models/task.cpp
                ../../src/data-accessor/json_data_accessor.cpp
                ../../src/data-accessor/data_accessor.cpp)

target_link_libraries(all_unit_tests 
    gtest_main 
    Boost::date_time
    ${Boost_SYSTEM_LIBRARY})

target_include_directories(all_unit_tests PRIVATE 
    ../../src
    ../../src/data-models
    ../../src/data-accessor
    ../../src/threads)

install (TARGETS all_unit_tests
    DESTINATION ${PROJECT_BINARY_DIR}/bin)