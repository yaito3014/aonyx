#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

namespace aonyx
{
    namespace css
    {
        struct style_element
        {
            std::string_view key;
            std::string_view value;
        };
        class style
        {
        public:
            void add(style_element elem)
            {
                elements[std::string(elem.key)] = std::string(elem.value);
            }

            std::string to_string() const
            {
                std::string res;
                for (const auto &[k, v] : elements)
                {
                    res += k + ":" + v + ";";
                }
                return res;
            }

        private:
            std::unordered_map<std::string, std::string> elements;
        };

        template <typename... T>
            requires(std::same_as<T, style_element> && ...)
        style rule(T... elems)
        {
            style s;

            (s.add(elems), ...);

            return s;
        }

        namespace style_elements
        {
            // --- Constant Values (Enums/Keywords) ---

            namespace display
            {
                inline static constexpr style_element none{"display", "none"};
                inline static constexpr style_element block{"display", "block"};
                inline static constexpr style_element inline_{"display", "inline"};
                inline static constexpr style_element inline_block{"display", "inline-block"};
                inline static constexpr style_element flex{"display", "flex"};
                inline static constexpr style_element grid{"display", "grid"};
            }

            namespace position
            {
                inline static constexpr style_element static_{"position", "static"};
                inline static constexpr style_element relative{"position", "relative"};
                inline static constexpr style_element absolute{"position", "absolute"};
                inline static constexpr style_element fixed{"position", "fixed"};
                inline static constexpr style_element sticky{"position", "sticky"};
            }

            namespace flex_direction
            {
                inline static constexpr style_element row{"flex-direction", "row"};
                inline static constexpr style_element column{"flex-direction", "column"};
                inline static constexpr style_element row_reverse{"flex-direction", "row-reverse"};
                inline static constexpr style_element column_reverse{"flex-direction", "column-reverse"};
            }

            namespace justify_content
            {
                inline static constexpr style_element flex_start{"justify-content", "flex-start"};
                inline static constexpr style_element flex_end{"justify-content", "flex-end"};
                inline static constexpr style_element center{"justify-content", "center"};
                inline static constexpr style_element space_between{"justify-content", "space-between"};
                inline static constexpr style_element space_around{"justify-content", "space-around"};
                inline static constexpr style_element space_evenly{"justify-content", "space-evenly"};
            }

            namespace align_items
            {
                inline static constexpr style_element stretch{"align-items", "stretch"};
                inline static constexpr style_element flex_start{"align-items", "flex-start"};
                inline static constexpr style_element flex_end{"align-items", "flex-end"};
                inline static constexpr style_element center{"align-items", "center"};
                inline static constexpr style_element baseline{"align-items", "baseline"};
            }

            namespace text_align
            {
                inline static constexpr style_element left{"text-align", "left"};
                inline static constexpr style_element right{"text-align", "right"};
                inline static constexpr style_element center{"text-align", "center"};
                inline static constexpr style_element justify{"text-align", "justify"};
            }

            namespace cursor
            {
                inline static constexpr style_element pointer{"cursor", "pointer"};
                inline static constexpr style_element default_{"cursor", "default"};
                inline static constexpr style_element text{"cursor", "text"};
                inline static constexpr style_element not_allowed{"cursor", "not-allowed"};
            }

            // --- Arbitrary Values (Functions) ---

            inline style_element width(std::string_view val) { return {"width", val}; }
            inline style_element height(std::string_view val) { return {"height", val}; }
            inline style_element max_width(std::string_view val) { return {"max-width", val}; }
            inline style_element max_height(std::string_view val) { return {"max-height", val}; }
            inline style_element min_width(std::string_view val) { return {"min-width", val}; }
            inline style_element min_height(std::string_view val) { return {"min-height", val}; }

            inline style_element margin(std::string_view val) { return {"margin", val}; }
            inline style_element margin_top(std::string_view val) { return {"margin-top", val}; }
            inline style_element margin_right(std::string_view val) { return {"margin-right", val}; }
            inline style_element margin_bottom(std::string_view val) { return {"margin-bottom", val}; }
            inline style_element margin_left(std::string_view val) { return {"margin-left", val}; }

            inline style_element padding(std::string_view val) { return {"padding", val}; }
            inline style_element padding_top(std::string_view val) { return {"padding-top", val}; }
            inline style_element padding_right(std::string_view val) { return {"padding-right", val}; }
            inline style_element padding_bottom(std::string_view val) { return {"padding-bottom", val}; }
            inline style_element padding_left(std::string_view val) { return {"padding-left", val}; }

            inline style_element color(std::string_view val) { return {"color", val}; }
            inline style_element background(std::string_view val) { return {"background", val}; }
            inline style_element background_color(std::string_view val) { return {"background-color", val}; }

            inline style_element font_size(std::string_view val) { return {"font-size", val}; }
            inline style_element font_family(std::string_view val) { return {"font-family", val}; }
            inline style_element font_weight(std::string_view val) { return {"font-weight", val}; }
            inline style_element line_height(std::string_view val) { return {"line-height", val}; }

            inline style_element border(std::string_view val) { return {"border", val}; }
            inline style_element border_radius(std::string_view val) { return {"border-radius", val}; }
            inline style_element box_shadow(std::string_view val) { return {"box-shadow", val}; }

            inline style_element z_index(std::string_view val) { return {"z-index", val}; }
            inline style_element opacity(std::string_view val) { return {"opacity", val}; }
        }
    }
}
