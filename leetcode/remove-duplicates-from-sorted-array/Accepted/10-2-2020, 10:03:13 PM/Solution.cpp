// https://leetcode.com/problems/remove-duplicates-from-sorted-array

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (!nums.size()) return 0;
		auto writeInd = 0;
		auto prevNum = nums[0]-1;
		for (auto t = 0 ; t < nums.size(); ++t){
			if (nums[t] != prevNum){
				nums[writeInd] = nums[t];
				writeInd += 1;
				prevNum = nums[t];
			}

		}
		return writeInd;
        
    }
};
