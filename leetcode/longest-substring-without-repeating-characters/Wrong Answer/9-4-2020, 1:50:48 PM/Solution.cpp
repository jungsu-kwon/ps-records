// https://leetcode.com/problems/longest-substring-without-repeating-characters

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::map<int,int> occurence;
        for (auto ch : s){
            occurence[ch] = -1;
        }
        int nMaxLen = 0, nStart=-1, nCurLen = 0, ind = 0;


        for (auto ch : s){
            if (occurence[ch] >= nStart){
                nStart = occurence[ch]+1;
            }
            else
            {
                nCurLen = ind - std::max(nStart,0) + 1 ;
                nMaxLen = std::max(nMaxLen,nCurLen);
            }
            occurence[ch] = ind;
            ind += 1;
        }
        return nMaxLen;
    }
};