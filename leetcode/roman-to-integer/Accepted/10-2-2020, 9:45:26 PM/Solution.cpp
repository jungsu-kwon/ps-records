// https://leetcode.com/problems/roman-to-integer

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		std::unordered_map<char,int> mapVals;
		std::string romanNums = "IVXLCDM";
		std::vector<int> vecVals{1,5,10,50,100,500,1000};

		auto ind = 0;
		for (auto ch : romanNums){
			mapVals[ch] = vecVals[ind];
			ind += 1 ;
		}

		int numericVal = 0 ;
		ind = 0 ;
		for (auto ch : s){
			auto curVal = mapVals[ch];
			if (ind < s.size() -1 &&  curVal < mapVals[s[ind+1]]){
				numericVal -= curVal;
			}
			else{
				numericVal += curVal;
			}
			ind += 1 ;
		}
		return numericVal;
        
    }
};
