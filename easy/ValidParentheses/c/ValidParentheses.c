#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

bool isLeft(char c) {
    // true iff c is an opening bracket
    return c == '[' || c == '{' || c == '(';
}
bool isMatch(char l, char r) {
    // true iff r is the proper closing bracket for l
    return  ((l == '[') && (r == ']')) ||
            ((l == '{') && (r == '}')) ||
            ((l == '(') && (r == ')'));
}

bool isValid(char * s){
    printf("\ts = '%s'\n", s);
    size_t l = strlen(s);
    if (l % 2 == 1) {
        printf("\t\t odd length (%zu)\n", l);
        return false;
    }
    
    size_t max_stack_size = (l/2)+1;
    // max stack needed is 1/2 the size of the input string.
    char* stack = malloc(sizeof(char) * max_stack_size);
    int top = 0;

    // walk the string, pushing and popping
    for (int i = 0; i < l; i++) {
        char c = s[i];
        printf("\t%03d. '%c', top = %d -> stack before = %s\n", i, c, top, stack);

        if (isLeft(c)) {    // push
            if ((top + 1) > max_stack_size) {
                printf("\t\tNested too deep. Can't recover.\n");
                if (stack) free(stack);
                return false;
            }
            // printf("\t\tPushing '%c' onto stack. top = %d, stack[top] = '%c'\n", c, top, stack[top]);
            stack[top++] = c;
            printf("\t\tPushed  '%c' onto stack. top = %d, stack[top-1] = '%c'\n", c, top, stack[top-1]);
        } else {
            printf("\t\tsaw a RIGHT: c = '%c', top-1 = %d, stack[top-1] = '%c'\n", c, top-1, stack[top-1]);
            if (top == 0 || !isMatch(stack[top-1], c)) {
                if (stack) free(stack);
                return false;
            }
            printf("\t\tMATCH! c = '%c', stack[%int - 1] = '%c'\n", c, top, stack[top-1]);
             top--;
        }
        printf("\t\t-> stack after = %s\n", stack);

    }
    if (stack) free(stack);
    return top == 0;
}

void test(char *s, bool expected, char* name) {
    printf("test '%s'  '%s' - \n", name, s);
    bool result = isValid(s);
    printf("\tresult = %s, expected = %s\n", result ? "valid" : "invalid", expected ? "valid" : "invalid");
    printf (result == expected ? "\tpass\n" : "\tFAIL\n");
}

int main(int argc, char**argv) {
    test("", true, "empty string");
    test("[", false, "single left");
    test("]", false, "single right");
    test("()", true, "leet example 1");
    test("){", false, "leet example 9");
    test("([}}])", false, "leet example 92");
    test("[]", true, "simple");
    test("(]", false, "leet example 3");
    test("()[]{}", true, "leet example 2");
    test(")(){}", false, "leet example 89");
    test("([]", false, "leet example 90");
    test("(([]", false, "leet example 90.1");
    test("[][", false, "odd length > 1");
    test("[[", false, "odd length > 1");
    test("[]{}", true, "serial");
    test("[{}]", true, "nested");
    test("[{]}", false, "overlapping");
    test("[{}()]", true, "nested serial");
    test("[[[[[[", false, "nested too deep");
}