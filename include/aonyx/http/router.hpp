#pragma once

#include <functional>
#include <string>
#include <vector>
#include <memory>
#include <string_view>
#include <unordered_map>
#include <ranges>
#include <aonyx/dom/html_node.hpp>
#include <aonyx/http/request.hpp>
#include <aonyx/http/response.hpp>
#include <aonyx/util/handler/handler.hpp>

namespace aonyx
{
    namespace http
    {
        class router
        {
        public:
            template <class... Args>
            void get(const std::string_view path, util::handler_t<std::type_identity_t<Args>...> &&handler);

            void dispatch(const request &req, response &res) const;

        private:
            class route_trie
            {
            public:
                struct node_t
                {
                    std::string segment;
                    util::inner_handler_t handler;
                    std::vector<std::shared_ptr<node_t>> children;
                };

                route_trie() : root_(std::make_shared<node_t>()) {}
                ~route_trie() = default;

                void add(const std::string_view path, util::inner_handler_t &&handler);
                util::inner_handler_t find(const std::string_view path) const;

            private:
                std::shared_ptr<node_t> root_;
            };

            route_trie trie_;
        };
    }
}

#include "details/router.ipp"
