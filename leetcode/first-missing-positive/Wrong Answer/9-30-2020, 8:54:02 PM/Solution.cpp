// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (auto t = 0 ; t < nums.size(); ++t){
			auto num = nums[t];
			while (num < n && num>=0 &&nums[num] != num){
				auto temp = nums[num];
				nums[num] = num;
				num = temp;
			}	
		}
		for (int t = 1; t < nums.size(); ++t){
			if (t != nums[t])
				return t;
		}
		return -1 ;
        
    }
};
