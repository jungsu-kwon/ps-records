// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int get_length(ListNode* head)
    {
        auto cur_node = head;
        int length = 0;
        while (cur_node != nullptr)
        {
            length++;
            cur_node = cur_node->next;
        }
        return length;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto len_a = get_length(headA);
        auto len_b = get_length(headB);

        auto offset_a = max(0,len_a - len_b);
        auto offset_b = max(0,len_b - len_a);

        auto start_a = headA;
        auto start_b = headB;

        for (auto i = 0; i < offset_a; ++i)
            start_a = start_a -> next;

        for (auto i = 0; i < offset_b; ++i)
            start_b = start_b -> next;
        
        while (start_a != nullptr && start_b != nullptr)
        {
            if (start_a == start_b)
                return start_a;

            start_a = start_a -> next;
            start_b = start_b -> next;
        }
        return nullptr;

        
    }
};