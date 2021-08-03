// https://leetcode.com/problems/partition-equal-subset-sum

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;
class Solution {
private : 
	bool dfs(std::vector<int> &nums,int target){
		if (target ==  0)
			return true;
		for (auto t = 0; t < nums.size(); ++t){
			auto num = nums[t];
			if (num == -1)
				continue;
			else if (num <= target){
				nums[t] = -1;
				if (dfs(nums,target-num))
					return true;
				nums[t] = num;
			}
		}
		return false;
	}
public:
    bool canPartition(vector<int>& nums) {
		auto sum = std::accumulate(nums.begin(),nums.end(),0);
        auto target = sum / 2 ; 

		if (sum % 2 == 1)
			return false;
        for (auto num : nums){
            if (num > target)
                return false;
        }
		return dfs(nums,target);
    }
};
