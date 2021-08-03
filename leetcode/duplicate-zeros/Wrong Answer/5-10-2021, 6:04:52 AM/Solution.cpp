// https://leetcode.com/problems/duplicate-zeros

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        auto begin = arr.begin();
        while (i != arr.size())
        {
            if (arr[i] == 0){
                arr.insert(arr.begin() + i + 1,0);
                i += 1;
            }
            i += 1;
        }
        
    }
};