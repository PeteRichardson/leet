#!/usr/bin/env python3

from logging.config import valid_ident
from typing import List, Optional
from math import log10

# # Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sum_digits = []
        carry : int = 0
        while l1 is not None or l2 is not None:
            local_sum : int = carry
            if l1 is not None:
                local_sum += l1.val
                l1 = l1.next
            if l2 is not None:
                local_sum += l2.val
                l2 = l2.next
            if local_sum >= 10:
                carry = 1
                local_sum %= 10
            else:
                carry = 0
            sum_digits.append(local_sum)
        if carry == 1:
            sum_digits.append(carry)
        
        sum_digits.reverse()
        result : Optional[ListNode] = None
        for digit in sum_digits:
            result = ListNode(digit, result)
        
        return result
        
    def println(self, l: Optional[ListNode]) -> None:
        node = l
        print("[", end = "")
        while node.next != None:
            print(f"{node.val},",end="")
            node = node.next
        print(f"{node.val}]")

if __name__ == "__main__":
    sol = Solution()
    l1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    sol.println(l1)
    l2 = ListNode(2, ListNode(8, ListNode(7)))
    sol.println(l2)

    answer = sol.addTwoNumbers(l1, l2)
    sol.println(answer)

    l1 = ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9)))))))))
    sol.println(l1)
    l2 = ListNode(9, ListNode(9, ListNode(9, ListNode(9))))
    sol.println(l2)

    answer = sol.addTwoNumbers(l1, l2)
    sol.println(answer)

        
