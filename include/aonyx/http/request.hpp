#pragma once

#include <string>

#include "method.hpp"
#include "headers.hpp"

namespace aonyx
{
    namespace http
    {
        struct request
        {
            http::method method;
            std::string path;
            std::string body;

            headers headers;
        };
    }
}
