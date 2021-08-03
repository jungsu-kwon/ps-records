// https://leetcode.com/problems/string-to-integer-atoi

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
		std::vector<char> vecChars;
		long long int sum = 0 ;
		long long int maxi = 2147483648 -1;
		long long int mini = -2147483648 ;
		bool isNegative = false;


		char upper = '9';
		char lower = '0';
		bool isFirst = true;


		for (auto ch : str){
			if (ch == '-'){
				isNegative = true;
				isFirst = false;
			}
            else if (ch == '+')
                continue;
			else if (ch <= upper && lower <= ch){
				sum *= 10;
				sum += ch - '0';
				isFirst = false;


			}
			else if (ch == ' '){
				continue;
			}
			else {
				if (isFirst)
					return 0;
                else {
                    break;
                }
			}

		}
		if (isNegative)
		{
			if (sum > maxi+1)
				return int(mini);
			sum *= -1;
		}
		else {
			if (sum > maxi)
				return int(maxi);
		}
		return int(sum);

        
    }
};
