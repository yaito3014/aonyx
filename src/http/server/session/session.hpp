#pragma once

#include <memory>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/http/string_body.hpp>
#include <aonyx/http/server/router.hpp>

class session : public std::enable_shared_from_this<session>
{
public:
    session(
        boost::asio::ip::tcp::socket socket,
        const aonyx::http::router &router)
        : socket_(std::move(socket)), router_(router)
    {
    }

    void run();

private:
    void read();
    void handle_request();

private:
    boost::asio::ip::tcp::socket socket_;
    boost::beast::flat_buffer buffer_;

    boost::beast::http::request<boost::beast::http::string_body> req_;
    const aonyx::http::router &router_;
};
