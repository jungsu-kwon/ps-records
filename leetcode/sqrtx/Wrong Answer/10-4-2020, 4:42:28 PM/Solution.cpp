// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
		for (auto t = 1 ; t < x; ++t){
			auto nSquare = t*t;
			if (nSquare == x){
				return t;
			}
			else if (nSquare > x){
				return t-1;
			}
		}
		return 0;
        
    }
};
