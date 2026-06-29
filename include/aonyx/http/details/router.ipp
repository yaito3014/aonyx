#pragma once

#include "../router.hpp"
#include <aonyx/util/handler/handler.hpp>
#include <aonyx/util/handler/make_handler.hpp>

namespace aonyx
{
    namespace http
    {
        template <class... Args>
        void router::get(const std::string_view path, util::handler_t<std::type_identity_t<Args>...> &&handler)
        {
            register_method<Args...>(method::get, path, std::forward<util::handler_t<std::type_identity_t<Args>...>>(handler));
        }

        template <class... Args>
        void router::register_method(http::method method, const std::string_view path, util::handler_t<std::type_identity_t<Args>...> &&handler)
        {
            auto trie = dispatch_trie(method);
            util::inner_handler_t inner_handler = util::make_handler(std::forward<util::handler_t<Args...>>(handler));

            trie.add(path, std::move(inner_handler));
        }
    }
}
