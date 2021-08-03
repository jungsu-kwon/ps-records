// https://leetcode.com/problems/daily-temperatures

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        std::vector<int> vecAns(T.size(),0);
        std::vector<int> stack;
        int prevTemp = T.back();
		for (auto t = T.size()-2; t != -1; --t){
			prevTemp = T[t+1];
			if (prevTemp >= T[t]){
				stack.push_back(t+1);
            }
			if (stack.size() == 0){
				continue;
			}
			while (stack.size() != 0 && T[stack.back()] <= T[t]){
				stack.pop_back();
			}
			if (stack.size() != 0){
				vecAns[t] = stack.back()-t;
			}
		}
		return vecAns;
    }
};
