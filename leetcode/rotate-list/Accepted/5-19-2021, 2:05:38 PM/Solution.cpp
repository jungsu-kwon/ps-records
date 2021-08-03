// https://leetcode.com/problems/rotate-list

#include <queue>
#include <iostream>
using namespace std;
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
private:
    int get_length(ListNode* head,ListNode* &tail)
    {
        auto cur = head;
        int count = 0;
        while (cur)
        {
            count++;
            tail = cur;
            cur = cur -> next;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        auto tail = head;
        auto n = get_length(head,tail);
        auto rotate = n - k % n;

        tail -> next = head;
        auto prehead = tail;
        for (auto i = 0; i < rotate; ++i)
            prehead = prehead -> next;
        
        head = prehead -> next;
        prehead -> next = nullptr;
        return head;


    }
};