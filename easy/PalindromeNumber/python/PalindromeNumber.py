import unittest

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0: 
            return False
        s = str(x)
        for i in range(len(s)):
            if s[i] != s[-i-1]:
                return False
        return True

if __name__ == "__main__":
    sol = Solution()
    print(sol.isPalindrome(1331))