// https://leetcode.com/problems/count-univalue-subtrees

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
        if (!root) return false;
        return !root -> left && !root -> right;
    }
    bool is_uniform(TreeNode* root)
    {
        auto left = root -> left;
        if (left && root -> val != left -> val)
            return false;
        auto right = root -> right;
        if (right && root -> val != right -> val)
            return false;
        return true;
    }
    bool helper(TreeNode* root, int& count)
    {
        if (!root) return true;

        auto left_count = 0, right_count = 0;

        auto left_uniform  = helper(root -> left , left_count);
        auto right_uniform = helper(root -> right, right_count);
        if (left_uniform && right_uniform && is_uniform(root))
        {
            count =  left_count + right_count + 1;
            return true;
        }
        count = left_count + right_count;
        return false;


    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        helper(root,count);
        return count;
                
    }
};