#include "aonyx/dom.hpp"

#include <aonyx/util/escape.hpp>

namespace aonyx
{
    namespace dom
    {

        html_node &html_node::operator()(const std::string_view text_content)
        {
            this->text_content = aonyx::util::escape_html(text_content);
            return *this;
        }

        std::string html_node::to_string() const
        {
            if (this->tag_name.empty())
            {
                std::string result = "";
                for (const auto &child : children)
                {
                    result += child.to_string();
                }

                return result;
            }
            std::string result = "<" + tag_name;
            for (const auto &attr : attributes)
            {
                result += " " + attr.name + "=\"" + attr.value + "\"";
            }
            result += ">";
            if (!text_content.empty())
            {
                result += text_content;
            }
            for (const auto &child : children)
            {
                result += child.to_string();
            }
            result += "</" + tag_name + ">";
            return result;
        }
    } // namespace aonyx
}
