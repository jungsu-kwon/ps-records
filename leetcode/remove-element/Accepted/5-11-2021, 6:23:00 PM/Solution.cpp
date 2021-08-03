// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto cur = 0;
        while (cur != nums.size())
        {
            if (nums[cur] == val) 
            {
                nums.erase(nums.begin() + cur);
            }
            else
            {
                cur += 1;

            }
        }
        return nums.size();
        
    }
};