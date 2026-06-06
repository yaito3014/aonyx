#pragma once

#include <string>
#include <unordered_map>

namespace aonyx
{
    namespace http
    {
        struct response
        {
            int status;

            std::string body;

            std::unordered_map<std::string, std::string> headers;
        };
    }
}
