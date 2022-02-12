// Utils help with text

#pragma once
#include <string>
#include <string_view>

using namespace std::string_literals;

using std::string;
using std::string_view;
namespace StringHelp
{
    void get_size_string(string_view str, size_t *p_max_length, size_t *p_count_lines)
    {
        size_t prev_pos{0}, pos_str{0}, lines{0}, max_length{0};
        for (; pos_str <= str.length(); pos_str = str.find('\n', ++prev_pos))
        {
            int length = pos_str - prev_pos;
            lines++;
            max_length = max_length < length ? length : max_length;
            prev_pos = pos_str;
        }
        *p_count_lines = lines;
        *p_max_length = max_length;
    }
}