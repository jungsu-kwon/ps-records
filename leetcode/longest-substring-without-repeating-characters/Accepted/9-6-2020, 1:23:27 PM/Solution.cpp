// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::map<int,int> lastOccurence;
        for (auto ch : s){
            lastOccurence[ch] = -1;
        }
        auto maxLen = 0;
        auto curLen = 0;
        auto startInd = 0;
        auto curInd = 0;

        for (auto ch : s){
            if (lastOccurence[ch] >= startInd){
                startInd = lastOccurence[ch] + 1;
            }
            else {
                curLen = curInd - startInd + 1 ;
                maxLen = std::max(maxLen, curLen);
            }
            lastOccurence[ch] = curInd;
            curInd += 1 ;
        }
        return maxLen;


    }
};
