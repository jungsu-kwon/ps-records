// https://leetcode.com/problems/sort-an-array

#include <vector>
using namespace std;

class Solution {
private:
    void merge(vector<int> &merged, const vector<int> &left, const vector<int> &right)
    {
        int left_ind = 0;
        int right_ind = 0;
        int merge_ind = 0;

        while (left_ind != left.size() && right_ind != right.size())
        {
            if (left[left_ind] < right[right_ind])
            {
                merged[merge_ind] = left[left_ind];
                left_ind++;
            }
            else
            {
                merged[merge_ind] = right[right_ind];
                right_ind++;
            }
            merge_ind++;
        }
        if (left_ind  == left.size())
            std::copy(right.begin()+right_ind,right.end(),merged.begin()+merge_ind);
        else
            std::copy(left.begin()+left_ind,left.end(),merged.begin()+merge_ind);
    
    }
    vector<int> helper(vector<int> &nums, int start, int end)
    {
        // end exclusive [start, end)
        if (start >= end) return vector<int>{};
        else if (end - start == 1) return vector<int> {nums[start]};
        int middle = (start + end) / 2;
        // cout << start << " "<< middle  << " " << end << endl;

        auto left = helper(nums,start,middle);
        auto right = helper(nums,middle,end);

        auto merged = vector<int>(end - start,0);
        merge(merged,left,right);
        return merged;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        return helper(nums,0,nums.size());

        
    }
};