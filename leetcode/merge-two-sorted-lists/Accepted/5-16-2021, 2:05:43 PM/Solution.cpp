// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode prehead = ListNode();
        ListNode* cur_node = &prehead;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1 -> val < l2 -> val)
            {
                cur_node -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                cur_node -> next = l2;
                l2 = l2 -> next;
            }
            cur_node = cur_node -> next;
        }
        if (l2)
            cur_node -> next = l2;
        else if (l1)
            cur_node -> next = l1;
        
        return prehead.next;

        
    }
};