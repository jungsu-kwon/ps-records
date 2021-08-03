// https://leetcode.com/problems/remove-nth-node-from-end-of-list

#include <queue>
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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> nodes;
        auto cur_node = head;
        while (cur_node != nullptr)
        {
            nodes.push(cur_node);
            if (nodes.size() == n + 2)
                nodes.pop();
            cur_node = cur_node -> next;
        }
        if (nodes.size() == n)
            return head->next;
        
        auto pre_node = nodes.front();
        nodes.pop();
        auto node = nodes.front();
        nodes.pop();
        auto post_node = nodes.front();
        nodes.pop();

        pre_node -> next = post_node;

        return head;




        
    }
};