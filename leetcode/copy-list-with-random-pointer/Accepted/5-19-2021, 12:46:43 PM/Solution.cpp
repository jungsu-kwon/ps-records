// https://leetcode.com/problems/copy-list-with-random-pointer

#include <unordered_map>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        auto cur_node = head;
        auto new_head = new Node(0);
        auto new_node = new_head;

        auto hash = unordered_map<Node*,Node*>();

        while (cur_node)
        {
            // deal with new_node
            new_node -> val = cur_node -> val;
            new_node -> random = cur_node -> random;

            hash[cur_node] = new_node;

            cur_node = cur_node -> next;
            
            if (cur_node)
            {
                new_node -> next = new Node(0);
                new_node = new_node -> next;
            }    

        }

        cur_node = new_head;
        while (cur_node)
        {
            cur_node -> random = hash[cur_node -> random];
            cur_node = cur_node -> next;
        }
        return new_head;
        
    }
};