// https://leetcode.com/problems/symmetric-tree

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
    bool isLeaf(TreeNode *root){
        return (root->left == nullptr && root->right == nullptr);
    }
    bool isSymmetric(TreeNode* root) {
        if ( root == nullptr||isLeaf(root) )
            return true;
        if (root->right == nullptr || root->left == nullptr )
            return false;
        if (root->right->val == root->left->val){
            return (isSymmetric(root->left->left,root->right->right) && 
                isSymmetric(root->right->left,root->left->right));
        }
        return false;
    }
    bool isSymmetric(TreeNode* root1,TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr){
           return true;
        }
        else if (root1 == nullptr || root2 == nullptr)
            return false;
        if (root1->val == root2->val){
            return (isSymmetric(root1->left,root2->right) && isSymmetric(root1->right,root2->left));
        }
        return false;
        
          
        
    }
      
};