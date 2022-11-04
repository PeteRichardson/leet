#include "regexmatch.h"
#include <iostream>

using std::string, std::cout, std::endl;

/**
 * @brief Returns true if strings match character by character including wildcard .
 */
bool Solution::isMatch(string s, string p) {
    if (p.empty()) return s.empty();

    if (p[1] == '*')
        return (isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p)));
    else
        return (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)));
}