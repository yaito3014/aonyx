#pragma once

#include <functional>
#include <aonyx/http/request.hpp>
#include <aonyx/http/response.hpp>

namespace aonyx
{
    namespace util
    {
        template <class... Args>
        using handler_t = std::function<void(const http::request &, http::response &, Args...)>;

        using inner_handler_params_t = std::vector<std::string>;
        using inner_handler_t = std::function<void(const http::request &, http::response &, const inner_handler_params_t)>;
    }
}
