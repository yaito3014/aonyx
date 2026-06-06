#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <type_traits>
#include <aonyx/dom/attribute.hpp>

namespace aonyx
{
    namespace dom
    {
        struct html_node
        {
            std::string tag_name;
            std::vector<attribute> attributes;
            std::vector<html_node> children;
            std::string text_content;

            constexpr html_node(const std::string_view tag_name) : tag_name(tag_name) {}

            template <class... Children>
                requires(std::same_as<Children, html_node> && ...)
            html_node &operator()(Children &&...child);

            html_node &operator()(const std::string_view text_content);

            std::string to_string() const;
        };
    } // namespace dom
} // namespace aonyx

#include "details/html_node.ipp"
