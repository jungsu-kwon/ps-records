// https://leetcode.com/problems/largest-rectangle-in-histogram

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private :
	std::vector<int> nextSmallestInd(std::vector<int> &heights){
		std::vector<int> nextSmallestind(heights.size(),-1);
		std::stack<int> indStack;
		for (auto t = 0 ; t < heights.size(); ++t){
			while (indStack.size() && heights[indStack.top()] >= heights[t]){
				indStack.pop();
			}
			if (indStack.size())
				nextSmallestind[t] = indStack.top();
			indStack.push(t);
		}
		return nextSmallestind;
	}
	std::vector<int> nextSmallestIndR(std::vector<int> &heights){
		std::vector<int> nextSmallestind(heights.size(),heights.size());
		std::stack<int> indStack;
		for (int t = heights.size()-1 ; t > -1; --t){
			while (indStack.size() && heights[indStack.top()] >= heights[t]){
				indStack.pop();
			}
			if (indStack.size())
				nextSmallestind[t] = indStack.top();
			indStack.push(t);
		}
		return nextSmallestind;

	}
public:
    int largestRectangleArea(vector<int>& heights) {
		auto vecSmallest = nextSmallestInd(heights);
		auto vecRSmallest = nextSmallestIndR(heights);
		int nMaxArea = 0;


		for (auto t = 0; t < heights.size(); ++t){
			auto l = vecSmallest[t];
			auto r = vecRSmallest[t];
			nMaxArea = std::max(nMaxArea,(r-l-1) * heights[t]);
		}
		return nMaxArea;



        
    }
};
