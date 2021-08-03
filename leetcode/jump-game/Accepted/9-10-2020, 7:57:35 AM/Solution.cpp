// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
		auto nReach = 0; 
		for (auto t = 0 ; t < nums.size();++t){
			if (nReach < t) return false;
			nReach = std::max(nReach,t + nums[t]);
		}
		return nReach >= nums.size()-1;
    }
};
