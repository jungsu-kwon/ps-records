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
    bool is_leaf(TreeNode* root)
    {
        return !root->left && !root -> right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (is_leaf(root)) return root -> val == targetSum;
        auto new_target = targetSum - root -> val;
        return hasPathSum(root->left, new_target) || hasPathSum(root->right, new_target);

    }
};