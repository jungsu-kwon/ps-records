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

        auto left_tree  = serialize(root -> left);
        auto right_tree = serialize(root -> right);
        // cout << to_string(root->val) + "," + left_tree + "," + right_tree << endl; 
        return to_string(root->val) + "," + left_tree + "," + right_tree;
    }

    TreeNode* helper(queue<string> &q)
    {
        if (!q.size()) return nullptr;
        
        auto word = q.front();
        q.pop();

        if (word == "x") return nullptr;
        auto root = new TreeNode(stoi(word));
        auto left  = helper(q);
        auto right = helper(q);

        root -> left  = left;
        root -> right = right;

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string word = "";
        // cout << data << endl;
        for (auto ch : data)
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