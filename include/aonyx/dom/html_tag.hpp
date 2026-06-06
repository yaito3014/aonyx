#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <type_traits>
#include <aonyx/dom/html_node.hpp>

namespace aonyx
{
    namespace dom
    {
        struct html_tag
        {
            std::string tag_name;

            constexpr html_tag(const std::string_view tag_name) : tag_name(tag_name) {}

            template <class... Attrs>
                requires(std::same_as<Attrs, attribute> && ...)
            html_node operator()(Attrs &&...attrs) const;

            html_node operator()() const;

            template <class... Children>
                requires(std::same_as<Children, html_node> && ...)
            html_node operator()(Children &&...children) const;

            html_node operator()(const std::string_view text_content) const;
        };
    } // namespace dom
} // namespace aonyx

#include "details/html_tag.ipp"
