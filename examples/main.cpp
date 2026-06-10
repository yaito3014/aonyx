#include <aonyx.hpp>
#include <iostream>

using namespace aonyx::dom;

html_node hoge()
{
    // do something
    int num = 10;

    return div_(
        div_("a"),
        div_("b"),
        div_("c"));
}

void top(const aonyx::http::request &req, aonyx::http::response &res)
{
    auto node =
        html(attribute{"lang", "en"})(
            head(),
            body(
                div_(
                    span("Hello, World!")),
                hoge()));

    res.body = node.to_string();
    res.status = 200;
    res.headers["Content-Type"] = "text/html";
}

int main()
{
    aonyx::http::server server;
    server.router().get("/top", top);

    server.run();

    return 0;
}
