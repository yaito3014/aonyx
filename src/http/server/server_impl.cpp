#include "server_impl.hpp"
#include "../session/session.hpp"
#include <boost/beast/http/error.hpp>
#include <boost/beast/http.hpp>

namespace aonyx::http
{
    void server::server_impl::run()
    {
        accept();
        io_.run();
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
