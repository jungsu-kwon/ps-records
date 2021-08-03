// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
		for (long t = 0 ; t <= x; ++t){
			long nSquare = t*t;
			if (nSquare == x){
				return t;
			}
			else if (nSquare > x){
				return t-1;
			}
		}
		return -1;
        
    }
};
