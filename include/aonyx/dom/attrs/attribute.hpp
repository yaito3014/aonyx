#pragma once

#include <string>
#include <string_view>

#include <aonyx/css/rule.hpp>

namespace aonyx
{
    namespace dom
    {
        struct attribute
        {
            std::string name;
            std::string value;
        };

        namespace attrs
        {
            inline attribute class_(const std::string_view value)
            {
                return attribute{"class", std::string(value)};
            }

            inline attribute id_(const std::string_view value)
            {
                return attribute{"id", std::string(value)};
            }

            inline attribute style(const std::string_view value)
            {
                return attribute{"style", std::string(value)};
            }
            inline attribute style(const css::style style)
            {
                return attribute{"style", style.to_string()};
            }

            inline attribute href(const std::string_view value)
            {
                return attribute{"href", std::string(value)};
            }

            inline attribute src(const std::string_view value)
            {
                return attribute{"src", std::string(value)};
            }

            inline attribute alt(const std::string_view value)
            {
                return attribute{"alt", std::string(value)};
            }

            inline attribute title(const std::string_view value)
            {
                return attribute{"title", std::string(value)};
            }

            inline attribute name(const std::string_view value)
            {
                return attribute{"name", std::string(value)};
            }

            inline attribute value(const std::string_view value)
            {
                return attribute{"value", std::string(value)};
            }

            inline attribute type(const std::string_view value)
            {
                return attribute{"type", std::string(value)};
            }

            inline attribute placeholder(const std::string_view value)
            {
                return attribute{"placeholder", std::string(value)};
            }

            inline attribute action(const std::string_view value)
            {
                return attribute{"action", std::string(value)};
            }

            inline attribute method(const std::string_view value)
            {
                return attribute{"method", std::string(value)};
            }

            inline attribute rel(const std::string_view value)
            {
                return attribute{"rel", std::string(value)};
            }

            inline attribute target(const std::string_view value)
            {
                return attribute{"target", std::string(value)};
            }

            inline attribute charset(const std::string_view value)
            {
                return attribute{"charset", std::string(value)};
            }

            inline attribute content(const std::string_view value)
            {
                return attribute{"content", std::string(value)};
            }

            inline attribute lang(const std::string_view value)
            {
                return attribute{"lang", std::string(value)};
            }
        }
    } // namespace dom
} // namespace aonyx
