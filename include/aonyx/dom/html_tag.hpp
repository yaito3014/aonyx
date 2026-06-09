#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <type_traits>
#include <aonyx/util/concepts.hpp>
#include <aonyx/dom/html_node.hpp>
#include <aonyx/dom/tags.hpp>

namespace aonyx
{
    namespace dom
    {
        struct html_tag
        {
            tags tag;
            std::string tag_name;

            constexpr html_tag(const std::string_view tag_name) : tag_name(tag_name)
            {
                tag = str2tags(tag_name);
            }
            constexpr html_tag(const tags &tag) : tag(tag)
            {
                tag_name = tags2str(tag);
            }

            template <class... Attrs>
                requires(util::like<Attrs, attribute> && ...)
            html_node operator()(Attrs &&...attrs) const;

            html_node operator()() const;

            template <class... Children>
                requires(util::like<Children, html_node> && ...)
            html_node operator()(Children &&...children) const;

            html_node operator()(const std::string_view text_content) const;
        };
    } // namespace dom
} // namespace aonyx

#include "details/html_tag.ipp"
