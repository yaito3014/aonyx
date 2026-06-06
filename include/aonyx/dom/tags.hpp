#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <type_traits>

#include <aonyx/dom/html_tag.hpp>

namespace aonyx
{
    namespace dom
    {
        inline constexpr html_tag html{"html"};
        inline constexpr html_tag head{"head"};
        inline constexpr html_tag body{"body"};
        inline constexpr html_tag div_{"div"};
        inline constexpr html_tag span{"span"};
    } // namespace dom
} // namespace aonyx
