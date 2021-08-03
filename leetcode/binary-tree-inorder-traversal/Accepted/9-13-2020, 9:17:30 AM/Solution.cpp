// https://leetcode.com/problems/binary-tree-inorder-traversal

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
private : 
	void traversal(TreeNode* root,std::vector<int> &vecAns){
		if (root == nullptr)
			return ;
		traversal(root->left,vecAns);
		vecAns.push_back(root->val);
		traversal(root->right,vecAns);
		return ;
	}
public:
	vector<int> inorderTraversal(TreeNode* root) {
		std::vector<int> vecAns;
		traversal(root,vecAns);
		return vecAns;
	}
};
