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

aonyx::dom::html_node top(const aonyx::http::request &req)
{
    auto node =
        html(attribute{"lang", "en"})(
            head(),
            body(
                div_(
                    span("Hello, World!")),
                hoge()));

    return node;
}

int main()
{
    aonyx::http::server server;
    server.router().get("/top", top);

    server.run();

    return 0;
}
