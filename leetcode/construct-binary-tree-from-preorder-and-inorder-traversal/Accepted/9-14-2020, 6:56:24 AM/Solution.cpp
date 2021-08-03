// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal


class Solution {
public:
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder, int preStart,int preEnd, int inStart,int inEnd){
		if (inStart > std::min(inEnd,int(inorder.size()-1)) || preStart >std::min( preEnd,int(preorder.size()-1))) return nullptr;
		auto root = new TreeNode(preorder[preStart]);
		// preorder root,l,l,l,l,l,l,l,l,l,r,r,r,r,r,r
		// inorder l,l,l,l,l,l,l,l, root ,r,r,r,r,r,r
		int rootInd = find(inorder.begin() + inStart, inorder.begin() + inEnd,preorder[preStart]) - inorder.begin();
		int treeSize = inEnd - inStart  + 1 ; 
		int leftSize = rootInd - inStart;
		int rightSize = treeSize - leftSize; 

		auto leftRoot = buildTree(preorder,inorder,preStart +1,preStart+1 + leftSize-1,inStart,inStart + leftSize -1);
		auto rightRoot = buildTree(preorder,inorder,preStart + leftSize + 1, preEnd, inStart + leftSize + 1,  inEnd);

		root->left = leftRoot;
		root->right = rightRoot;
		return root;

	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
	}
};
