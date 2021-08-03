// https://leetcode.com/problems/partition-equal-subset-sum

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
		auto sum = std::accumulate(nums.begin(),nums.end(),0);
		if (sum % 2 == 1)
			return false;
		auto target = sum / 2 ; 
		std::vector<bool> prevDp(target+1,false);
		std::vector<bool> dp(target+1,false); 
        prevDp[0] = true;

		for (auto t = 0; t < nums.size(); ++t){
			std::fill(dp.begin(), dp.end(), false);
            dp[0] = true;
			for (auto i = 0; i < target+1; ++i){
				dp[i] = ( i >= nums[t]) ? prevDp[i] || prevDp[i-nums[t]] : prevDp[i];
			}
			prevDp = dp;
			if (dp.back())
				return true;
		}
		return dp.back();
    }
};
