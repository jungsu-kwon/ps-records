// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;

        while (fast != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next ? fast -> next -> next : nullptr;
            if (slow && slow == fast)
                return true;
        }
        return false;
        
    }
};