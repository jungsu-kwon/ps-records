// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // find first decreasing element
        int nFirstDecrease = -1 ;
        for (auto t = 0;t < nums.size()-1;++t){
            if (nums[t] > nums[t+1]){
                nFirstDecrease = t;
                break;
            }
        }
        if (nFirstDecrease == -1) return 0;
        int nLastDecrease = -1;
        for (auto t = nums.size()-1; t>0; --t){
            if (nums[t] < nums[t-1]){
                nLastDecrease = t;
                break;
            }
        }
        auto minimax = std::minmax_element(nums.begin()+nFirstDecrease,
                                           nums.begin()+nLastDecrease);
        int mini = *minimax.first; 
        int maxi = *minimax.second;
        int nStart = 0, nEnd = nums.size()-1;
        for (auto num : nums){
            if(num > mini)
                break;
            nStart ++;
        }
        for (auto t = nums.size()-1;t>0;--t ){
            if(nums[t] < maxi){
                nEnd = t;
                break;
            }
        }
        return nEnd-nStart+1;
        
    }
};