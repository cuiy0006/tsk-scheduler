add_executable(scheduler 
    tsk_scheduler.m.cpp
    config.cpp
    scheduler/scheduler.cpp
    data-models/task.cpp
    data-accessor/json_data_accessor.cpp
    data-accessor/data_accessor.cpp)

target_link_libraries(scheduler 
    ${Boost_SYSTEM_LIBRARY} 
    ${CMAKE_THREAD_LIBS_INIT}
    Boost::date_time
    Boost::log_setup
    Boost::log)

target_include_directories(scheduler PRIVATE 
    .
    data-accessor
    data-models
    scheduler
    threads)

install (TARGETS scheduler
    DESTINATION ${PROJECT_BINARY_DIR}/bin)