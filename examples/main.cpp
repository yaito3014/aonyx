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

void user_prof(const aonyx::http::request &req, aonyx::http::response &res, int id)
{
    res.body = aonyx::dom::div_(std::to_string(id)).to_string();
    res.status = 200;
    res.headers["Content-Type"] = "text/html";
}

int main()
{
    aonyx::http::server server;
    auto &router = server.router();
    router.get("/top", top);
    router.get<int>("/users/{}", [](const aonyx::http::request &req, aonyx::http::response &res, int id)
                    {
    res.body = aonyx::dom::div_(std::to_string(id)).to_string();
    res.status = 200;
    res.headers["Content-Type"] = "text/html"; });

    router.post<int>("/users/{}", [](const aonyx::http::request &req, aonyx::http::response &res, int id)
                     {
        res.body = R"({"user_id": 100, "user_name": "hoge"})";
        res.status = 200;
        res.headers["Content-Type"] = "text/json"; });

    server.run();

    return 0;
}
