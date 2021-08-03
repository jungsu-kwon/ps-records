// https://leetcode.com/problems/coin-change

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

		if (amount == 0) return 0;
		std::vector<int> dp(amount+1,-1);
        dp[0] = 0;

		for (auto t = 0; t <= amount; ++t){
			for (auto coin : coins){
                if (coin > t) continue;
				if (t == coin) dp[t] = 1;
				else if ( dp[t-coin] != -1)  {
					dp[t] = (dp[t] == -1 || dp[t] > dp[t-coin] + 1) ? dp[t-coin] + 1 : dp[t];
				}
			}
		}
		return dp.back();

        
    }
};


