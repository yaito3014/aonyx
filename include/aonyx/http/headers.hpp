#pragma once

#include <string>
#include <unordered_map>

namespace aonyx
{
    namespace http
    {
        using headers = std::unordered_map<std::string, std::string>;
    }
}
