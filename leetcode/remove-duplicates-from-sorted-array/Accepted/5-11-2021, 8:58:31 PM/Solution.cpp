// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return nums.size();
        
        auto prev = nums[0] - 1;
        auto cur = 0;

        while (cur != nums.size())
        {
            if (nums[cur] == prev)
            {
                nums.erase(nums.begin() + cur);
            }
            else
            {
                prev = nums[cur];
                cur += 1;
            }
        }
        return nums.size();
        
    }
};