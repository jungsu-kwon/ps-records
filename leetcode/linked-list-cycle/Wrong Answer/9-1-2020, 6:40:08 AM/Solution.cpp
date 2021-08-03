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
        ListNode *slowNode = head;
        ListNode *fastNode = head;
        
        while (fastNode != nullptr){
            if (fastNode == slowNode)
                return true;
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            if (fastNode == nullptr)
                return false;
            
        }
        return false;
        
        
    }
};