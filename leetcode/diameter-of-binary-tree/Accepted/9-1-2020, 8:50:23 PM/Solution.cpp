// https://leetcode.com/problems/diameter-of-binary-tree

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
    int nDiameter = 0;
    int computeDepth(TreeNode* root){
        if (root == nullptr)
            return -1;
        int nLeftDepth = computeDepth(root->left)+1;
        int nRightDepth = computeDepth(root->right)+1;
        
        nDiameter = std::max(nDiameter,nLeftDepth+nRightDepth);
        return std::max(nLeftDepth,nRightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       computeDepth(root); 
       return nDiameter;
    }
};