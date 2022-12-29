#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

bool isBracket(char c) {
    // true iff c is an opening bracket
    return c == '[' || c == ']' || c == '{' || c == '}' || c == '(' || c == ')';
}
bool isLeft(char c) {
    // true iff c is an opening bracket
    return c == '[' || c == '{' || c == '(';
}
bool isRight(char c) {
    // true iff c is a closing bracket
    return c == ']' || c == '}' || c == ')';
}
bool isMatch(char l, char r) {
    // true iff r is the proper closing bracket for l
    return  ((l == '[') && (r == ']')) ||
            ((l == '{') && (r == '}')) ||
            ((l == '(') && (r == ')'));
}

bool isValid(char * input){
    char *s = strdup(input);
    printf("\tbefore: '%s'\n", s);

    char* trailing = s;
    if (*trailing == '\0')
        return true;
    char* leading = s+1;
    if (*leading == '\0' || isRight(*trailing))
        return false;
    for (leading = s+1; *leading != '\0'; leading++) {
        printf("\ttrailing = '%c', leading = '%c'", *trailing, *leading);
        assert(isBracket(*leading));
        if (isMatch(*trailing, *leading)) {
            printf(" MATCH! removing both.");
            *trailing = '.';
            while (trailing > s && *trailing == '.')
                trailing--;
            *leading = '.';
        };
        if (isLeft(*leading)) {
            trailing = leading;
            printf(" do nothing.");
        }
        if (isRight(*leading)) {
            // right but no match!  FAIL.
            printf(" invalid: unmatched right\n");
            return false;
        }
        printf("\n");
    }
    printf("\tafter:  '%s'\n", s);
    printf("\ttrailing = '%c', leading = '%c'\n", *trailing, *leading);
    printf("\t&s = 0x%X, &trailing = 0x%X, &leading = 0x%X\n", s, trailing, leading);

    if (*trailing != '\.') {
        printf("\tSUCKAGE - trailing = '%s', &trailing = 0x%X, &leading = 0x%X\n", trailing, trailing, s);
        return false;
    }
    // Last chance... make sure length is even.
    // return ((leading - trailing) %2) == 0;
    return true;
}

void test(char *s, bool expected, char* name) {
    printf("test '%s'  '%s' - \n", name, s);
    bool result = isValid(s);
    printf (result == expected ? "\tpass\n" : "\tFAIL\n");
}

int main(int argc, char**argv) {
    test("()[]{}", true, "leet example 2");
    test("()", true, "leet example 1");
    test("(]", false, "leet example 3");
    test(")(){}", false, "leet example 89");
    test("([]", false, "leet example 90");
    test("(([]", false, "leet example 90.1");
    test("[]", true, "simple");
    test("[", false, "single left");
    test("]", false, "single right");
    test("[][", false, "odd length > 1");
    test("[[", false, "odd length > 1");
    test("", true, "empty string");
    test("[]{}", true, "serial");
    test("[{}]", true, "nested");
    test("[{]}", false, "overlapping");
    test("[{}()]", true, "nested serial");
}