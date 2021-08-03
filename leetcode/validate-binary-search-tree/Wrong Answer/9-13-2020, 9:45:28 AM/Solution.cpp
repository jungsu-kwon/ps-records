// https://leetcode.com/problems/validate-binary-search-tree

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root == nullptr)
			return true;
		auto leftValid = (root->left == nullptr) ? true : (root->left->val < root->val && 
														   isValidBST(root->left));
		auto rightValid = (root->right == nullptr) ? true: (root->right->val > root->val &&
														   isValidBST(root->right));
		if (leftValid && rightValid)
			return true;
		return false;
	}
};
