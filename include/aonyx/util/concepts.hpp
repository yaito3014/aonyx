#pragma once

#include <type_traits>
#include <concepts>

namespace aonyx
{
    namespace util
    {
        template <class T, class U>
        concept like = std::same_as<std::remove_cvref_t<T>, U>;
    }
}
