#pragma once

#include <vector>
#include <string>
#include <tuple>
#include <utility>

#include <aonyx/http/request.hpp>
#include <aonyx/http/response.hpp>
#include "handler.hpp"
#include "param_from_string.hpp"
#include "handler_traits.hpp"

namespace aonyx
{
    namespace util
    {
        namespace details{
            template <class Fn, class... Args>
            void call_handler_impl(Fn fn, const http::request &req, http::response &res, Args... args)
            {
                return fn(req, res, args...);
            }
    
            template <class Fn, std::size_t... I>
            bool call_handler(Fn fn, const http::request &req, http::response &res, const inner_handler_params_t params, std::index_sequence<I...>)
            {
                call_handler_impl<
                Fn,
                std::tuple_element_t<I, handler_args_tuple_t<Fn>>...>(
                    fn,
                    req,
                    res,
                    (param_from_string<
                        std::tuple_element_t<I, handler_args_tuple_t<Fn>>>(params[I]))...);
                return true;
            }
    
            template <class Fn>
            bool call_handler(Fn fn, const http::request &req, http::response &res, const inner_handler_params_t params)
            {
                auto fn_args_size = util::handler_args_size_v<Fn>;

                if(fn_args_size != params.size()){
                    return false;
                }

                return call_handler(
                    fn,
                    req,
                    res,
                    params,
                    std::make_index_sequence<std::tuple_size<handler_args_tuple_t<Fn>>::value>{});
            }
        }
    }
}
