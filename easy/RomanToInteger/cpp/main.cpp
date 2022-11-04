#include <iostream>
#include <stdlib.h>
#include "RomanToInteger.h"

using std::string, std::cout, std::endl;

auto sol = Solution();

void test(string roman, int expected_answer) {
    cout << "# TEST: roman = '" << roman << "' ------ ";
    cout << "\tRESULT: ";
    auto computed_answer = sol.romanToInt(roman);
    if (computed_answer == expected_answer)
        cout << "pass";
    else {
        cout << "FAIL!  (computed = " << computed_answer << ", expected = " << expected_answer << endl;
    }
    cout << "\n";
}

int main(int argc, char** argv) {
    test("I", 1);
    test("III", 3);
    test("XV", 15);
    test("MDCLXVI", 1666);
    test("IV", 4);
    test("IX", 9);
    test("XL", 40);
    test("XC", 90);
    test("CD", 400);
    test("CM", 900);
    test("MMMCMXCIX", 3999);

    return EXIT_SUCCESS;
}