// https://leetcode.com/problems/longest-common-prefix

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		std::string strAns = "";
		if (!strs.size()) return strAns;
		auto minLen =  strs[0].size();
		for (auto str : strs){
			minLen = std::min(minLen,str.size());
		}

		for (auto t = 0 ; t < minLen; ++t){
			char cand = strs[0][t];
			for (auto str: strs){
				if (str[t] != cand){
					return strAns;
				}
			}
			strAns += cand;
		}
		return strAns;

        
    }
};
