// https://leetcode.com/problems/powx-n

class Solution {
private : 
	double helper(double x, int n){
		if (n == 1 ){
			return x;
		}
		else if (n == 0){
			return 1;
		}
        auto toSquare = helper(x,(n-(n%2))/2);
        auto remainder = helper(x,(n%2));
        //std::cout << "x/n " << x << " " << n << " " << n%2 << endl;
        //std::cout << "toSquare/remainder" << toSquare <<  " " << remainder <<endl;
        auto ret = toSquare * toSquare * remainder;
		return ret ;

	}
public:
    double myPow(double x, int n) {
		auto isNeg = false;
        auto isNegLimit = false;
        if (n == -2147483648){
            isNeg = true;
            isNegLimit = true;
            n += 1;
            n *= -1;
        }
		else if (n <0){
			n *= -1;
			isNeg = true;
		}
			
		auto ret = helper(x,n);
		if (isNeg){
			ret = 1/ ret;
		}
        if (isNegLimit){
            ret /= x; 
        }
		return ret;
    }
};
