import unittest
from PalindromeNumber import Solution

class TestPalindromeNumber (unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test0(self):
        self.assertEqual(True, self.sol.isPalindrome(0))

    def test121(self):
        self.assertEqual(True, self.sol.isPalindrome(121))

    def testnegative121(self):
        self.assertEqual(False, self.sol.isPalindrome(-121))

    def test1331(self):
        self.assertEqual(True, self.sol.isPalindrome(1331))

    def testnormal(self):
        self.assertEqual(False, self.sol.isPalindrome(12345))

if __name__ == "__main__":
    unittest.main()