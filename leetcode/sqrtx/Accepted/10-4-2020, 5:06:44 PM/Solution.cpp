// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
		long l = 0 ;
		long r = x/2 ;
		while (l <= r){
			long mid = (l+r) /2;
			long nSquare = mid * mid ;
			if (nSquare == x ){
				return mid;
			}

			else if (nSquare > x){
				r = mid -1;
			}
			else 
			{
				l = mid + 1;
			}

		}
		return r;
        
    }
};
