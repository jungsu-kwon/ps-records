// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int read_ind = 0, write_ind = 0;
        
        while (read_ind != nums.size() && write_ind != nums.size())
        {
            while (read_ind != nums.size() && nums[read_ind] == 0)
                read_ind++;
            if (read_ind != nums.size())
            {
                nums[write_ind] = nums[read_ind];
                write_ind++;
                read_ind++;
            }
        }
        
        while (write_ind != nums.size())
        {
            nums[write_ind] = 0;
            write_ind++;
        }
        
    }
};