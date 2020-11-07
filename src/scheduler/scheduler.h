#ifndef SCHEDULER_H
#define SCHEDULER_H

// boost
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <config.h>
#include <json_data_accessor.h>
#include "scheduler_engine.h"

namespace general::scheduler {

class scheduler {
public:
    scheduler(boost::asio::io_service& io_service, config& config);
    void run();
private:
    void refresh(bool first_run);
    void schedule_next_refresh();
    void get_tasks_map_callback(data_accessor::tasks_map_t& tasks_map);
    
    boost::asio::io_service& m_io_service;
    config& m_config;
    boost::asio::deadline_timer m_refresh_timer;
    json_data_accessor m_data_accessor;
    scheduler_engine m_scheduler_engine;

};

}

#endif