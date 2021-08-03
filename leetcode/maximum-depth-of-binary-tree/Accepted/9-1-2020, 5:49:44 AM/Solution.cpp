// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    bool isLeaf(TreeNode* root){
        return (root->left == nullptr && root->right == nullptr);
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int right_depth = maxDepth(root->left);
        int left_depth = maxDepth(root->right);
        return std::max(left_depth,right_depth) + 1 ;
        
        
        
    }
};