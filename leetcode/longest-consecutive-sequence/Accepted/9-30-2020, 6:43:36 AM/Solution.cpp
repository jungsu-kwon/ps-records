// https://leetcode.com/problems/longest-consecutive-sequence

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		std::unordered_set<int> setNums;
		for (auto num : nums){
			setNums.insert(num);
		}
		int nLongestLen = 0;

		for (auto num : nums){
			if (setNums.find(num) != setNums.end())
			{
				int curLen = 1;

				int nLower = num - 1 ; 
				while (setNums.find(nLower) != setNums.end()){
					setNums.erase(nLower);
					curLen += 1 ;
					nLower -= 1;
				}

				int nHigher = num + 1 ;
				while (setNums.find(nHigher) != setNums.end()){
					setNums.erase(nHigher);
					curLen += 1 ;
					nHigher += 1 ;
				}
				nLongestLen = std::max(nLongestLen,curLen);
			}
		}
		return nLongestLen;
        
    }
};
