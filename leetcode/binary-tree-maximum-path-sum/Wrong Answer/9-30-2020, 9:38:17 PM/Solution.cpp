// https://leetcode.com/problems/binary-tree-maximum-path-sum

class Solution {
private : 
	int helper(TreeNode* root, int &maxSum){
		if (root == nullptr) return 0;

		auto leftSum = helper(root->left,maxSum);
		auto rightSum = helper(root->right,maxSum);

		maxSum = std::max(maxSum,root->val + std::max(leftSum,0) + std::max(rightSum,0));
		return std::max(leftSum,rightSum) + root->val; 
	}
public:
    int maxPathSum(TreeNode* root) {
		if (root == nullptr) return 0;
		int maxSum = root->val;
		helper(root,maxSum);
		return maxSum;
		
        
    }
};
