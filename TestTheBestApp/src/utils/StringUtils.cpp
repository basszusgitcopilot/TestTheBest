#include "StringUtils.h"

auto replace(std::string where, std::string what, std::string by_what) -> std::string {
    size_t index = 0;
    while (index < where.size()) {
        index = where.find(what, index);
        if (index == std::string::npos) {
            break;
        }
        where.replace(index, what.size(), by_what);
        index += what.size();
    }
    return where;
}