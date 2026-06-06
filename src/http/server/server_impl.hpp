#pragma once

#include "aonyx/http/server.hpp"
#include <boost/asio/ip/tcp.hpp>
#include <aonyx/http/router.hpp>

namespace aonyx::http
{
    class server::server_impl
    {
    public:
        server_impl(unsigned short port) : io_(),
                                           acceptor_(
                                               io_,
                                               {boost::asio::ip::tcp::v4(),
                                                port}) {}
        void run();
        aonyx::http::router &router();

    private:
        void accept();

    private:
        boost::asio::io_context io_;
        boost::asio::ip::tcp::acceptor acceptor_;
        aonyx::http::router router_;
    };
}
