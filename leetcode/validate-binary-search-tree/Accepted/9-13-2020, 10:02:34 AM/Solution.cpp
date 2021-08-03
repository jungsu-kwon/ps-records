// https://leetcode.com/problems/validate-binary-search-tree

class Solution {
private : 
	bool isValidBST(TreeNode* root, int minVal, int maxVal,bool compareMin, bool compareMax)
	{
		if (root == nullptr)
			return true;
		if (compareMin && root->val <= minVal)
			return false;
		if (compareMax && root->val >= maxVal)
			return false;

		auto leftCompareMin = compareMin;
		auto leftMax = root->val;
		auto leftValid = isValidBST(root->left,minVal,leftMax,leftCompareMin,true);
		if (! leftValid)
			return false;

		auto rightCompareMax = compareMax;
		auto rightMin = root->val;
		auto rightValid = isValidBST(root->right,rightMin,maxVal,true,rightCompareMax);

		return rightValid;
	}
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root,0,0,false,false);
	}
};
