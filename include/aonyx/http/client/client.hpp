#pragma once

#include <string>
#include <string_view>
#include <cstdint>
#include <unordered_map>

#include <aonyx/http/response.hpp>
#include <aonyx/http/method.hpp>
#include <aonyx/http/headers.hpp>

namespace aonyx
{
    namespace http
    {
        namespace client
        {
            aonyx::http::response fetch(
                const std::string_view url,
                const aonyx::http::method method,
                const std::string_view body = "",
                const http::headers headers = {});
            aonyx::http::response fetch(
                const std::string_view host,
                const std::string_view port,
                const std::string_view target,
                const aonyx::http::method method = aonyx::http::method::get,
                const std::string_view body = "",
                const http::headers headers = {});

            aonyx::http::response get(
                const std::string_view url,
                const std::string_view body = "",
                const http::headers headers = {});
            aonyx::http::response post(
                const std::string_view url,
                const std::string_view body = "",
                const http::headers headers = {});
            aonyx::http::response put(
                const std::string_view url,
                const std::string_view body = "",
                const http::headers headers = {});
            aonyx::http::response delete_(
                const std::string_view url,
                const std::string_view body = "",
                const http::headers headers = {});
        }
    }
}
