// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		std::vector<std::vector<int>> vecAns;
		std::vector<int> perm;
		std::unordered_set<int> used;

		permute(vecAns,nums,perm,used);
		return vecAns;
        
    }
	void permute(std::vector<std::vector<int>> &res,std::vector<int> &nums,std::vector<int> &perm,std::unordered_set<int> &used){
		if (used.size() == nums.size()){
			res.push_back(perm);
			return;
		}
		for (auto t = 0; t < nums.size(); ++t){
			if ( used.find(nums[t]) == used.end()){
				perm.push_back(nums[t]);
				used.insert(nums[t]);
				permute(res,nums,perm,used);
				used.erase(nums[t]);
				perm.pop_back();
			}
		}
	}
};