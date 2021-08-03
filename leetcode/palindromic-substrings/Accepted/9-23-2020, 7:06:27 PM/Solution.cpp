// https://leetcode.com/problems/palindromic-substrings

#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
		int numPalind = 0 ;

		for (auto i = 0 ; i < s.size(); ++i){
            auto l = i;
			auto r = i;
			while (l>=0 && r < s.size() && s[l] == s[r])
			{
				++r;
				--l;
				++numPalind;
			}
            l = i;
			r  = i + 1;
            
			while (l>=0 && r < s.size() && s[l] == s[r])
			{
				++r;
				--l;
				++numPalind;
			}
            
		}


		return numPalind;

    }
};
