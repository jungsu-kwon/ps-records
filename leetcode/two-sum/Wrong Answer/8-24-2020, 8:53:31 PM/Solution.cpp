// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ans;
        std::map<int,int> hash;
        // construct map
        size_t ind = 0 ;
        for (auto t = nums.begin();t < nums.end();t++)
        { 
            int cur_target = target - *t;
            
            if (hash.find(cur_target) != hash.end())
            {
                ans.push_back(ind);
                ans.push_back(hash[*t]);
                return ans;
            }
            hash.insert({*t,ind});
            ind ++ ;

        }
        return ans;

        
        
        
        
    }
};