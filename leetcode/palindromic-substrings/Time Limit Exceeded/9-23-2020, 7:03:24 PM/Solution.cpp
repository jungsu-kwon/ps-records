// https://leetcode.com/problems/palindromic-substrings

#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
		int numPalind = 0 ;

		for (auto l = 0 ; l < s.size(); ++l){
            auto temp = l;
			auto r = l;
			while (l>=0 && r < s.size() && s[l] == s[r])
			{
				++r;
				--l;
				++numPalind;
			}
            l = temp;
			r  = l + 1;
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
