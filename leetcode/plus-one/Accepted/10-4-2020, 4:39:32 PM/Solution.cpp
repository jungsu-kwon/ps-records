// https://leetcode.com/problems/plus-one

#include <vector>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		auto it = digits.rbegin();
		int nCarry = 1;


		while  (nCarry != 0 && it != digits.rend()){
			auto num = (*it ) + nCarry;
			if (num == 10){
				nCarry = 1;
				*it = 0;
			}
			else{
                (*it) = (*it) + nCarry;
				nCarry = 0;
                
			}
			++it;
		}
		if (nCarry){
            digits.push_back(nCarry);
            rotate(digits.rbegin(),digits.rbegin()+1,digits.rend());
		}
		return digits;
        
    }
};
