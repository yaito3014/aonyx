#pragma once

#include <functional>
#include <tuple>
#include <type_traits>

#include <aonyx/http/request.hpp>
#include <aonyx/http/response.hpp>

namespace aonyx
{
    namespace util
    {
        template <class F>
        struct handler_traits;

        template <class R, class... Args>
        struct handler_traits<R(const http::request &, http::response &, Args...)>
        {
            using result_type = R;
            using args_type_tuple = std::tuple<Args...>;
        };

        template <class R, class... Args>
        struct handler_traits<R (*)(const http::request &, http::response &, Args...)>
            : handler_traits<R(const http::request &, http::response &, Args...)>
        {
        };

        template <class R, class... Args>
        struct handler_traits<std::function<R(const http::request &, http::response &, Args...)>>
            : handler_traits<R(const http::request &, http::response &, Args...)>
        {
        };

        template <class F>
        using handler_result_t = typename handler_traits<F>::result_type;

        template <class F>
        using handler_args_tuple_t = typename handler_traits<F>::args_type_tuple;

        template <class F>
        struct handler_args_size : std::tuple_size<handler_args_tuple_t<F>> {};

        template <class F>
        static constexpr std::size_t handler_args_size_v = handler_args_size<F>::value;
    }
}
