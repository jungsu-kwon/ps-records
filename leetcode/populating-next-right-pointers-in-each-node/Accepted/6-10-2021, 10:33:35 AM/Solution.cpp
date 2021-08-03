// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

#include <iostream>
#include <vector>


class Solution {
public:
    Node* connect(Node* root) {
        // if root is nullptr return root
        if (!root) return root;

        vector<Node*> bfs;
        bfs.push_back(root);

        while (bfs.size())
        {
            vector<Node*> children;
            Node* prev = nullptr;
            for (int i = 0; i < bfs.size(); ++i)
            {
                auto node = bfs[i];
                auto left_child = node -> left;
                auto right_child = node -> right;

                if (prev) prev -> next = left_child;
                if (left_child) 
                {
                    left_child -> next = right_child;
                    prev = left_child;
                    children.push_back(left_child);
                }
                if (right_child) 
                {
                    prev = right_child;
                    children.push_back(right_child);
                }
            }
            bfs = children;
        }
        return root;
    }
};