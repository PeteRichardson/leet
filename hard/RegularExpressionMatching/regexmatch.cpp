#include "regexmatch.h"
#include <iostream>

using std::string, std::cout, std::endl;

/**
 * @brief Returns true if strings match character by character including wildcard .
 */
bool simpleMatch(string s, string p) {
    int si = 0;
    int sl = s.length();
    int pi = 0;
    int pl = p.length();
    cout << endl << "sl=" << sl << "; pl=" << pl << endl;
    while ( si < sl && pi < pl && (s[si] == p[pi] || p[pi] == '.')) {
        cout << "si=" << si << ";  pi=" << pi;
        cout << " - s[si]='" << s[si] << "';  p[pi]=" << p[pi] << endl;
        si++;
        pi++;
    }
    //cout << "si=" << si << ";  pi=" << pi;
    //cout << " - s[si]='" << s[si] << "';  p[pi]=" << p[pi] << endl;
    return si == sl and pi == pl;
}

bool singleAsteriskMatch(string s, string p) {
    // if there's only one asterisk, it's easy to calculate the match.
    // if the first char of the pattern is '.' then return true (.* matches anything)
    // otherwise, all chars in the remaining string must match the first char of the pattern
    assert(p.length() == 2);
    assert(p[1] == '*');
    if (p[0] == '.')
        return true;

    for (char c: s) {
        if (c != p[0])
            return false;
    }
    return true;
}



bool Solution::isMatch(string s, string p) {
    int si = 0;
    int sl = s.length();
    int pi = 0;
    int pl = p.length();

    // anything before the first asterisk (aka the prefix) must match exactly
    // anything after the last asterisk (aka the suffix) must match exactly
    int first_ast_i = p.find('*');
    int last_ast_i  = p.rfind('*');

    //if there's are no asterisks, just do a simple match of the full string and pattern
    if (first_ast_i == std::string::npos) {
        return simpleMatch(s, p);
    }

    size_t prefix_length = first_ast_i - 1;
    size_t suffix_length = pl - first_ast_i;
    string s_prefix = s.substr(0, prefix_length);
    string s_suffix = s.substr(sl - suffix_length + 1);
    cout << "\ns_prefix='" << s_prefix << "'  ...  s_suffix='" << s_suffix << "'" <<  endl;
    string p_prefix = p.substr(0, first_ast_i - 1);
    string p_suffix = p.substr(first_ast_i + 1);
    cout << "p_prefix='" << p_prefix << "'  ...  p_suffix='" << p_suffix << "'" << endl;

    string s_middle = s.substr(prefix_length, sl - prefix_length - suffix_length + 1);
    string p_middle = p.substr(prefix_length, pl - prefix_length - suffix_length + 1);
    cout << "s_middle='" << s_middle << "'" << endl;
    cout << "p_middle='" << p_middle << "'" << endl;


    return simpleMatch(s_prefix, p_prefix) && singleAsteriskMatch(s_middle, p_middle) && simpleMatch(s_suffix, p_suffix);
}