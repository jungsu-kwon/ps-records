// https://leetcode.com/problems/kth-smallest-element-in-a-bst

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root -> left == nullptr){
            if (k == 1 )
                return root->val;
            else 
                return kthSmallest(root->right,k-1);

        }
        auto nLeftSize = nTreeSize(root->left);
        auto nRightSize = nTreeSize(root->right);

        if (k<=nLeftSize)
            return kthSmallest(root->left,k);
        else if (k == nLeftSize+1)
            return root->val;
        else 
            return kthSmallest(root->right,k-nLeftSize-1);
    }
private:
    int nTreeSize(TreeNode* root){
        if (root == nullptr)
            return 0;
        return nTreeSize(root->left) + nTreeSize(root->right) + 1;
    }
};