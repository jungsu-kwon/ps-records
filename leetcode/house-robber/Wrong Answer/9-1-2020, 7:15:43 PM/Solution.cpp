// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        
        int maxi = 0; 
        std::vector<int> dp(nums.size()+1,0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (auto t = 2 ; t < nums.size();++t){
            dp[t] = std::max(dp[t-1],dp[t-2] + nums[t]); 
        }
        return dp[nums.size()-1];
    }
};