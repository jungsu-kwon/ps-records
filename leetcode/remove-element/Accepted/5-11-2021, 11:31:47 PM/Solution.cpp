// https://leetcode.com/problems/remove-element

#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write_ind = 0, read_ind = 0;
        while (read_ind != nums.size())
        {
            if (nums[read_ind] != val)
            {
                nums[write_ind] = nums[read_ind];
                write_ind++;
                read_ind++;
            }
            else
            {
                read_ind++;
            }
        }
        return write_ind;
        
    }
};