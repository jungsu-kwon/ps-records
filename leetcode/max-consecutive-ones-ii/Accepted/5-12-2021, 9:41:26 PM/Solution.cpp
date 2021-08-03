// https://leetcode.com/problems/max-consecutive-ones-ii

#include <vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int prev = 0;
        int maxi = 0;

        for (auto num : nums)
        {
            if (num == 0)
            {
                maxi = std::max(maxi,prev + count);
                prev = count + 1;
                count = 0;
            }
            else{
                count++;
            }
        }
        maxi = std::max(count+prev,maxi);
        return maxi;


        
        
    }
};