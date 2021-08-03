// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

#include <string>
#include <iostream>
#include <queue>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "x";

        string left_tree  = serialize(root -> left);
        string right_tree = serialize(root -> right);
        return to_string(root->val) + "," + left_tree + "," + right_tree;
    }

    TreeNode* helper(queue<string> &q)
    {
        if (!q.size()) return nullptr;
        
        auto word = q.front();
        q.pop();

        if (word == "x") return nullptr;
        TreeNode* root = new TreeNode(stoi(word));
        TreeNode* left  = helper(q);
        TreeNode* right = helper(q);

        root -> left  = left;
        root -> right = right;

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string word = "";
        for (char ch : data)
        {
            if (ch == ',')
            {
                q.push(word);
                word = "";
            }

            else word += ch;
        }

        return helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));