// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto nonZeroCount = 0 ;
        for (auto num:nums){
            if (num != 0){
                nums[nonZeroCount] = num;
                nonZeroCount += 1;
            }
        }
        for (auto t = nonZeroCount; t < nums.size();++t)
            nums[t] = 0;
    }
};