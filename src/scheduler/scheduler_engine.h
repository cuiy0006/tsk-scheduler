#ifndef SCHEDULER_ENGINE_H
#define SCHEDULER_ENGINE_H

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/trivial.hpp>

#include <unordered_map>

#include <config.h>
#include <data-models/task.h>

namespace general::scheduler {

class scheduler_engine {
public:
    scheduler_engine(boost::asio::io_service& io_service, config& config);
    void add_tasks(std::unordered_map<std::string, task>& tasks_map);

private:
    boost::asio::io_service& m_io_service;
    config& m_config;

    struct entry
    {

        entry(task& task)
            : m_task(std::move(task)){

        }

        ~entry(){
            stop_timers();
        }

        entry(const entry& e) = delete;
        entry(entry&& e) = delete;

        task m_task;
        std::unique_ptr<boost::asio::deadline_timer> start_timer_ptr;
        std::unique_ptr<boost::asio::deadline_timer> recurring_timer_ptr;

        void stop_timers() {
            BOOST_LOG_TRIVIAL(info) << "Stop timers for task: " << m_task.get_task_id();

            if(start_timer_ptr){
                start_timer_ptr->cancel();
            }

            if(recurring_timer_ptr){
                recurring_timer_ptr->cancel();
            }
        }
    };

    std::unordered_map<std::string, entry> m_entries_map;
    
};

}


#endif