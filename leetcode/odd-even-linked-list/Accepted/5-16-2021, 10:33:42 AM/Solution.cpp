// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode even_head = ListNode();

        auto even = &even_head;
        auto odd =  head;

        auto cur_node = head;

        auto is_even = false;
        while (cur_node != nullptr)
        {
            if (is_even)
            {
                odd  -> next = cur_node -> next;
                even -> next = cur_node;
                even = cur_node;
            }
            else
            {
                odd = cur_node;
            }
            is_even = !is_even;
            cur_node = cur_node -> next;
        }
        odd  -> next = even_head.next;
        even -> next = nullptr;
        
        return head;

        
    }
};