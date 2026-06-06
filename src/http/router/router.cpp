#include <aonyx/http/router.hpp>

namespace aonyx
{
    namespace http
    {
        void router::get(const std::string_view path, handler_t handler)
        {
            get_routes_[std::string(path)] = std::move(handler);
        }
        void router::get(const std::string_view path, handler_html_node_t handler)
        {
            handler_t h = [&handler](const request &req)
            {
                response res;
                res.body = handler(req).to_string();
                res.status = 200;
                res.headers["Content-Type"] = "text/html";

                return res;
            };

            this->get(path, h);
        }

        response router::route(const request &req) const
        {
            if (req.method == method::get)
            {
                auto it = get_routes_.find(std::string(req.path));

                if (it != get_routes_.end())
                {
                    return it->second(req);
                }
            }

            response res;
            res.status = 404;
            res.body = "404 Not Found";

            res.headers["Content-Type"] = "text/html";

            return res;
        }
    }
}
