// https://leetcode.com/problems/jump-game-ii

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
		if (nums.size() == 0 ) return 0;
		int numJumps = 0;
		int start = 0 ;
		int end = 1;

		while (start < nums.size() && end  <= nums.size()-1)
		{
			int canReach = 0;
			for (int t = start; t < end; ++t){
				canReach = std::max(canReach,t+nums[t]);
			}
			numJumps += 1;
			if (canReach >= nums.size()-1) return numJumps;
			start = end ;
			end = canReach+1;
		}
		return -1;
        
    }
};
