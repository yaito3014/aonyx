#pragma once

#include "../html_tag.hpp"

namespace aonyx
{
    namespace dom
    {
        template <class... Attrs>
            requires(util::like<Attrs, attribute> && ...)
        html_node html_tag::operator()(Attrs &&...attrs) const
        {
            html_node node{tag_name};
            (node.attributes.push_back(std::forward<Attrs>(attrs)), ...);
            return node;
        }

        template <class... Children>
            requires(util::like<Children, html_node> && ...)
        html_node html_tag::operator()(Children &&...children) const
        {
            html_node node{tag_name};
            (node.children.push_back(std::forward<Children>(children)), ...);
            return node;
        }
    } // namespace dom
} // namespace aonyx
