#include "convert.hpp"

namespace aonyx
{
    namespace impl
    {
        namespace http
        {
            namespace helper
            {
                namespace method
                {
                    boost_verb convert(const aonyx_method method)
                    {
                        switch (method)
                        {
                        case aonyx_method::get:
                            return boost_verb::get;
                            break;
                        case aonyx_method::post:
                            return boost_verb::post;
                            break;
                        case aonyx_method::put:
                            return boost_verb::put;
                            break;
                        case aonyx_method::delete_:
                            return boost_verb::delete_;
                            break;

                        default:
                            return boost_verb::unknown;
                            break;
                        }
                    }
                    aonyx_method convert(const boost_verb verb)
                    {
                        switch (verb)
                        {
                        case boost_verb::get:
                            return aonyx_method::get;
                            break;
                        case boost_verb::post:
                            return aonyx_method::post;
                            break;
                        case boost_verb::put:
                            return aonyx_method::put;
                            break;
                        case boost_verb::delete_:
                            return aonyx_method::delete_;
                            break;

                        default:
                            return aonyx_method::unknown;
                            break;
                        }
                    }
                }

                namespace request
                {
                    boost_request convert(const aonyx_request &req)
                    {
                        namespace http = boost::beast::http;

                        http::request<http::string_body> result;

                        result.method(method::convert(req.method));
                        result.target(req.path);
                        result.body() = req.body;

                        for (const auto &[key, value] : req.headers)
                        {
                            result.set(key, value);
                        }

                        result.prepare_payload();

                        return result;
                    }
                    aonyx_request convert(const boost_request &req)
                    {
                        aonyx_request result;

                        result.method = method::convert(req.method());
                        result.path = std::string(req.target());
                        result.body = req.body();

                        for (const auto &field : req)
                        {
                            result.headers.emplace(
                                std::string(field.name_string()),
                                std::string(field.value()));
                        }

                        return result;
                    }
                }

                namespace response
                {
                    boost_response convert(const aonyx_response &res)
                    {
                        namespace http = boost::beast::http;

                        boost_response result;

                        result.result(
                            static_cast<http::status>(res.status));

                        result.body() = res.body;

                        for (const auto &[key, value] : res.headers)
                        {
                            result.set(key, value);
                        }

                        result.prepare_payload();

                        return result;
                    }
                    aonyx_response convert(const boost_response &res)
                    {
                        aonyx_response result;

                        result.status = static_cast<int>(res.result());

                        result.body = res.body();

                        for (const auto &field : res)
                        {
                            result.headers.emplace(
                                std::string(field.name_string()),
                                std::string(field.value()));
                        }

                        return result;
                    }
                }
            }
        }
    }
}
