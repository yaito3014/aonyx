#pragma once

#include <string>
#include <string_view>

namespace aonyx
{
    namespace util
    {
        template <class T>
        inline T param_from_string(std::string_view) {}

        template <>
        inline int param_from_string<int>(std::string_view s)
        {
            return std::stoi(s.data());
        }

        template <>
        inline bool param_from_string<bool>(std::string_view s)
        {
            if (s == "true" || s == "1")
                return true;
            else
                return false;
        }

        template <>
        inline std::string param_from_string<std::string>(std::string_view s)
        {
            return std::string(s);
        }
    }
}
