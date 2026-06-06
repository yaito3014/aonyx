#include "session.hpp"
#include "../helper/convert.hpp"

void session::run()
{
    read();
}

void session::read()
{
    auto self = shared_from_this();

    boost::beast::http::async_read(
        socket_,
        buffer_,
        req_,
        [self](boost::beast::error_code ec, std::size_t)
        {
            if (ec)
                return;

            self->handle_request();
        });
}

void session::handle_request()
{
    // TODO
    const auto req = aonyx::impl::http::helper::request::convert(req_);
    auto res = std::make_shared<boost::beast::http::response<boost::beast::http::string_body>>(
        aonyx::impl::http::helper::response::convert(router_.route(req)));

    auto self = shared_from_this();

    boost::beast::http::async_write(
        socket_,
        *res,
        [self, res](boost::beast::error_code, std::size_t)
        {
            self->socket_.shutdown(
                boost::asio::ip::tcp::socket::shutdown_send);
        });
}
