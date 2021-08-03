// https://leetcode.com/problems/height-checker

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted_heights(heights.begin(),heights.end());
        sort(sorted_heights.begin(),sorted_heights.end());


        int ans = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            if (sorted_heights[i] != heights[i])
                ans +=1;
        }
        return ans;
    }
};