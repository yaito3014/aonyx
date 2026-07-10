#pragma once

#include <memory>
#include <aonyx/http/server/router.hpp>

namespace aonyx
{
    namespace http
    {
        class server
        {
        public:
            server();
            server(unsigned short port);
            ~server();

            void run();
            http::router &router();

        private:
            class server_impl;
            std::unique_ptr<server_impl> pimpl_;
        };
    }
}
