#pragma once

#include <string>

#include "headers.hpp"

namespace aonyx
{
    namespace http
    {
        struct response
        {
            int status;

            std::string body;

            headers headers;
        };
    }
}
