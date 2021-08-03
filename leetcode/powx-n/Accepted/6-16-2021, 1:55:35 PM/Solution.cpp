// https://leetcode.com/problems/powx-n

#define NEGATIVE_LIMIT -2147483648
class Solution {
private:
    double helper(double x, int n)
    {
        if (n == 0) return 1;
        else if (n == 1) return x;
        double half = helper(x, n / 2);

        if (n % 2) return half * half * x;
        return half * half;
    }
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        auto divide_once_more = false;
        if (n == NEGATIVE_LIMIT)
        {
            divide_once_more = true;
            n++;
        }

        auto is_negative = false;
        if (n < 0)
        {
            n *= -1;
            is_negative = true;
        } 

        if (is_negative) ans /= helper(x,n);
        else ans = helper(x,n);
        if (divide_once_more) ans /= x;
        return ans;




        
    }
};