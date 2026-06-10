#include <algorithm>

#include <aonyx/http/router.hpp>

namespace aonyx
{
    namespace http
    {
        void router::dispatch(const request &req, response &res) const
        {
            if (req.method == method::get)
            {
                auto handler = trie_.find(req.path);

                if (not handler)
                {
                    res.status = 404;
                    res.body = "404 Not Found";

                    res.headers["Content-Type"] = "text/html";

                    return;
                }

                handler(req, res, {});

                return;
            }

            res.status = 404;
            res.body = "404 Not Found";

            res.headers["Content-Type"] = "text/html";
        }

        void router::route_trie::add(const std::string_view path, util::inner_handler_t &&handler)
        {
            using namespace std::literals;

            auto node = root_;

            for (int i = 0; auto sv : path | std::views::split("/"sv))
            {
                if (i++ == 0)
                    continue;
                auto segment = std::string(sv.begin(), sv.end());

                auto result = std::find_if(node->children.begin(), node->children.end(), [&segment](std::shared_ptr<node_t> node)
                                           { return node->segment == segment; });
                if (result == node->children.end())
                {
                    auto new_node = std::make_shared<node_t>();
                    new_node->segment = segment;
                    node->children.push_back(new_node);

                    node = new_node;
                }
                else
                {
                    node = *result;
                }
            }
            node->handler = std::forward<util::inner_handler_t>(handler);
        }

        util::inner_handler_t router::route_trie::find(std::string_view path) const
        {
            using namespace std::literals;

            auto node = root_;

            for (int i = 0; auto sv : path | std::views::split("/"sv))
            {
                if (i++ == 0)
                    continue;

                auto segment = std::string(sv.begin(), sv.end());

                auto it = std::find_if(
                    node->children.begin(),
                    node->children.end(),
                    [&segment](const std::shared_ptr<node_t> &child)
                    {
                        return child->segment == segment;
                    });

                if (it == node->children.end())
                {
                    return {};
                }

                node = *it;
            }

            return node->handler;
        }
    }
}
