// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (!nums.size()) return nums.size();
        int write_ind = 0, read_ind = 0;
        int cur = nums[0] - 1;

        while (read_ind != nums.size())
        {
            cur = nums[read_ind];
            nums[write_ind] = cur;

            while (cur == nums[read_ind])
                read_ind++;

            write_ind++;
        }
        return write_ind;
        
    }
};