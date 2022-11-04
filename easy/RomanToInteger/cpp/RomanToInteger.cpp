#include "RomanToInteger.h"
using std::string;

int Solution::romanToInt(string s) {
    int result = 0;
    char prev = ' ';
    for (char c : s) {
        switch (c) {
            case 'I': result += 1; break;
            case 'V': result += (prev == 'I') ? 3 : 5; break;
            case 'X': result += (prev == 'I') ? 8 :10; break;
            case 'L': result += (prev == 'X') ? 30 :50; break;
            case 'C': result += (prev == 'X') ? 80 :100; break;
            case 'D': result += (prev == 'C') ? 300 :500; break;
            case 'M': result += (prev == 'C') ? 800 :1000; break;
        }
        prev = c;
    }
    return result;
}