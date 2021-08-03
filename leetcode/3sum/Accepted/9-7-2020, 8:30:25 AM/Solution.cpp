// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		std::sort(nums.begin(),nums.end());
		std::vector<std::vector<int>> vecAns;
		for (auto t = 0 ; t < nums.size();++t){
			if (t > 0 && nums[t] == nums[t-1]) continue;
			auto l = t+1; 
			auto r = nums.size()-1;
			while ( l < r ){
				auto threeSum = nums[l] + nums[r] + nums[t];
                if (l> t+1 && nums[l] == nums[l-1] ){
                    ++l ;
                    continue;
                };
				if (threeSum == 0){
					std::vector<int> vecTriplet{nums[l],nums[r],nums[t]};
					vecAns.push_back(vecTriplet);
                    ++l;
				}
				else if(threeSum < 0){
                    ++l;
				}
				else
				{
                    --r;
				}
			}

		}
		return vecAns;
    }
};