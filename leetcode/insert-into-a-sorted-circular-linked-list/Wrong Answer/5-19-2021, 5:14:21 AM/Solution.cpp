// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list

#include <iostream>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) return new Node(insertVal);
        auto tail = head;
        auto new_head = tail->next;
        tail -> next = nullptr;

        auto cur_node = new_head;
        Node* next_node = nullptr;
        Node* insert_node = new Node(insertVal);
        
        auto inserted = false;
        while (cur_node)
        {
            auto left = cur_node -> val;
            next_node = cur_node -> next;
            auto right = next_node ? next_node -> val : new_head -> val;

            if (left <= right)
            {
                if (insertVal >= left && insertVal <= right)
                {
                    cur_node -> next = insert_node;
                    insert_node -> next = next_node;
                    inserted = true;
                    break;
                }
            }
            else
            {
                if (insertVal >= left || insertVal <= right)
                {
                    cur_node -> next = insert_node;
                    insert_node -> next = next_node;
                    inserted = true;
                    break;
                }

            }
            cur_node = cur_node -> next;

        }

        while (tail->next)
        {
            tail = tail -> next;
        }
        if (!inserted) 
        {
            tail -> next = insert_node;
            tail = insert_node;
        }

        tail -> next = new_head;
        return head;
    }
};