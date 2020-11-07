#ifndef SCHEDULER_ENGINE_H
#define SCHEDULER_ENGINE_H

#include <boost/asio.hpp>

#include <unordered_map>

#include <config.h>
#include <data-models/task.h>

namespace general::scheduler {

class scheduler_engine {
public:
    using tasks_map_t = std::unordered_map<std::string, task>;
    scheduler_engine(boost::asio::io_service& io_service, config& config);
    void add_tasks(tasks_map_t& tasks_map);

private:
    tasks_map_t m_tasks_map;
    boost::asio::io_service& m_io_service;
    config& m_config;
};

}


#endif