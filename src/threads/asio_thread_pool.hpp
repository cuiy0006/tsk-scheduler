#ifndef THREAD_POOL_H
#define THREAD_POOL_H

// system
#include <memory>
#include <thread>
#include <vector>

// boost
#include <boost/asio.hpp>
#include <boost/log/trivial.hpp>

namespace general::scheduler {

class asio_thread_pool
{
public:
    asio_thread_pool(int thread_num = std::thread::hardware_concurrency())
        : m_work_ptr(new boost::asio::io_service::work(m_io_service))
    {
        for (int i = 0; i < thread_num; ++i)
        {
            m_threads.emplace_back([this] () { 
                BOOST_LOG_TRIVIAL(info) << "Initiating thread: " << std::this_thread::get_id();
                m_io_service.run(); 
            });
        }
    }

    asio_thread_pool(const asio_thread_pool &) = delete;
    asio_thread_pool &operator=(const asio_thread_pool &) = delete;

    boost::asio::io_service &get_io_service()
    {
        return m_io_service;
    }

    void stop()
    {
        m_work_ptr.reset();
        for (auto &t: m_threads)
        {
            t.join();
        }        
    }
private:
    boost::asio::io_service m_io_service;
    std::unique_ptr<boost::asio::io_service::work> m_work_ptr;
    std::vector<std::thread> m_threads;
};

}

#endif /* THREAD_POOL_H */
