// https://leetcode.com/problems/jump-game


class Solution {
public:
    bool canJump(vector<int>& nums) {
		std::vector<bool> dp(nums.size(),0);
		dp[0] = true;
		for (auto t = 0 ; t < dp.size(); ++t){
			if (dp[t] == false) continue;
			for (auto i = t; i <= t+nums[t] && i < nums.size(); ++i) dp[i] = true;
		}
		return dp[nums.size()-1];
    }
};
