// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

class Solution {
private : 
	TreeNode* helper(vector<int> &nums,int left, int right){
		if (left > right) return nullptr;
		if (left == right) return new TreeNode(nums[left]);

		int rootInd = (left + right) / 2; 
		auto root = new TreeNode(nums[rootInd]);

		auto leftTree = helper(nums,left,rootInd -1);
		auto rightTree = helper(nums,rootInd + 1, right);

		root->left = leftTree;
		root->right =rightTree;

		return root;

	}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums,0,nums.size()-1);
    }
};
