// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		auto n = prices.size();
		if (n == 0 ) return 0 ;

		int reset = 0;
		int hold = -1000000;
		int sell = -1000000;
		for (auto price : prices){
			auto temp =  sell;
			sell = std::max(sell,hold + price);
			hold = std::max(hold,reset - price);
			reset = std::max(reset,temp);
		}
		return std::max(reset,sell);
        
    }
};
