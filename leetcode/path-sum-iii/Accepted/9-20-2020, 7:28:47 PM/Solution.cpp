// https://leetcode.com/problems/path-sum-iii

 
class Solution {
private : 
	int search(TreeNode* root, const std::vector<int> &targets,const int sum){
		if (root == nullptr) return 0;
		auto numFound = 0 ;
		std::vector<int> newTargets;
		for (auto target : targets){
			if (target == root->val) ++ numFound;
			newTargets.push_back(target-root->val);
		}
        newTargets.push_back(sum);
		numFound += search(root->left,newTargets,sum);
		numFound += search(root->right,newTargets,sum);

		return numFound;
	}
public:
    int pathSum(TreeNode* root, int sum) {
		std::vector<int> targets;
		targets.push_back(sum);
		return search(root,targets,sum);
    }
};
