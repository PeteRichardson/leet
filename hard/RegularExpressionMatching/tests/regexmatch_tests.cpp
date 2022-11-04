#include <gtest/gtest.h>

#include "../regexmatch.h"

auto sol = Solution();

TEST(LeetCode, Example1) {
    EXPECT_FALSE(sol.isMatch("aa", "a"));
}
TEST(LeetCode, Example2) {
    EXPECT_TRUE(sol.isMatch("aa", "a*"));
}
TEST(LeetCode, Example3) {
    EXPECT_TRUE(sol.isMatch("ab", ".*"));
}

TEST(DirectMatch, NoSpecialChars) {
    EXPECT_TRUE(sol.isMatch("foo", "foo"));
    EXPECT_FALSE(sol.isMatch("foo", "bar"));
}

TEST(DirectMatch, PatternLength) {
    EXPECT_FALSE(sol.isMatch("foo", "fooo"));
    EXPECT_FALSE(sol.isMatch("foo", "fo"));
}

TEST(DirectMatch, SingleChar) {
    EXPECT_TRUE(sol.isMatch("a", "a"));
}

TEST(DirectMatch, StringLength) {
    EXPECT_FALSE(sol.isMatch("fooo", "foo"));
    EXPECT_FALSE(sol.isMatch("fo",   "foo"));
}

TEST(Period, Simple) {
    EXPECT_TRUE(sol.isMatch("foo", "f.o"));
    EXPECT_TRUE(sol.isMatch("foo", "..."));
    EXPECT_FALSE(sol.isMatch("foo", "foo."));
}

TEST(DotStar, Single) {
    EXPECT_TRUE(sol.isMatch("", ".*"));
    EXPECT_TRUE(sol.isMatch("foo", ".*"));
    EXPECT_TRUE(sol.isMatch("fooAnythingHere", "foo.*"));
    EXPECT_TRUE(sol.isMatch("foobbbbSuffix", "foo.*Suffix"));
    EXPECT_FALSE(sol.isMatch("fooAnythingHere", "foo.*f"));
}

TEST(Asterisk, Single) {
    EXPECT_TRUE(sol.isMatch("foo", "fo*"));   // 
    EXPECT_TRUE(sol.isMatch("foo", "f*oo"));
    EXPECT_TRUE(sol.isMatch("foo", "b*foo"));
    EXPECT_TRUE(sol.isMatch("fooot", "fo*t"));
    EXPECT_FALSE(sol.isMatch("foo", "foo."));
    EXPECT_TRUE(sol.isMatch("fooo", ".o*"));
    EXPECT_TRUE(sol.isMatch("foo", ".*"));
    EXPECT_TRUE(sol.isMatch("food", "fo.*d"));
    EXPECT_TRUE(sol.isMatch("fooot", "fo*ot"));
    EXPECT_TRUE(sol.isMatch("elginmarbles", "elgin.*"));
    EXPECT_TRUE(sol.isMatch("elginmarbles", "elgin.*les"));
}

TEST(Asterisk, Multiple) {
    EXPECT_TRUE(sol.isMatch("foo", "b*.*"));
    EXPECT_TRUE(sol.isMatch("foo", "a*b*.*"));
    EXPECT_TRUE(sol.isMatch("aacfoo", "a*cb*.*"));
}
