// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };

class Solution {
public:
    Node* connect(Node* root) {
        // if root is nullptr return root
        if (!root) return root;

        queue<Node*> bfs;
        bfs.push(root);

        while (bfs.size())
        {
            Node* prev = nullptr;
            auto bfs_size = bfs.size();
            for (int i = 0; i < bfs_size; ++i)
            {
                auto node = bfs.front();
                bfs.pop();

                auto left_child = node -> left;
                auto right_child = node -> right;

                if (prev) prev -> next = left_child;
                if (left_child) 
                {
                    left_child -> next = right_child;
                    prev = left_child;
                    bfs.push(left_child);
                }
                if (right_child) 
                {
                    prev = right_child;
                    bfs.push(right_child);
                }
            }
        }
        return root;
    }
};