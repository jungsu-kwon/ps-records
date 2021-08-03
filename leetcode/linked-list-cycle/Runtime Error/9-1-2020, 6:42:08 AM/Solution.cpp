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
        ListNode *slowNode = head->next;
        ListNode *fastNode = head->next;
        if (fastNode == nullptr)
            return false;
        fastNode = fastNode->next;
        
        while (fastNode != nullptr){
            if (fastNode == slowNode)
                return true;
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            if (fastNode == nullptr)
                return false;
            fastNode = fastNode->next;
            
        }
        return false;
        
        
    }
};