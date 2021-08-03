// https://leetcode.com/problems/serialize-and-deserialize-binary-tree



class Codec {
private :
	int nNull = -10000;
public:

    // Encodes a tree to a single string.
	std::string  serialize(TreeNode* root) {
		std::string strAns;
		if (root == nullptr) return strAns;
		std::queue<TreeNode*> bfs;
		bfs.push(root);

		bool isValidBfs = true;
		while (bfs.size())
		{
			auto bfsSize = bfs.size();
			for(auto t = 0; t < bfsSize; ++t){
				auto node= bfs.front();
				bfs.pop();
				if (node != nullptr){
					strAns += std::to_string(node->val) + ",";
                    bfs.push(node->left);
                    bfs.push(node->right);
				}
				else {
					strAns += "n,";
				}

			}
		}

		strAns.erase(strAns.find_last_not_of("n,")+1);
        return strAns;
    }
	int findInt(std::string &strTree,int &start){
		if (start == strTree.npos) return nNull;
		
        auto end = strTree.find(',',start);
        std::string strSub;
		if (end == strTree.npos)
		{
            strSub = strTree.substr(start);
            start = end;
		}
        else {
            strSub = strTree.substr(start,end-start);
            start = end + 1;
        }
		if (strSub == "n"){
		   	return nNull;
		}
		else {
			int ret = std::stoi(strSub);
			return  ret;
		}
	}


    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string strTree) {
        //std::cout << strTree << std::endl;
		auto n = strTree.size();
		if (n == 0 ) return nullptr;

		int start = 0;
		TreeNode* root = new TreeNode(findInt(strTree,start));
		std::queue<TreeNode*> queueParents;
		queueParents.push(root);

		int nParentInd = 0;
		while (start != strTree.npos){
			int leftVal = findInt(strTree,start);
			int rightVal = findInt(strTree,start);
			auto parentNode = queueParents.front() ;
			queueParents.pop();
			if (parentNode != nullptr)
			{
				parentNode->left = (leftVal == nNull) ? nullptr : new TreeNode(leftVal);
				parentNode->right = (rightVal == nNull) ? nullptr : new TreeNode(rightVal);
				if (parentNode->left) queueParents.push(parentNode->left);
				if (parentNode->right) queueParents.push(parentNode->right);
			}
            

		}
		return root;

    }
};