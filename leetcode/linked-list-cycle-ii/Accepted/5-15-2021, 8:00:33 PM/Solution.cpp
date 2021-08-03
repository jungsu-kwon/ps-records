// https://leetcode.com/problems/linked-list-cycle-ii

#include <iostream>
using namespace std;
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
    ListNode *detectCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;

        ListNode* meeting_point = nullptr;
        while (fast != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next ? fast -> next -> next : nullptr;
            if (slow != nullptr && fast == slow)
            {
                meeting_point = slow;
                break;
            }

        }

        if (meeting_point == nullptr)
            return nullptr;
        
        auto from_head = head;
        auto from_meet = meeting_point;

        while (from_head != from_meet)
        {
            from_head = from_head -> next;
            from_meet = from_meet -> next;
        }
        return from_head;
        

        
    }
};