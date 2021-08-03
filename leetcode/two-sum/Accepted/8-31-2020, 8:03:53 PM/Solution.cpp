// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> hash;
        std::vector<int> vecRes;
        int i = 0;
        for (auto num : nums){
            int curTarget = target - num;
            // if curTarget is present
            auto ind = hash.find(curTarget);
            if ( ind != hash.end()){
                vecRes.push_back(ind->second);
                vecRes.push_back(i);
                return vecRes;
            }
            else{
                hash.insert(std::make_pair(num,i));
            }
            ++i;
        }
        return vecRes;
    }
};