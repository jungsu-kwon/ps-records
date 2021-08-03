// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if(nums.size() ==1 )
            return nums[0];

        // dp1 select current value
        std::vector<int> dp1(nums.size()+1,0);
        // dp2 not select current value
        std::vector<int> dp2(nums.size()+1,0);
        dp1[0] = nums[0]; dp1[1] = nums[1];
        dp2[0] = 0; dp2[1] = nums[0];
        
        for (auto t = 2; t < nums.size(); ++t){
            dp1[t] = std::max(dp1[t-2],dp2[t-1])+nums[t];
            dp2[t] = std::max(dp1[t-1],dp2[t-1]);
        }
        return std::max(dp1[nums.size()-1],dp2[nums.size()-1]);
        
        
    }
};