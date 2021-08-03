// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    void countElem(vector<int>& nums){
        for (auto num:nums){
            auto temp = 0;
            while (num > 0){
                temp = nums[num-1];
                nums[num-1] = 0 ; 
                num = temp;
            }
        }
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       countElem(nums); 
       std::vector<int> ans;
       
       for (auto t =0; t < nums.size();++t){
           if (nums[t])
               ans.push_back(t+1);
       }
        
       return ans;
    }
};