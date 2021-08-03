// https://leetcode.com/problems/max-consecutive-ones

#include <iostream>
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int max_ones = 0;
      int count = 0;
      for (auto num : nums)
      {
        if (num == 1)
          count += 1;
        else
          count = 0;
        
        max_ones = std::max(count,max_ones);
      }
      return max_ones;
  }
};