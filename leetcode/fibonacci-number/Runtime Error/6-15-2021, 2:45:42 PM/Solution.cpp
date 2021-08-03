// https://leetcode.com/problems/fibonacci-number


class Solution {
private:
    int helper(vector<int> &memo,int n)
    {
        if (memo[n] != -1) return memo[n];
        memo[n] = helper(memo,n-1) + helper(memo,n-2);
        return memo[n];
    }
public:
    int fib(int n) {
        vector<int> memo(n+1,-1);
        memo[0] = 0;
        memo[1] = 1;
        helper(memo,n);
        return memo[n];
        
    }
};