// https://leetcode.com/problems/swap-nodes-in-pairs

class Solution {
private:
    ListNode* helper(ListNode* head)
    {
        if (!head || !(head->next)) return head;
        auto next_node = head -> next;

        ListNode* temp = next_node -> next;
        next_node -> next = head;

        head -> next =  helper(temp);
        return next_node;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return helper(head);
        
    }
};