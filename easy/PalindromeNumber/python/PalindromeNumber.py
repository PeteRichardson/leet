import unittest
from math import log10
class Solution:

    ## Solution without converting the integer to a string

    ###   FAILS when embedded 0s e.g.  1021 -> True! ??
    def isPalindromeNoString(self, x: int) -> bool:
        if x < 0:
            return False
        while x != 0 and x >= 10:
            y=int(log10(x))
            l = x//10**y
            r = x%10
            # print(l,r)
            if l!=r:
                return False
            x = (x%10**y - r) // 10
        return True

    ## Even better string solution
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        return s == s[::-1]

    ## Simple solution by converting to string
    # def isPalindrome(self, x: int) -> bool:
    #     if x < 0: 
    #         return False
    #     s = str(x)
    #     for i in range(len(s)):
    #         if s[i] != s[-i-1]:
    #             return False
    #     return True

if __name__ == "__main__":
    sol = Solution()
    print(sol.isPalindrome(1021))