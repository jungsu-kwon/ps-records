// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
		auto l=0;
		auto r=nums.size()-1;
		auto t = 0 ;
		if (r == 0) return ;

		while (l < r && t <= r  ){
			auto curColor = nums[t];
			if (curColor == 0) {
				std::swap(nums[t],nums[l]);
				++l;
				++t;
			}
			else if (curColor == 1 ){
				++t;
			}
			else if (curColor == 2){
				std::swap(nums[t],nums[r]);
				--r;
			}
		}
		return;

    }
};