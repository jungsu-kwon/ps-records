// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		std::sort(candidates.begin(),candidates.end());
		std::vector<std::vector<int>> vecAns;
		std::vector<int> combination;
        combinationSum(candidates,target,vecAns,combination,0);
        return vecAns;

	}
	void combinationSum(std::vector<int> &candidates,int target ,std::vector<std::vector<int>> &res,std::vector<int> &combination,int begin){
		if (!target) {
			res.push_back(combination); 
			return;
		}

		for (auto i = begin; i < candidates.size() && candidates[i] <= target; ++i){
			combination.push_back(candidates[i]);
			combinationSum(candidates,target-candidates[i], res,combination,i);
			combination.pop_back();
		}
		return;
    }
};
