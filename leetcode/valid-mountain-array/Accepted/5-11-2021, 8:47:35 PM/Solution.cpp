// https://leetcode.com/problems/valid-mountain-array

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        else if (arr[0] >= arr[1]) return false;
        bool is_increasing = true;
        int prev = -1;

        for (auto num : arr)
        {
            if (is_increasing)
            {
                if (prev == num)
                {
                    return false;
                }
                else if (prev > num)
                {
                    is_increasing = false;
                }
            }
            else
            {
                if (prev <= num)
                {
                    return false;
                }

            }
            prev = num;

        }
        if (is_increasing) return false;
        return true;
        
    }
};