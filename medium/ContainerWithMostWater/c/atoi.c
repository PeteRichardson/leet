#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define MIN_INT32 -2147483648
#define MAX_INT32 2147483647


int myAtoi(char * s) {
    int64_t result = 0;

    // Step 1: check for end of string and skip whitespace
    while (*s != '\0' && *s == ' ') s++;

    // Step 2: Read the sign (if any)
    int sign = 1;
    if (*s == '+') {
        s++;
    } else if (*s == '-') {
        sign = -1;
        s++;
    };

    // Step 3: Convert leading digits to an int64
    while (*s >= '0' && *s <= '9') {
        result = (result * 10) + (*s - '0');
        s++;
        // abort as soon as we know we're out of range.
        if (result > MAX_INT32) {
            return sign == -1 ? labs(MIN_INT32) : MAX_INT32;
        };
    }

    return sign * result;
}

void test(char* s, int expected) {

    printf("test: '%s':\n", s);
    int result = myAtoi(s);

    char* message = "FAIL";
    printf("\treturned = %d\n", result);
    printf("\texpected = %d\n", expected);

    if (result == expected) {
        message = "pass";
    }
    printf( "\t%s\n\n", message);
}


int main(int argc, char** argv) {
    test("42", 42);
    test("    23", 23);
    test("18", 18);
    test("+18", 18);
    test("-18", -18);
    test("546 Some words", 546);
    test("547.Some words", 547);
    test("-", 0);
    test("words", 0);
    test("-words", 0);
    test("-2147483650", -2147483648);
    test("3336402735171707160320", 2147483647);
}