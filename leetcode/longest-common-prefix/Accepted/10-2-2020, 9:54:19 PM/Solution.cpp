// https://leetcode.com/problems/longest-common-prefix

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		std::string strAns = "";
		if (!strs.size()) return strAns;

		for (auto t = 0 ; t < strs[0].size(); ++t){
			char cand = strs[0][t];
			for (auto str: strs){
				if (t > str.size()-1||str[t] != cand){
					return strAns;
				}
			}
			strAns += cand;
		}
		return strAns;

        
    }
};
