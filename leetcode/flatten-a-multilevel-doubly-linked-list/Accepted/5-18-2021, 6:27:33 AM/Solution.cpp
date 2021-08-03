// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

#include <iostream>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node* helper(Node* head)
    {
        if (!head) return nullptr;

        auto cur_node = head;
        auto tail = head;
        
        while(cur_node)
        {
            if (cur_node -> child)
            {
                auto child = cur_node -> child;
                auto new_tail = helper(child);
                auto ori_next = cur_node -> next;

                new_tail -> next = ori_next;
                if (ori_next)
                    ori_next -> prev = new_tail;

                child -> prev = cur_node;
                cur_node -> next = child;

                cur_node -> child = nullptr;
                tail = new_tail;
                cur_node = ori_next;
                

            }
            else
            {
                tail = cur_node;
                cur_node = cur_node -> next;
            }


        }
        return tail;
    }
public:
    Node* flatten(Node* head) {
        helper(head);


        return head;
        
    }
};