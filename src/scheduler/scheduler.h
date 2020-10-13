#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <config.h>

namespace general::scheduler {

class scheduler {
public:
    scheduler(boost::asio::io_service& io_service, config& config);
    void run();
private:
    void refresh();
    void schedule_next_refresh();
    boost::asio::io_service& m_io_service;
    config& m_config;
    boost::asio::deadline_timer m_refresh_timer;

};

}

#endif