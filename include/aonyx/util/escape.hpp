#pragma once

#include <string>
#include <string_view>

namespace aonyx
{
    namespace util
    {
        inline std::string escape_html(std::string_view data) noexcept
        {
            std::string buffer;
            buffer.reserve(data.size());
            for(size_t pos = 0; pos != data.size(); ++pos)
            {
                switch(data[pos])
                {
                    case '&':  buffer.append("&amp;");       break;
                    case '\"': buffer.append("&quot;");      break;
                    case '\'': buffer.append("&apos;");      break;
                    case '<':  buffer.append("&lt;");        break;
                    case '>':  buffer.append("&gt;");        break;
                    default:   buffer.append(&data[pos], 1); break;
                }
            }

            
            return buffer;
        }
    }
}
