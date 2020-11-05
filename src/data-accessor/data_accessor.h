#ifndef DATA_ACCESSOR_H
#define DATA_ACCESSOR_H
// system
#include <unordered_map>
#include <functional>

// boost
#include <boost/asio.hpp>

#include <config.h>
#include <task.h>

namespace general::scheduler {

class data_accessor {

public:
    data_accessor(boost::asio::io_service& io_service, config& config);

    virtual ~data_accessor();

    using tasks_map_t = std::unordered_map<std::string, task>;

    using get_tasks_callback = std::function<void(const tasks_map_t&)>;

    virtual void get_tasks_async(get_tasks_callback cb, bool all) = 0;

    virtual void get_tasks(tasks_map_t& tasks_map, bool all) = 0;

protected:
    boost::asio::io_service& m_io_service;

    config& m_config;

};

}

#endif