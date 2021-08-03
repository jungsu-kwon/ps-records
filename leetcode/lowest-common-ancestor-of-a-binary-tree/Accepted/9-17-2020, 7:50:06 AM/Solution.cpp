// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

class Solution {
private : 
	bool LCA(TreeNode* root, int p, int q, bool &pFound, bool &qFound,TreeNode* &nodeLCA){
		if (root == nullptr) return false;
		bool leftP = false, leftQ = false;
		bool rightP = false, rightQ = false;

		if (LCA(root->left,p,q,leftP,leftQ,nodeLCA))
			return true;
		else if (LCA(root->right,p,q,rightP,rightQ,nodeLCA))
			return true;
		pFound = leftP || rightP || root->val == p;
		qFound = leftQ || rightQ || root->val == q;

		if (pFound && qFound)
		{
			nodeLCA = root;
			return true;
		}
		return false;
	}


public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* nodeLCA = nullptr;
		bool pFound=false;
		bool qFound=false;
		LCA(root,p->val,q->val,pFound,qFound,nodeLCA);

		return nodeLCA;
	}
};
