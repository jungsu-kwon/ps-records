// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side

#include <vector>

using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        auto it = arr.rbegin();
        
        int maxi = -1;
        int temp = -1;
        
        while (it != arr.rend())
        {
            temp = *it;
            *it = maxi;
            maxi = max(temp,maxi);
            it++;
        }
        return arr;

        
    }
};