// https://leetcode.com/problems/path-sum

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
private:
    bool helper(TreeNode* root,int target_sum)
    {
        if (!root)  return target_sum == 0;
        auto new_target = target_sum - root->val;
        return helper(root -> left,new_target) ||\
         helper(root -> right,new_target );
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return helper(root,targetSum);
    }
};