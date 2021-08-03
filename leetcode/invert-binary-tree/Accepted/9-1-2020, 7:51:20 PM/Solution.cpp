// https://leetcode.com/problems/invert-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        
        // init variables
        TreeNode *leftTree = root->left;
        TreeNode *rightTree = root->right;
        
        // swap right subtree and right subtree
        root->right = leftTree;
        root->left = rightTree;
        
        // invert each subtree
        invertTree(root->right);
        invertTree(root->left);
        return root;
        
    }
};