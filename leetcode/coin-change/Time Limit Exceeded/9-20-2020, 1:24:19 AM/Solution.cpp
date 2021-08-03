// https://leetcode.com/problems/coin-change

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

		if (amount == 0) return 0;
		std::vector<int> bfs;
		std::unordered_set<int> visited;
		bfs.push_back(amount);
		int numCoins = 0;

		while (bfs.size() != 0){
			std::vector<int> nextBfs;
			for (auto cur :  bfs){
				if (cur == 0)
					return numCoins;
				for (auto coin : coins)
				{
					if (cur >= coin && visited.find(cur-coin) == visited.end()){
						nextBfs.push_back(cur - coin);
					}
				}
				visited.insert(cur);
			}
			numCoins += 1 ;
			bfs = nextBfs;


		}
		return -1;
        
    }
};
