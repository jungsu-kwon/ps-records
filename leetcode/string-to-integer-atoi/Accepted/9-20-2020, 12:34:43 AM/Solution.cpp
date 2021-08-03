// https://leetcode.com/problems/string-to-integer-atoi

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
		std::vector<char> vecChars;
		long int sum = 0 ;
		long int maxi = 2147483648 -1;
		long int mini = -2147483648 ;
		bool isNegative = false;


		char upper = '9';
		char lower = '0';
		bool isFirst = true;


		for (auto ch : str){
			if (isFirst && ch == '-'){
                isNegative = true;
                isFirst = false;
            }
                
            else if (isFirst && ch == '+'){
				isNegative = false;
				isFirst = false;
			}
			else if (isFirst && ch == ' '){
				continue;
			}
			else if (ch <= upper && lower <= ch){
				sum *= 10;
				sum += ch - '0';
				isFirst = false;

                if (isNegative)
                {
                    if (sum > maxi+1)
                        return int(mini);
                }
                else {
                    if (sum > maxi)
                        return int(maxi);
                }

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
