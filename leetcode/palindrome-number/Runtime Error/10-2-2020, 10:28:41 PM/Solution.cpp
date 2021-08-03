// https://leetcode.com/problems/palindrome-number

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0 ) return false;
		int numDigits = int(std::log10(x))+1;
		std::vector<int> vecDigits(numDigits,0);
		for (auto t = 0 ; t < numDigits; ++t){
			vecDigits[numDigits-t-1] = x%10;
			x -= vecDigits[numDigits-t-1];
			x /= 10;
			
		}

		for (auto t = 0; t < (1+numDigits)/2; ++t){
			if (vecDigits[t] != vecDigits[numDigits-t-1])
				return false;
		}
		return true;


        
    }
};
