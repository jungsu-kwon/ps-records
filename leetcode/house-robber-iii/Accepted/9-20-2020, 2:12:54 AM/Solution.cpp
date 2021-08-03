// https://leetcode.com/problems/house-robber-iii

class Solution {
private:
	std::vector<int> helper(TreeNode* root){
		if (root == nullptr){
			std::vector<int> vecAns{0,0};
			return vecAns;
		}

		auto vecLeft = helper(root->left);
		auto vecRight = helper(root->right);

		int rootExclude = vecLeft[0] + vecRight[0] ;
		int rootInclude = std::max(vecLeft[1] + vecRight[1] + root->val,rootExclude);

		return std::vector<int>{rootInclude,rootExclude};

	}
public:
    int rob(TreeNode* root) {
		auto vecAns = helper(root);
		return std::max(vecAns[0],vecAns[1]);
    }
};
