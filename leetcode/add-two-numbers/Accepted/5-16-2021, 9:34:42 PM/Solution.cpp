// https://leetcode.com/problems/add-two-numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto n1 = l1;
        auto n2 = l2;
        auto carry = 0;

        ListNode* tail = nullptr;

        while (n1 && n2)
        {
            auto sum = n1 -> val + n2 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;

            n1 -> val = sum;

            tail = n1;
            n1 = n1 -> next;
            n2 = n2 -> next;
        }

        if (n2)
        {
            tail -> next = n2;
            n1 = n2;
        }

        while (carry && n1)
        {
            auto sum = n1 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;

            n1 -> val = sum;

            tail = n1;
            n1 = n1 -> next;
        }
        if (carry)
            tail -> next = new ListNode(carry);
        return l1;


        
        
        

        return l1;
        
    }
};