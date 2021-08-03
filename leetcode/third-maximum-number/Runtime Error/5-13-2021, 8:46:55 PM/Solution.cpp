// https://leetcode.com/problems/third-maximum-number

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
class Solution {

private:
    void sort_array(vector<int> &maxis, int cand)
    {
        if (maxis.size() == 0)
        {
            maxis.push_back(cand);
        }
        else if (maxis.size() <= 3)
        {
            if (find(maxis.begin(),maxis.end(),cand) == maxis.end())
            {
                maxis.push_back(cand);
                sort(maxis.begin(),maxis.end());
            }
        }
        else
        {
            maxis[3] = cand;
            sort(maxis.begin(),maxis.end());
        }
    }
public:
    int thirdMax(vector<int>& nums) {
        vector<int> maxis;
        for (auto num : nums)
        {
            sort_array(maxis,-num);
        }
        if (maxis.size() < 3)
            return -maxis[0];
        return -maxis[2];


        
    }
};