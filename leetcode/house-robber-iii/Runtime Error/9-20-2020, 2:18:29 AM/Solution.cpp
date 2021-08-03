// https://leetcode.com/problems/house-robber-iii

class Solution {
private:
	void helper(TreeNode* root ,int &rootExclude, int &rootInclude){
		int leftRootIn = 0, leftRootEx;
		int rightRootIn = 0, rightRootEx;

		if (root == nullptr){
			return;
		}


		helper(root->left,leftRootEx,leftRootIn);
		helper(root->right,rightRootEx,rightRootIn);

		rootExclude = leftRootIn + rightRootIn;
		rootInclude = std::max(leftRootEx + rightRootEx + root->val,rootExclude);

	}
public:
    int rob(TreeNode* root) {
		int rootInclude = 0 ; 
		int rootExclude = 0 ;
		helper(root,rootExclude,rootInclude);
		return std::max(rootExclude,rootInclude);
    }
};
