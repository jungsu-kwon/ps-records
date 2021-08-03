// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int maxProfit = 0;
        int mini = prices[0];
        for (auto price:prices){
            maxProfit = std::max(maxProfit,price-mini);
            mini = std::min(mini,price);
        }
        return maxProfit;
            
        
        
    }
};