// https://leetcode.com/problems/merge-two-sorted-lists

class Solution {
private:
    void helper(ListNode* cur_node, ListNode* l1, ListNode* l2)
    {
        if (l1 && l2)
        {
            if (l1 -> val < l2 -> val)
            {
                cur_node -> next = l1;
                helper(cur_node -> next, l1 -> next, l2);
                return;
            }
            cur_node -> next = l2;
            helper(cur_node -> next, l1, l2 -> next);
        }
        else if (l1) cur_node -> next = l1;
        else if (l2) cur_node -> next = l2;

    }
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto prehead = ListNode(0);

        helper(&prehead,l1,l2);
        return prehead.next;



        
    }
};