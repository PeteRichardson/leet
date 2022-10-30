#include <iostream>

using std::cout, std::endl;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr;
        ListNode *tail = nullptr;
        int carry = 0;

        while (l1 or l2 or carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum >= 10 ? 1 : 0;
            auto temp = new ListNode(sum % 10, nullptr);
            if (!result) {
                result = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = tail->next;
            }
        }
        return result;
    }

    void dump(ListNode* l) {   
        cout << "[";
        for (; l ; l = l->next)
            cout << l->val << (l->next ? "," : "]");
    }
};

int main() {
    auto sol = Solution{};
    ListNode *x1 = new ListNode(3);
    ListNode *x2 = new ListNode(4, x1);
    ListNode *x  = new ListNode(2, x2);
    sol.dump(x);
    ListNode *y1 = new ListNode(4);
    ListNode *y2 = new ListNode(6, y1);
    ListNode *y  = new ListNode(5, y2);
    sol.dump(y);

    auto result =  sol.addTwoNumbers(x, y);
    sol.dump(result);

    auto result2 = sol.addTwoNumbers(new ListNode(0), new ListNode(0));
    sol.dump(result2);

    delete x1;
    delete x2;
    delete x;
    delete y1;
    delete y2;
    delete y;
    cout << endl;
}