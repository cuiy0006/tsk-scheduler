// boost
#include <boost/log/trivial.hpp>

#include "scheduler_engine.h"

namespace general::scheduler {

scheduler_engine::scheduler_engine(boost::asio::io_service& io_service, config& config)
    : m_io_service(io_service),
      m_config(config) {

};

void scheduler_engine::add_tasks(tasks_map_t& tasks_map) {
    for(auto it = tasks_map.begin(); it != tasks_map.end(); ++it) {
        if(m_tasks_map.find(it->first) != tasks_map.end()){
            BOOST_LOG_TRIVIAL(debug) << "Adding modified task: " << it->second;

            m_tasks_map.emplace(it->first, std::move(it->second));
        } else {
            BOOST_LOG_TRIVIAL(debug) << "Adding new task: " << it->second;

            m_tasks_map[it->first] = std::move(it->second);
        }
    }
}

}