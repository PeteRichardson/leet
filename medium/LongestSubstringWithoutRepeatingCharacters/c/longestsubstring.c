#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int lengthOfLongestSubstring(char *s){
    int global_max = 0;
    int local_max = 0;
    int global_start = 0;
    int local_start = 0;

    int16_t seen[255];
    memset(seen, -1, sizeof(seen));

    char c;
    for (int i=0; (c = *(s+i)); i++) {
        //printf("%c ", c);
        if (seen[c] == -1) {
            // never seen this char before, so we're clearly
            // extending the local substring.
            local_max++;
        } else {
            // we've seen this character before.
            // if it was before current local start, we're still
            // extending the local substring
            if (seen[c] < local_start) {
                local_max++;
            } else {
                //new local start is one after the last seen
                local_start = seen[c] + 1;
                local_max = i - local_start + 1;
            }
        }
        // after all that, do we have a new global_max?
        if (local_max > global_max) {
            global_max = local_max;
            global_start = local_start;
        }
        seen[c] = i;   // mark that we've seen this char
        // printf("local: start = %d, max = %d  (set seen[%c] = %d\n", local_start, local_max,c,i);
    }
    //printf("\n");
    //printf("global: start = %d, max = %d\n", global_start, global_max);
    return global_max;
}



int main(int argc, char** argv) {
    char *s="abcabcbb";
    printf("\"%s\" -> lols=%d\n", s, lengthOfLongestSubstring(s));

    s="bbbbb";
    printf("\"%s\" -> lols=%d\n", s, lengthOfLongestSubstring(s));

    s="pwwkew";
    printf("\"%s\" -> lols=%d\n", s, lengthOfLongestSubstring(s));

    s="abcdefghijklmnopqratuvwxyz1234567890-+=_";
    printf("\"%s\" -> lols=%d\n", s, lengthOfLongestSubstring(s));

    return EXIT_SUCCESS;
}