// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
private:
    void helper(vector<int> &ans,int cur_level, int dst_level)
    {
        if (cur_level > dst_level) return;
        int prev = 0;
        for (int i = 0; i < cur_level; ++i)
        {
            auto temp = ans[i];
            ans[i] += prev;
            prev = temp;
        }
        helper(ans,cur_level + 1, dst_level);

    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,1);
        helper(ans,0,rowIndex);
        return ans;
        
    }
};