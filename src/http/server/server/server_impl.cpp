#include "server_impl.hpp"
#include "../session/session.hpp"
#include <boost/beast/http/error.hpp>
#include <boost/beast/http.hpp>
#include <thread>
#include <vector>

namespace aonyx::http
{
    void server::server_impl::run()
    {
        accept();
        
        auto num_threads = std::thread::hardware_concurrency();
        if (num_threads == 0) num_threads = 4;

        std::vector<std::thread> threads;
        threads.reserve(num_threads - 1);

        for (unsigned i = 0; i < num_threads - 1; ++i)
        {
            threads.emplace_back([this] {
                io_.run();
            });
        }

        io_.run();

        for (auto& t : threads)
        {
            if (t.joinable()) t.join();
        }
    }

    void server::server_impl::accept()
    {
        acceptor_.async_accept(
            [this](boost::beast::error_code ec,
                   boost::asio::ip::tcp::socket socket)
            {
                if (!ec)
                {
                    std::make_shared<session>(
                        std::move(socket),
                        router_)
                        ->run();
                }

                this->accept();
            });
    }

    router &server::server_impl::router()
    {
        return router_;
    }
}
