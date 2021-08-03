// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

		if (std::binary_search(nums.begin(),nums.end(),target)){
			// found 
			std::vector<int> vecAns ;
			auto itLower = std::lower_bound(nums.begin(),nums.end(),target);
			auto itUpper = std::upper_bound(nums.begin(),nums.end(),target);
			vecAns.push_back(itLower - nums.begin());
			vecAns.push_back(itUpper - nums.begin() -1 );

			return vecAns;

		}
		else {
			return std::vector<int>{-1,-1};

		}

    }
};