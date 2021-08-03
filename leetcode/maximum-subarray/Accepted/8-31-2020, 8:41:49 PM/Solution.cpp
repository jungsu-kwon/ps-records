// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        auto sum = 0 ;
        auto maxi = nums[0];
        
        for(auto num:nums){
            sum = std::max(sum,0) + num;
            maxi = std::max(sum,maxi);
        }
        return maxi;
    }
};