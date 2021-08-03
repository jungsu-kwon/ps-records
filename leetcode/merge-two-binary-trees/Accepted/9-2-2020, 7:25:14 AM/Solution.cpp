// https://leetcode.com/problems/merge-two-binary-trees

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
            return nullptr;
        else if (t1 == nullptr || t2 == nullptr){
            // non nullptr node
            TreeNode* t3 = (t1 == nullptr) ? t2 : t1;
            TreeNode *root = new TreeNode(t3->val);
            root->left = mergeTrees(t3->left,nullptr);
            root->right = mergeTrees(t3->right,nullptr);
            return root;
        }
        else{
            // no nullptr in t1 and t2
            TreeNode *root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left,t2->left);
            root->right = mergeTrees(t1->right,t2->right);
            return root;
        }
    }
};