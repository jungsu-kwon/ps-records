// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
		for (int t = 0 ; t <= x; ++t){
            if (t >= 46341)
            {
                long nSquare = long(t)*long(t);
			    if (nSquare == x){
			    	return t;
		    	}
		    	else if (nSquare > x){
			    	return t-1;
		    	}
            }
            else {
                int nSquare = t*t;
                if (nSquare == x){
			    	return t;
		    	}
		    	else if (nSquare > x){
			    	return t-1;
		    	}
            }

		}
		return -1;
        
    }
};
