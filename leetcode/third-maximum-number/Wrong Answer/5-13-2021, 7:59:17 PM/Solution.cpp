// https://leetcode.com/problems/third-maximum-number

#include <algorithm>
#include <vector>
using namespace std;
class Solution {

private:
    void sort_array(vector<int> &maxis, int cand)
    {
        if (find(maxis.begin(),maxis.end(),cand) == maxis.end())
        {
            if (maxis.size() <= 3)
                maxis.push_back(-cand);
            else
                maxis[3] = -cand;
            sort(maxis.begin(),maxis.end());
        }

    }
public:
    int thirdMax(vector<int>& nums) {
        vector<int> maxis;
        for (auto num : nums)
            sort_array(maxis,num);
        if (maxis.size() < 3)
            return -maxis[0];
        return -maxis[2];


        
    }
};