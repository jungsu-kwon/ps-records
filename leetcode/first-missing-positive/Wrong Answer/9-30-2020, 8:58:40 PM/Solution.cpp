// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
        if (n == 0) return 1;
		for (auto t = 0 ; t < nums.size(); ++t){
			auto num = nums[t];
			while (num < n && num>0 &&nums[num-1] != num){
				auto temp = nums[num-1];
				nums[num-1] = num;
				num = temp;
			}	
		}
		for (int t = 0; t < nums.size(); ++t){
			if (t+1 != nums[t])
				return t+1;
		}
		return n+1;
        
    }
};
