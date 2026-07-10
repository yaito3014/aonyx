#pragma once

#include <string>
#include <aonyx/http/request.hpp>
#include <aonyx/http/response.hpp>
#include <aonyx/http/method.hpp>
#include <boost/beast/http/verb.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/string_body.hpp>

namespace aonyx
{
    namespace impl
    {
        namespace http
        {
            namespace helper
            {
                using boost_verb = boost::beast::http::verb;
                using aonyx_method = aonyx::http::method;

                namespace method
                {
                    boost_verb convert(const aonyx_method method);
                    aonyx_method convert(const boost_verb verb);
                }

                using boost_request = boost::beast::http::request<boost::beast::http::string_body>;
                using aonyx_request = aonyx::http::request;

                namespace request
                {
                    boost_request convert(const aonyx_request &req);
                    aonyx_request convert(const boost_request &req);
                }

                using boost_response = boost::beast::http::response<boost::beast::http::string_body>;
                using aonyx_response = aonyx::http::response;

                namespace response
                {
                    boost_response convert(const aonyx_response &res);
                    aonyx_response convert(const boost_response &res);
                }
            }
        }
    }
}
