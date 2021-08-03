// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

#include <vector>
#include <iostream>
#include <string>

using namespace std;


class Codec {
private : 
	int nNull = -10000;
public:

    // Encodes a tree to a single string.
	std::vector<int>  serialize(TreeNode* root) {
		std::vector<int> vecAns;
		if (root == nullptr) return vecAns;

		std::vector<TreeNode*> bfs{root};
        bool nValidBfs = true;
		while (nValidBfs){
            nValidBfs = false;
			auto bfsSize = bfs.size();
			std::vector<TreeNode*> vecChildren;
			for (auto node : bfs)
			{

				if (node == nullptr){
					vecChildren.push_back(nullptr);
					vecChildren.push_back(nullptr);
					vecAns.push_back(nNull);
				}
				else{
					vecChildren.push_back(node->left);
					vecChildren.push_back(node->right);
					vecAns.push_back(node->val);
                    if (node->left != nullptr || node->right != nullptr)
                        nValidBfs = true;
				}
			}
			bfs = vecChildren;
		}
		return vecAns;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::vector<int> data) {
		auto n = data.size();
		if (n == 0 ) return nullptr;
		TreeNode* root = new TreeNode(data[0]);
		std::vector<TreeNode*> vecParents{root};

		int nParentInd = 0;
		for (auto t = 1 ; t < data.size(); ++t){
			auto leftVal = data[t];
			auto rightVal = (t+1 >= data.size()) ? nNull : data[t+1];
			auto parentNode = vecParents[nParentInd] ; 
			if (parentNode != nullptr)
			{
				parentNode->left = (leftVal == nNull) ? nullptr : new TreeNode(leftVal);
				parentNode->right = (rightVal == nNull) ? nullptr : new TreeNode(rightVal);
				vecParents.push_back(parentNode->left);
				vecParents.push_back(parentNode->right);
			}
			else 
			{
				vecParents.push_back(nullptr);
				vecParents.push_back(nullptr);
			}

			t += 1 ;
			nParentInd += 1 ;
		}
		return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
