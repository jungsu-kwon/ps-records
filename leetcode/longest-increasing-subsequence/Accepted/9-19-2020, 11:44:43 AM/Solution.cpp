// https://leetcode.com/problems/longest-increasing-subsequence

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		std::vector<int> vecLIS(nums.size(),0);
		int ans = 0;
		for (auto num : nums){
			auto low = 0;
			auto high = ans;

			while(low < high){
				auto mid = (low + high) /2 ;
				if (vecLIS[mid] >= num) high = mid ; 
				else low = mid + 1  ;
			}

			vecLIS[low] = num;
			if (low == ans)  ans += 1 ;
		}
        return ans;
    }
};
