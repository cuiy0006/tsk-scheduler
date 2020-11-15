// boost
#include <boost/log/trivial.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "scheduler_engine.h"
#include <common/common.h>

namespace general::scheduler {

scheduler_engine::scheduler_engine(boost::asio::io_service& io_service, config& config)
    : m_io_service(io_service),
      m_config(config) {

};

void scheduler_engine::add_tasks(std::unordered_map<std::string, task>& tasks_map) {
    for(auto it = tasks_map.begin(); it != tasks_map.end(); ++it) {
        if(m_entries_map.find(it->first) != m_entries_map.end()){
            BOOST_LOG_TRIVIAL(info) << "Adding modified task: " << it->second;

            m_entries_map.at(it->first).m_task = it->second;
        } else {
            BOOST_LOG_TRIVIAL(info) << "Adding new task: " << it->second;

            m_entries_map.emplace(it->first, it->second);

            auto&& entry = m_entries_map.at(it->first);

            ptime now = microsec_clock::universal_time();
            auto td = entry.m_task.get_start_date_time() - now;
            if(td < milliseconds(0)) {
                td = milliseconds(0);
            }

            if(!entry.start_timer_ptr) {
                entry.start_timer_ptr = std::make_unique<boost::asio::deadline_timer>(m_io_service);
            }
            
            entry.start_timer_ptr->expires_from_now(td);
            entry.start_timer_ptr->async_wait([this, &entry](const boost::system::error_code& e) {
                this->setup_start_timer(entry);
            });
        }
    }
}

void scheduler_engine::setup_start_timer(entry& ent) {

}

void scheduler_engine::setup_recurring_timer(entry& ent) {

}



}