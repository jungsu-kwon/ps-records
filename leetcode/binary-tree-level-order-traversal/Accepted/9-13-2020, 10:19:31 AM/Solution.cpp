// https://leetcode.com/problems/binary-tree-level-order-traversal

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		std::vector<std::vector<int>> vecAns;

		if (root == nullptr) {
			return vecAns;
		}

		std::vector<TreeNode*> vecNodes{root};
		while (vecNodes.size() != 0){
			auto numNodes = vecNodes.size();
			std::vector<TreeNode*> vecChildren{};
			std::vector<int> vecLevel;
			for (auto node : vecNodes){
				vecLevel.push_back(node->val);
				if (node->left != nullptr)
					vecChildren.push_back(node->left);
				if (node->right != nullptr)
					vecChildren.push_back(node->right);
			}
			vecNodes = vecChildren;
            vecAns.push_back(vecLevel);
		}
		return vecAns;
	}
};
