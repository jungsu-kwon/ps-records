// https://leetcode.com/problems/trapping-rain-water

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
		auto n  = height.size();
		if (n == 0) return 0;

		std::vector<int> vecMaxLeft(n,0);
		std::vector<int> vecMaxRight(n,0);

		auto leftMax = -1;
		auto rightMax = -1;
		for (auto t = 0 ; t < n; ++t){
			auto leftVal = height[t];
			auto rightVal = height[n-1-t];

			leftMax = std::max(leftVal,leftMax);
			rightMax = std::max(rightVal,rightMax);

			vecMaxLeft[t] = leftMax;
			vecMaxRight[n-1-t] = rightMax;
		}

		int sum = 0;
		for (auto t = 0 ; t < n; ++t){
			auto leftMax = vecMaxLeft[t];
			auto rightMax = vecMaxRight[t];
			auto nTrapHeight = std::min(leftMax,rightMax);
			if (nTrapHeight == 0)
				continue;


			auto ind = t;
			while (ind < n && height[ind] < nTrapHeight){
				sum += nTrapHeight - height[ind];

				ind += 1;
			}

			t = ind ;
		}
		return sum;


        
    }
};
