// https://leetcode.com/problems/word-break

class Solution {
private : 
	bool startsWith(std::string s,int startInd, std::string prefixCand){
		if (s.size() < prefixCand.size()+startInd) return false;
		for (auto t = 0; t < prefixCand.size(); ++t){
			if(prefixCand[t] != s[t+startInd]) 
				return false;
		}
		return true;
	}
	bool wordBreak(string s, int startInd, vector<string>& wordDict)
	{
		if (startInd == s.size()) return true;
		for (auto word : wordDict)
		{
			if (startsWith(s,startInd,word))
			{
				if (wordBreak(s,startInd + word.size(), wordDict))
					return true;
			}
		}
		return false;
	}
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		return  wordBreak(s,0,wordDict);
	}
};
