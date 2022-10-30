public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}

extension ListNode : CustomStringConvertible {
    public var description : String {
        var digits = Array<Int>()
        var n : ListNode? = self
        while n != nil {
            if let j = n?.val {
                digits.append(j)
            }
            n = n?.next
        }
        return "[\(digits.map{String($0)}.joined(separator: ","))]"
    }
}
 
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var result : ListNode? = nil
        var tail : ListNode? = nil
        var carry : Int = 0

        var l1c = l1
        var l2c = l2

        while (l1c != nil || l2c != nil || carry == 1) {
            var sum = carry
            if l1c != nil {
                sum += l1c!.val
                l1c = l1c!.next
            }  
            if l2c != nil {
                sum += l2c!.val
                l2c = l2c!.next
            }            
            carry = (sum >= 10) ? 1 : 0
            var temp = ListNode(sum % 10)
            
            if result == nil {
                result = temp
                tail = temp
            } else {
                tail?.next = temp
                tail = temp
            }
        }
        if carry != 0 {
            tail?.next = ListNode(1, nil)
        }

        return result;
    }

}

let sol: Solution = Solution()

let l1: ListNode = ListNode(2, ListNode(4, ListNode(3)))
print(l1)
let l2: ListNode = ListNode(5, ListNode(6, ListNode(4)))
print(l2)
if let answer: ListNode = sol.addTwoNumbers(l1, l2) {
    print(answer)
}
