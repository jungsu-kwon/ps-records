// https://leetcode.com/problems/path-sum-iii

 
class Solution {
private : 
	int search(TreeNode* root, const std::unordered_set<int> &targets,const int sum){
		if (root == nullptr) return 0;
		auto numFound = 0 ;
		std::unordered_set<int> newTargets;
		for (auto target : targets){
			if (target == root->val) ++ numFound;
			newTargets.insert(target-root->val);
		}
        newTargets.insert(sum);
		numFound += search(root->left,newTargets,sum);
		numFound += search(root->right,newTargets,sum);

		return numFound;
	}
public:
    int pathSum(TreeNode* root, int sum) {
		std::unordered_set<int> targets;
		targets.insert(sum);
		return search(root,targets,sum);
    }
};
