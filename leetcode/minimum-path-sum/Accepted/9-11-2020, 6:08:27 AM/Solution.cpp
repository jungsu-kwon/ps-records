// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		auto m = grid.size();
		if (m == 0) 
			return 0 ;
	   	auto n = grid[0].size();
        if (n == 0)
            return 0;

		std::vector<int> dp(n,0);
		dp[0] = grid[0][0];
		
		for (auto t = 0 ; t < m ; ++t){
			if ( t == 0) 
				for (auto i = 0 ; i < n-1; ++i){
					dp[i+1] = dp[i] + grid[0][i+1];
				}
			else
			{
				dp[0] = dp[0] + grid[t][0];
				for (auto i = 0; i < n-1; ++i){
					dp[i+1] = std::min(dp[i],dp[i+1]) + grid[t][i+1];
				}
			}
		}
		return dp.back();
        
    }
};
