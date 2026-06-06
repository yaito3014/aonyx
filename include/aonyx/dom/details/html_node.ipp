#pragma once

#include "../html_tag.hpp"

namespace aonyx
{
    namespace dom
    {
        template <class... Children>
            requires(std::same_as<Children, html_node> && ...)
        html_node &html_node::operator()(Children &&...child)
        {
            (children.push_back(std::forward<Children>(child)), ...);
            return *this;
        }
    } // namespace dom
} // namespace aonyx
