// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		std::vector<std::string> vecAns;
		if (n == 0){
            vecAns.push_back("");
			return vecAns;
		}
		std::list<std::pair<int,std::string>> listSearch;
		listSearch.push_back(std::make_pair(1,"("));

		for (auto t = 1 ; t < 2*n; ++t){
			auto sizeList = listSearch.size();
			for (auto i = 0 ; i < sizeList; ++i){
				auto pair = listSearch.begin();
				auto count = pair->first;
				auto curString = pair->second;
				listSearch.pop_front();

				if (count > 0){
					listSearch.push_back(std::make_pair(count-1,curString+")"));
					listSearch.push_back(std::make_pair(count+1,curString+"("));
				}
				else{
					listSearch.push_back(std::make_pair(count+1,curString+"("));
				}
			}
		}
		for (auto t : listSearch){
			if (t.first ==0)
				vecAns.push_back(t.second);
		}

		return vecAns;
    }
};
