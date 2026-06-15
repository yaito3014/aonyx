#pragma once

#include "handler.hpp"
#include "call_handler.hpp"
#include <aonyx/http/request.hpp>

namespace aonyx
{
    namespace util
    {
        template <class F>
        inner_handler_t make_handler(F &&f)
        {
            return [fn = std::forward<F>(f)](const http::request &req, http::response &res, const util::inner_handler_params_t params)
            {
                return details::call_handler(fn, req, res, params);
            };
        }
    }
}
