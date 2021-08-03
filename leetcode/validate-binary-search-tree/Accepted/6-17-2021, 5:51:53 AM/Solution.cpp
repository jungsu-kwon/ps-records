// https://leetcode.com/problems/validate-binary-search-tree


class Solution {
private:
    bool helper(TreeNode* root,int min, int max, bool mask_min, bool mask_max)
    {
        if (!root) return true;
        if (!mask_min && root -> val <= min) return false;
        if (!mask_max && root -> val >= max) return false;

        return helper(root -> left, min, root->val,mask_min,false) &&
               helper(root -> right, root -> val, max,false, mask_max);

    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,0,0,true,true);
    }
};