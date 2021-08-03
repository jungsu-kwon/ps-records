// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> vecLastLoc(256,-1);
        int nMaxLen = 0 ; 
        int start = 0 ;
        for (auto i = 0; i < s.size(); i++){
           if(vecLastLoc[s[i]] >= start) {
               start = vecLastLoc[s[i]]+1;
           }
           nMaxLen = std::max(nMaxLen,i - start + 1);
            vecLastLoc[s[i]] = i;
            
        }
       return nMaxLen; 
    }
};