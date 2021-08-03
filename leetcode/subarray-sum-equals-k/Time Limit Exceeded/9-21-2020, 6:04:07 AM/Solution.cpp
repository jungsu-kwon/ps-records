// https://leetcode.com/problems/subarray-sum-equals-k

#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0 ;
		std::vector<int> dp{nums[0]};
		int count = 0 ;
		if (nums[0] == k) ++count;

		for (auto t = 1; t<nums.size();++t){
			auto num = nums[t];
			for (auto i = 0 ; i < dp.size();++i){
				dp[i] += num;
				if(dp[i] == k) ++count;
			}
			dp.push_back(num);
			if (num == k) ++count;
		}

		return count; 
        
    }
};
