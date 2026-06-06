#pragma once

#include <functional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <aonyx/dom/html_node.hpp>
#include <aonyx/http/request.hpp>
#include <aonyx/http/response.hpp>

namespace aonyx
{
    namespace http
    {
        class router
        {
        public:
            using handler_t = std::function<response(const request &)>;
            using handler_html_node_t = std::function<aonyx::dom::html_node(const request &)>;

            void get(const std::string_view path, handler_t handler);
            void get(const std::string_view path, handler_html_node_t handler);

            response route(const request &req) const;

        private:
            std::unordered_map<std::string, handler_t> get_routes_;
        };
    }
}
