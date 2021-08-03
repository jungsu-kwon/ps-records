// https://leetcode.com/problems/subarray-sum-equals-k

#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0 ;
		std::vector<int> sums;
		auto sum = 0 ;
		for (auto num : nums){
			sum += num;
			sums.push_back(sum);
		}
		auto startInd = 0;
		auto target = k;
		int count = 0;
		for (auto t = 0 ; t < nums.size(); ++t){
			for(auto i = startInd; i < nums.size(); ++i){
				if (sums[i] == target) ++count ;
			}
			target += nums[t];
			++startInd;
			
		}


		return count; 
    }
};
