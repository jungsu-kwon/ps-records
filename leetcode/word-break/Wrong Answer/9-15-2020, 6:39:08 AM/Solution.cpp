// https://leetcode.com/problems/word-break

class Solution {
private : 
	bool startsWith(std::string s,int startInd, std::string prefixCand)
	{
		if (s.size() < prefixCand.size()+startInd) return false;
		for (auto t = 0; t < prefixCand.size(); ++t)
		{
			if(prefixCand[t] != s[t+startInd]) 
			{
				return false;
			}
		}
		return true;
	}
	bool wordBreak(string s, int startInd, vector<string>& wordDict,std::vector<int> &visited)
	{
		if (startInd == s.size()) return true;
		for (auto word : wordDict)
		{
			if (startInd + word.size() < s.size() && 
				visited[startInd+word.size()]==0  &&
				startsWith(s,startInd,word))
			{
				if (wordBreak(s,startInd + word.size(), wordDict,visited))
					return true;
			}
		}
		visited[startInd] = 1;
		return false;
	}
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		std::vector<int> visited(s.size(),0);
		return  wordBreak(s,0,wordDict,visited);
	}
};