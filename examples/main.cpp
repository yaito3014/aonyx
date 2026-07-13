#include <aonyx.hpp>
#include <iostream>
#include <thread>

using namespace aonyx::dom;

html_node hoge()
{
    // do something
    int num = 10;

    return div_(
        div_("a"),
        div_("<p>hoge!!</p>"),
        div_("c"));
}

void top(AONYX_PARAM(req, res))
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

void user_prof(AONYX_PARAM(req, res), int id)
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
    router.get<int>("/users/{}", [](AONYX_PARAM(req, res), int id)
                    {
    res.body = aonyx::dom::div_(std::to_string(id)).to_string();
    res.status = 200;
    res.headers["Content-Type"] = "text/html"; });

    router.post<int>("/users/{}", [](AONYX_PARAM(req, res), int id)
                     {
        aonyx::json body;
        body["user_id"] = 100;
        body["user_name"] = "hoge";
        res.body = body.dump();
        res.status = 200;
        res.headers["Content-Type"] = "text/json"; });

    router.get("/heavy", [](AONYX_PARAM(req, res))
               { 
                std::this_thread::sleep_for(std::chrono::minutes(1));
                res.body = aonyx::dom::div_("heavy").to_string();
    res.status = 200;
    res.headers["Content-Type"] = "text/html"; });

    server.run();

    return 0;
}
