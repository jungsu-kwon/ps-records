// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int,int> hash;
        auto n = nums.size();
        for(auto num:nums){
            hash[num] += 1 ;
        }
        for (auto it = hash.begin();it != hash.end(); ++it){
            if(it->second > n/2)
                return it->first;
        }
        return -1;
        
        
        

            
        
    }
};