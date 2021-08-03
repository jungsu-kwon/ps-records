// https://leetcode.com/problems/maximum-product-subarray


class Solution {
public:
	int maxProduct(vector<int>& nums) {
		auto n = nums.size();
		if (n == 0)
			return 0;
		// empty vector dp with size 2,n
		// dp 0 i stores minimum elem
		// dp 1 i stores maximum elem
		std::vector<std::vector<int>> dp;
		dp.push_back(std::vector<int>(n,0));
		dp.push_back(std::vector<int>(n,0));
		dp[0][0]= nums[0];
		dp[1][0] = nums[0];
		auto ret = nums[0];

		for (auto t = 1; t < n ; ++t){
			dp[0][t] = std::min(nums[t],std::min(dp[0][t-1]*nums[t], dp[1][t-1]*nums[t]));
			dp[1][t] = std::max(nums[t],std::max(dp[0][t-1]*nums[t], dp[1][t-1]*nums[t]));
			ret = std::max(dp[1][t],ret);
		}

		return ret;

				
	}
};
