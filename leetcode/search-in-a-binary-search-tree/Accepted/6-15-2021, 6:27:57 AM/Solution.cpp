// https://leetcode.com/problems/search-in-a-binary-search-tree


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return root;

        if (root -> val == val) return root;

        TreeNode* left_res = searchBST(root -> left, val);
        if (left_res) return left_res;

        TreeNode* right_res = searchBST(root -> right, val);
        if (right_res) return right_res;

        return nullptr;
        
    }
};