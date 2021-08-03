// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int write_ind = 0;
        int fin_ind = 0;

        while (fin_ind != nums.size())
        {
            auto exist_num = nums[fin_ind];
            write_ind = exist_num -1;
            while (write_ind >=0)
            {
                exist_num = nums[write_ind];
                nums[write_ind] = -1;
                write_ind = exist_num -1;
            }
            fin_ind++;
        }

        vector<int> ans;
        for (int i = 0; i < nums.size();++i)
        {
            if (nums[i] != -1)
                ans.push_back(i+1);
        }
        return ans;
        
    }
};