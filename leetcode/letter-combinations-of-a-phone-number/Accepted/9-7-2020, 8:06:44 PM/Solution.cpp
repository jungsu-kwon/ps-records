// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> dict{
            "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
		auto lenAns  = 1;
		for (auto digit : digits){
			lenAns *= dict[(digit-'1')].size();
		}
        if (digits.size() == 0){
            std::vector<std::string> vecAns;
            return vecAns;
        }
		std::vector<std::string> vecAns(lenAns,"");
		auto period = 1 ;

		for (auto digit : digits){
			auto ind = 0;
			for (auto t = 0 ; t < lenAns;++t){
				vecAns[t] += dict[digit-'1'][ind];
				if ( (t+1) % period == 0){
					ind += 1 ;
					ind = ind % dict[digit-'1'].size();
				}
			}
			period *= dict[digit-'1'].size();
		}

        return vecAns;
    }
};