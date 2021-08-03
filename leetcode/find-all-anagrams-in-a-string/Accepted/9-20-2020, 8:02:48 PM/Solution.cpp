// https://leetcode.com/problems/find-all-anagrams-in-a-string

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
private : 
	bool same(std::unordered_map<char,int> &templateCounter,std::unordered_map<char,int> &wordCounter){
		for (auto it = templateCounter.begin(); it != templateCounter.end(); ++it){
			auto key = it->first;
			if (templateCounter[key] != wordCounter[key])
				return false;
		}
		return true;
	}

public:
    vector<int> findAnagrams(string s, string p) {
		//basic sanity checks
		if (s.size() < p.size() || s.size() == 0)
			return std::vector<int>{};
		std::vector<int> vecAns;
		std::unordered_map<char,int> templateCounter;
		for (auto ch : p)
			templateCounter[ch] += 1 ;

		std::unordered_map<char,int> wordCounter;
		for (auto t = 0 ; t < p.size(); ++t){
			wordCounter[s[t]] += 1 ;
		}
		if (same(templateCounter,wordCounter))
			vecAns.push_back(0);

		for (auto t = 1; t < s.size() - p.size() + 1 ; ++t){
			wordCounter[s[t-1]] -= 1 ;
			wordCounter[s[t+p.size()-1]] += 1;
			if (same(templateCounter,wordCounter))
				vecAns.push_back(t);
		}
		return vecAns;


        
    }
};
