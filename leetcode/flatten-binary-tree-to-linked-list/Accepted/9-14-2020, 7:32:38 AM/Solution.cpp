// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

class Solution {
private : 
	TreeNode *flattenTree(TreeNode* root){
		auto leftNode = root->left;
		auto rightNode = root->right;
		auto retNode = root;
        root->left = nullptr;

		if (leftNode != nullptr) 
		{
			auto leftEnd =  flattenTree(leftNode);
			root->right = leftNode;
			retNode = leftEnd;
		}
		if (rightNode != nullptr)
		{
			auto rightEnd = flattenTree(rightNode);
			retNode->right = rightNode;
			retNode = rightEnd;

		}

        return retNode;

	}
public:
	void flatten(TreeNode* root) {
        if (root == nullptr) return;
		flattenTree(root);
    }
};
