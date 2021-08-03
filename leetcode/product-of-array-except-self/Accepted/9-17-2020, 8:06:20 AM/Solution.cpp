// https://leetcode.com/problems/product-of-array-except-self

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		if (nums.size() == 0) return std::vector<int>{};
		auto n = nums.size();
		std::vector<int> vecAns(n,0);

		int prod = 1;
		for(auto t = 0; t < n; ++t){
			vecAns[t] = prod;
			prod *= nums[t];
		}

		prod = 1;
		for(auto t = n-1; t != -1; --t){
			vecAns[t] *= prod;
			prod *= nums[t];
		}
		return vecAns;
				
	}
};
