#pragma once

#include <exception>

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
                try
                {
                    auto result = details::call_handler(fn, req, res, params);

                    if (not result)
                    {
                        res.status = 500;
                        res.body = "500 Internal Server Error";
                        res.headers["Content-Type"] = "text/html";

                        return;
                    }

                    return;
                }
                catch (const std::invalid_argument &)
                {
                    res.status = 400;
                    res.body = "400 Bad Request";
                    res.headers["Content-Type"] = "text/html";

                    return;
                }
                catch (const std::out_of_range &)
                {
                    res.status = 400;
                    res.body = "400 Bad Request";
                    res.headers["Content-Type"] = "text/html";

                    return;
                }
            };
        }
    }
}
