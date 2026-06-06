#pragma once

#include <string>
#include <unordered_map>

#include "method.hpp"

namespace aonyx
{
    namespace http
    {
        struct request
        {
            http::method method;
            std::string path;
            std::string body;

            std::unordered_map<std::string, std::string> headers;
        };
    }
}
