// https://leetcode.com/problems/palindrome-linked-list

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
    ListNode* reverse_list(ListNode* head)
    {
        if (head == nullptr) return head;
        auto cur_node = head;
        while (cur_node -> next != nullptr)
        {
            cur_node = cur_node -> next;
        }
        auto tail = cur_node;

        while (head != tail)
        {
            auto next_node = head -> next;
            head -> next = tail -> next;
            tail -> next = head;
            head = next_node;
        }
        return head;
    }
    ListNode* get_node(ListNode* head, int index)
    {
        auto node = head;
        for (auto i = 0; i < index; ++i)
        {
            node = node -> next;
        }
        return node;
    }
public:
    bool isPalindrome(ListNode* head) {
        auto cur_node = head;
        int len = 0;
        while (cur_node != nullptr)
        {
            cur_node = cur_node -> next;
            len++;
        }
        

        auto head2 = reverse_list(get_node(head,(len+1)/2));
        cur_node = head;
        auto cur_node2 = head2;

        while (cur_node2 != nullptr)
        {
            if (cur_node -> val != cur_node2 -> val)
                return false;
            cur_node = cur_node -> next;
            cur_node2 = cur_node2 -> next;
        }

        return true;


        
    }
};