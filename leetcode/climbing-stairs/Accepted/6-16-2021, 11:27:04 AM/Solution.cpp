// https://leetcode.com/problems/climbing-stairs

#include <vector>
using namespace std;
class Solution {
private:
    int helper(vector<int>& memo,int n)
    {
        if (memo[n] != 0) return memo[n];
        memo[n] = helper(memo,n-1) + helper(memo, n-2);
        return memo[n];
    }
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        // initialize memo with first few values
        vector<int> memo(n+1,0);
        memo[1] = 1;
        memo[2] = 2;

        return helper(memo,n);
    }
};