// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

#include <iostream>

class Solution {
private:
    bool is_even_digit(int num)
    {
        int count = 0;
        while (num != 0)
        {
            num /= 10;
            count += 1;
        }
        return (count % 2) == 0;
    }
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto num : nums)
        {
            if (is_even_digit(num))
            {
                count += 1;
            }
        }
        return count;
        
    }
};