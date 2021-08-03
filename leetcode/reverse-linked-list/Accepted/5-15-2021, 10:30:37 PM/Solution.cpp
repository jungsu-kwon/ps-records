// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        auto cur_node = head;

        while (cur_node -> next != nullptr)
            cur_node = cur_node -> next;

        auto tail = cur_node;

        while (head != tail)
        {
            cur_node = head;
            head = cur_node -> next;

            auto next_node = tail -> next;
            tail -> next = cur_node;
            cur_node -> next = next_node;
        }
        return tail;


        
    }
};