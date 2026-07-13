#include <aonyx/dom/html_tag.hpp>
#include <aonyx/util/escape.hpp>

namespace aonyx
{
    namespace dom
    {

        html_node html_tag::operator()() const
        {
            return html_node{tag_name};
        }

        html_node html_tag::operator()(const std::string_view text_content) const
        {
            html_node node{tag_name};
            node.text_content = aonyx::util::escape_html(text_content);
            return node;
        }
    } // namespace aonyx
}
