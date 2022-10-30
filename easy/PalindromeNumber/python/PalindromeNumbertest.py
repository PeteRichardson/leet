import unittest
from PalindromeNumber import Solution

class TestPalindromeNumber (unittest.TestCase):
    def test0(self):
        sol = Solution()
        self.assertEqual(True, sol.isPalindrome(0))

    def test121(self):
        sol = Solution()
        self.assertEqual(True, sol.isPalindrome(121))

    def testnegative121(self):
        sol = Solution()
        self.assertEqual(False, sol.isPalindrome(-121))

    def test1331(self):
        sol = Solution()
        self.assertEqual(True, sol.isPalindrome(1331))

    def testnormal(self):
        sol = Solution()
        self.assertEqual(False, sol.isPalindrome(12345))