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

            setup_start_timer(entry);
        }
    }
}

void scheduler_engine::setup_start_timer(entry& ent) {

    ptime now = microsec_clock::universal_time();
    auto td = ent.m_task.get_start_date_time() - now;
    if(td < milliseconds(0)) {
        td = milliseconds(0);
    }

    if(!ent.start_timer_ptr) {
        ent.start_timer_ptr = std::make_unique<boost::asio::deadline_timer>(m_io_service);
    }

    BOOST_LOG_TRIVIAL(info) << "Setup up start timer for " << ent.m_task.get_task_id() << ", " << td.total_milliseconds() << " milliseconds from now";
    
    ent.start_timer_ptr->expires_from_now(td);
    ent.start_timer_ptr->async_wait([this, &ent](const boost::system::error_code& e) {
        this->setup_recurring_timer(ent);
    });

    
}

void scheduler_engine::setup_recurring_timer(entry& ent) {

    if(!ent.recurring_timer_ptr) {
        ent.recurring_timer_ptr = std::make_unique<boost::asio::deadline_timer>(m_io_service);
    }

    int interval = ent.m_task.get_interval();

    BOOST_LOG_TRIVIAL(info) << "Setup up recurring timer for " << ent.m_task.get_task_id() << ", " << interval << " seconds from now";

    ent.recurring_timer_ptr->expires_from_now(seconds(interval));
    ent.recurring_timer_ptr->async_wait([this, &ent](const boost::system::error_code& e) {
        this->dispatch(ent);
    });


}

void scheduler_engine::dispatch(entry& ent) {
    BOOST_LOG_TRIVIAL(info) << "Dispatching task for " << ent.m_task.get_task_id();

    setup_recurring_timer(ent);
}



}