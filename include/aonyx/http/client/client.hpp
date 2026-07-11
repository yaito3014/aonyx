#pragma once

#include <string>
#include <string_view>
#include <cstdint>
#include <unordered_map>

#include <aonyx/http/response.hpp>
#include <aonyx/http/method.hpp>

namespace aonyx
{
    namespace http
    {
        namespace client
        {
            aonyx::http::response fetch(const std::string_view url);
            aonyx::http::response fetch(
                const std::string_view host,
                const std::string_view port,
                const std::string_view target,
                const aonyx::http::method method = aonyx::http::method::get,
                const std::string_view body = "",
                const std::unordered_map<std::string, std::string> headers = {});
        }
    }
}
