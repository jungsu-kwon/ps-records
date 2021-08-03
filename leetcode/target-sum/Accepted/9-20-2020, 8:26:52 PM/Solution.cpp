// https://leetcode.com/problems/target-sum

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
		std::unordered_map<int,int> dp;
		std::unordered_map<int,int> prevDp;
		prevDp[0] = 1;

		for (auto num : nums){
			dp.clear();
			for (auto it = prevDp.begin(); it != prevDp.end(); ++it){
				dp[it->first+num] += it->second;
				dp[it->first-num] += it->second;
			}
			prevDp = dp;
		}
		return dp[S];
        
    }
};
