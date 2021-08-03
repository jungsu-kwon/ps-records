// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        auto cur_node = head;
        ListNode* prev_node = nullptr;

        while (cur_node != nullptr)
        {
            if (cur_node -> val == val)
            {
                if (prev_node != nullptr)
                    prev_node -> next = cur_node -> next;
                else
                    head = head -> next;
            }
            else
            {
                prev_node = cur_node;
            }
            cur_node = cur_node -> next;
        }
        return head;
        
    }
};