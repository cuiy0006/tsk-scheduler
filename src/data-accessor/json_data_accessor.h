#ifndef JSON_DATA_ACCESSOR_H
#define JSON_DATA_ACCESSOR_H

#include <unordered_map>
#include <functional>
#include <task.h>
#include <boost/asio.hpp>
#include "data_accessor.h"
#include "json.hpp"

namespace general::scheduler {

using json = nlohmann::json;

class json_data_accessor : public data_accessor {

public:
    json_data_accessor(boost::asio::io_service& io_service, config& config);

    void get_tasks_async(get_tasks_callback cb, bool all);

    void get_tasks(tasks_map_t& tasks_map, bool all);

};

}

#endif