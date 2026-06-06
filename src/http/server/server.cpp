#include <aonyx/http/server.hpp>
#include "server_impl.hpp"

namespace aonyx::http
{

    server::server() : pimpl_(std::make_unique<server_impl>(8080))
    {
    }

    server::server(unsigned short port) : pimpl_(std::make_unique<server_impl>(port))
    {
    }

    server::~server()
    {
    }

    void server::run()
    {
        pimpl_->run();
    }

    router &server::router()
    {
        return pimpl_->router();
    }

} // namespace aonyx::http
