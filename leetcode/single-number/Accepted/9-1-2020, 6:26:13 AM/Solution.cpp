// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int,int> hash;
        for (auto num:nums){
            if (hash.find(num) != hash.end())
                hash[num] += 1 ;
            else
                hash[num] = 1;
        }
        for (auto num:nums){
            if (hash[num] == 1 )
                return num;
        }
        return -1;
        
        
    }
};