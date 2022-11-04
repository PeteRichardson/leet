#include <iostream>
#include <string>
#include "regexmatch.h"

using std::cout;
using std::endl;
using std::string;

auto sol = Solution();

void test(string s, string p) {
    cout << "#TEST: s = " << s << "; p = " << p << " ------ ";
    cout << "\nRESULT: ";
    if (sol.isMatch(s, p))
        cout << "pass";
    else
        cout << "FAIL!";
    cout << "\n\n";
}

int main(int argc, char** argv) {
    bool test_result = false;
    
    test("fooAnythingHere", "foo.*");
}