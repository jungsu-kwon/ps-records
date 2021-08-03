// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		std::sort(nums.begin(),nums.end());
		std::vector<std::vector<int>> vecAns;
		for (auto t = 0 ; t < nums.size();++t){
			if (t > 0 && nums[t] == nums[t-1]) continue;

			std::unordered_set<int> hash;
			for (auto s = t+1; s < nums.size();++s){
				auto target = -nums[t] - nums[s];
				auto itFound = hash.find(target);
				if (itFound != hash.end()){
					std::vector<int> vecTriplet{nums[t],nums[s],-nums[s]-nums[t]};
					vecAns.push_back(vecTriplet);
				}
				hash.insert(nums[s]);
			}
		}
		return vecAns;
    }
};
