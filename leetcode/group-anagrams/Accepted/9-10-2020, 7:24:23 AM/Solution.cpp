// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		std::unordered_map<std::string,std::vector<std::string>> hash;
		for (auto str : strs){
			std::string key{str};
			std::sort(key.begin(),key.end());
			hash[key].push_back(str);
		}

		std::vector<std::vector<std::string>> vecAns;
		for (auto it = hash.begin(); it != hash.end(); ++it){
			vecAns.push_back(it->second);
		}

		return vecAns;
    }
};