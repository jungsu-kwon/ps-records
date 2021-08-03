// https://leetcode.com/problems/duplicate-zeros

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        auto begin = arr.begin();
        auto origin_len = arr.size();
        while (i <= origin_len)
        {
            if (arr[i] == 0){
                arr.insert(arr.begin() + i + 1,0);
                i += 1;
            }
            i += 1;
        }
        arr.resize(origin_len);

        
    }
};