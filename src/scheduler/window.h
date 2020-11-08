#ifndef WINDOW_H
#define WINDOW_H

#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

namespace general::scheduler {

class window {
public:
    struct window_info {
        int m_interval;
        ptime m_start_date_time;
        ptime m_end_date_time;
        bool is_expired;
        bool is_valid;
    };

    window(const window_info& wi, const std::string& task_id);
    window(const window& w) = default;
    window(window&& w) = default;
    window &operator=(const window& w) = default;
    window &operator=(window&& w) = default;

private:
    window_info m_window_info;
    std::string m_task_id;
};

}

#endif