#include "asio_thread_pool.hpp"
#include "config.h"
#include "scheduler.h"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/phoenix.hpp>
#include <thread>

namespace logging = boost::log;
namespace keywords = boost::log::keywords;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;

BOOST_LOG_ATTRIBUTE_KEYWORD(thread_id, "ThreadID", attrs::current_thread_id::value_type)

void init_logging(general::scheduler::config& config);

int main(int argc, char *argv[])
{
    general::scheduler::config config;

    init_logging(config);

    BOOST_LOG_TRIVIAL(info) << "Starting task scheduler!";

    general::scheduler::asio_thread_pool pool(config.get_thread_pool_size());

    auto& io_service = pool.get_io_service();

    general::scheduler::scheduler scheduler(io_service, config);

    scheduler.run();

    io_service.run();
    
    return 0;
}

attrs::current_thread_id::value_type::native_type get_native_thread_id(
        logging::value_ref<attrs::current_thread_id::value_type,
        tag::thread_id> const& tid)
{
    if (tid)
        return tid->native_id();
    return 0;
}

void init_logging(general::scheduler::config& config) {
    logging::add_common_attributes();

    logging::add_file_log (
        keywords::file_name = config.get_log_path(),
        keywords::rotation_size = 10 * 1024 * 1024,
        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
        keywords::format = (
            expr::stream
                << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
                << "[" << logging::trivial::severity << "]"
                << "[" << boost::phoenix::bind(&get_native_thread_id, thread_id.or_none()) << "]"
                << "> " << expr::smessage
        ),
        keywords::auto_flush = true,
        keywords::open_mode = std::ios_base::app
    );

    auto log_level = (config.get_log_level() == "DEBUG") ? logging::trivial::debug : logging::trivial::info;

    logging::core::get()->set_filter
    (
        logging::trivial::severity >= log_level
    );
}