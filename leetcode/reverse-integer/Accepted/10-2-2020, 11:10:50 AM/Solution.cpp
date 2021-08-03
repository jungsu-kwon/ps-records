// https://leetcode.com/problems/reverse-integer

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        std::vector<int> nums;
        int maxNum = 2147483647;


        bool isNegative = false;
        if (x < -maxNum) return 0;
        if (x < 0 ) {
            x *= -1;
            isNegative = true;
        }
        
        while (x !=0){
            nums.push_back(x%10);
            x -= nums.back();
            x /=10;
        }

        int retNum = 0;
        for (auto it = nums.begin();it!=nums.end();++it){
            if (!isNegative)
			{
				if (retNum > (maxNum-1)/10)
					return 0;
			}
			else
			{
				if (retNum > (maxNum)/10)
					return 0;
			}
            retNum *= 10;
			retNum += *it;
			
        }
		if (isNegative)
			retNum *= -1;
		return retNum;
        
        
    }
};
