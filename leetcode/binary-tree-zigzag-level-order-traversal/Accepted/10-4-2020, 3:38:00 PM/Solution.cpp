// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

class Solution {
private : 
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> vecAns;
		if (root == nullptr) return vecAns;
		std::vector<TreeNode*> vecNodes{root};
		bool reverseLevel = false;

		while (vecNodes.size()){
			auto n = vecNodes.size();
			std::vector<TreeNode*> vecChildren;
			std::vector<int> vecLevel;
			if (reverseLevel) {
				for (auto it = vecNodes.rbegin(); it != vecNodes.rend(); ++it){
					vecLevel.push_back((*it)->val);
				}
			}
			else{
				for (auto it = vecNodes.begin(); it != vecNodes.end(); ++it){
					vecLevel.push_back((*it)->val);
				}
			}
			vecAns.push_back(vecLevel);
			for (auto node : vecNodes)
			{
				if (node->left != nullptr) vecChildren.push_back(node->left);
				if (node->right != nullptr) vecChildren.push_back(node->right);
			}
			reverseLevel = 1 - reverseLevel;
			vecNodes = vecChildren;
		}
		
		return vecAns;

        
    }
};
