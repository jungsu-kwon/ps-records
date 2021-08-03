// https://leetcode.com/problems/add-two-numbers

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *preHead = new ListNode(0);
        ListNode *curNode = preHead;
        auto carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry > 0){
            auto nodeVal = ( (l1 == nullptr) ? 0 : l1->val ) +
                           ((l2 ==nullptr)? 0:l2->val) + carry;
            carry = nodeVal/10;
            nodeVal = nodeVal % 10;

            curNode->next = new ListNode(nodeVal);
            curNode = curNode->next;
            l1 = (l1 == nullptr) ? nullptr : l1->next;
            l2 = (l2 == nullptr) ? nullptr : l2->next;
        }
        return preHead->next;
    }
};
