// https://leetcode.com/problems/reverse-linked-list

class Solution {
private:
    void helper(ListNode* head, ListNode* tail)
    {
        if (head == tail) return;

        ListNode* new_head = head -> next;
        head -> next = tail -> next;
        tail -> next = head;

        helper(new_head,tail);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;

        ListNode* tail = head;
        while (tail->next)
        {
            tail = tail -> next;
        }
        helper(head,tail);
        return tail;

        
    }
};