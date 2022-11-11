#include <gtest/gtest.h>

#include "../sources/StrongPasswordChecker.hxx"

auto sol = Solution();

// NOTE: expected return values are calculated as
//          #inserts + #deletes+ #replacements
// i.e.  3 + 0 + 1  means 3 inserts, 0 deletes, 1 replacement

TEST(LeetCode420, Example1) {
    EXPECT_EQ(sol.strongPasswordChecker("a"), 5 + 0 + 0);
}

TEST(LeetCode420, Example2) {
    EXPECT_EQ(sol.strongPasswordChecker("aA1"), 3 + 0 + 0);
}

TEST(LeetCode420, Example3) {
    EXPECT_EQ(sol.strongPasswordChecker("1337C0d3"), 0 + 0 + 0);
}

TEST(LeetCode420, ShortStrings) {
    EXPECT_EQ(sol.strongPasswordChecker(""),      6 + 0);
    EXPECT_EQ(sol.strongPasswordChecker("a"),     5 + 0);
    EXPECT_EQ(sol.strongPasswordChecker("aa"),    4 + 0);
    EXPECT_EQ(sol.strongPasswordChecker("aaa"),   3 + 0);
    EXPECT_EQ(sol.strongPasswordChecker(".!."),   3 + 0);
    EXPECT_EQ(sol.strongPasswordChecker("aaaa"),  2 + 0);
    EXPECT_EQ(sol.strongPasswordChecker(".!aa"),  2 + 0);
    EXPECT_EQ(sol.strongPasswordChecker("...."),  2 + 1);
    EXPECT_EQ(sol.strongPasswordChecker("..!."),  2 + 1);
    EXPECT_EQ(sol.strongPasswordChecker("aaaaa"), 1 + 1);
    EXPECT_EQ(sol.strongPasswordChecker("aaAaa"), 1 + 0);
    EXPECT_EQ(sol.strongPasswordChecker("aabaa"), 1 + 1);
    EXPECT_EQ(sol.strongPasswordChecker("aAaaa"), 1 + 0);
    EXPECT_EQ(sol.strongPasswordChecker("1Aaaa"), 1 + 0);
}

TEST(LeetCode420, MissingCategories) {
    EXPECT_EQ(sol.strongPasswordChecker("ABCdef"), 0 + 1);
    EXPECT_EQ(sol.strongPasswordChecker("ABC123"), 0 + 1);
    EXPECT_EQ(sol.strongPasswordChecker("def123"), 0 + 1);
    EXPECT_EQ(sol.strongPasswordChecker("ABCdef123"), 0 + 0);
    EXPECT_EQ(sol.strongPasswordChecker(".!.!.!"), 0 + 3);
    EXPECT_EQ(sol.strongPasswordChecker("AB.!.!"), 0 + 2);
    EXPECT_EQ(sol.strongPasswordChecker("ABcd.!"), 0 + 1);
}

TEST(LeetCode420, RepeatingChars) {
    EXPECT_EQ(sol.strongPasswordChecker("aaaaaa"), 0 + 2);
    EXPECT_EQ(sol.strongPasswordChecker("aaaaaaaa"), 0 + 2);
    EXPECT_EQ(sol.strongPasswordChecker("Aa1aaa"), 0 + 1);
}

TEST(LeetCode420, LongStrings) {
    // Long strings (> 20Chars) require deleting chars and
    // offer no opportunity to supply missing categories
    // without adding a replacement step.
    EXPECT_EQ(sol.strongPasswordChecker("01234567890123456789Ab"), 2 + 0);
    EXPECT_EQ(sol.strongPasswordChecker("01234567890123456789AB"), 2 + 1);
    EXPECT_EQ(sol.strongPasswordChecker("01234567890123456789AB"), 2 + 1);
    EXPECT_EQ(sol.strongPasswordChecker("0123456789012345678901"), 2 + 2);
    EXPECT_EQ(sol.strongPasswordChecker(".!.!.!.!.!.!.!.!.!.!AB"), 2 + 2);
    EXPECT_EQ(sol.strongPasswordChecker(".!.!.!.!.!.!.!.!.!.!.!"), 2 + 3);
    EXPECT_EQ(sol.strongPasswordChecker("aaabbbcccdddeeefffggghhh"), 4 + 4);
    EXPECT_EQ(sol.strongPasswordChecker("aaabbbcccdddeeefffhhhhhh"), 4 + 4);
    EXPECT_EQ(sol.strongPasswordChecker("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), 14 + 7);

}