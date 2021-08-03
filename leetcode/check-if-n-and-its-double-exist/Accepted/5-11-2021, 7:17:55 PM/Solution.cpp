// https://leetcode.com/problems/check-if-n-and-its-double-exist

#include <map>

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // construct counter
        std::map<int,int> counter;
        for (auto num : arr) counter[num]++;

        for (const auto &it : counter)
        {
            if (it.first == 0)
            {
                if (it.second >=2) return true;
            }
            else{
                if (counter.find(it.first * 2) != counter.end())
                    return true;
            }
        }
        return false;

    }
};