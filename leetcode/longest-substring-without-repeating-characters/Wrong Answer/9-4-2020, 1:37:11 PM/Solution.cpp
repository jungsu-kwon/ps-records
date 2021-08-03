// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::map<int,int> occurence;
        for (auto ch : s){
            occurence[ch] = -1;
        }
        int nMaxLen = 0, nStart=-1, nCurLen = 0, ind = 0;


        for (auto ch : s){
            if (occurence[ch] > nStart){
                nStart = ind;
            }
            else
            {
                nCurLen = ind - std::max(nStart,0) + 1 ;
                nMaxLen = std::max(nMaxLen,nCurLen);
            }
            ind += 1;
            occurence[ch] = ind;
        }
        return nMaxLen;
    }
};