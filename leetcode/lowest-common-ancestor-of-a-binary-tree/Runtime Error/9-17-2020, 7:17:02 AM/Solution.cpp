// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree



class Solution {
private : 
	bool search(TreeNode* root,int target,std::vector<TreeNode*> &path){
		if (root == nullptr) return false;
		if (root->val == target || search(root->left,target,path) || search(root->right,target,path))
		{
			path.push_back(root);
			return true;
		}
		return false;
	}


public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		std::vector<TreeNode*> pPath;
		std::vector<TreeNode*> qPath;
		search(root,p->val,pPath);
		search(root,q->val,qPath);

		auto qIt = qPath.rbegin();
		auto pIt = pPath.rbegin();
		TreeNode* prevNode = *qIt;

		while (*pIt == *qIt){
			prevNode = *qIt;
			++pIt;
			++qIt;
		}


		return prevNode;
	}
};
