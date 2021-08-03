// https://leetcode.com/problems/k-th-symbol-in-grammar

#include <cmath>
using namespace std;

class Solution {
private:
    int power(int x, int p)
    {
        if (p == 0) return 1;
        if (p == 1) return x;
        
        int tmp = power(x, p/2);
        if (p%2 == 0) return tmp * tmp;
        else return x * tmp * tmp;
    }
    int helper(int n, int k)
    {
        if (n == 1) return 0;
        auto border  = power(2,n-2);
        if ( k >= border) return 1 - helper(n-1,k % border);
        else return helper(n-1,k);

    }
public:
    int kthGrammar(int n, int k) {
        return helper(n,k-1);
        
    }
};