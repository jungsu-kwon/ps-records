// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
private : 
    std::string helper(const string &s,int t){
        int l= t, r = t ; 
        std::string maxCand;
        while (l>=0 && r < s.size() ){
            if (s[r] == s[l]){
                maxCand = s.substr(l,r-l+1);
                if (r < s.size()-1 && l > 0 ){
                    ++r; --l;
                }
                else
                    break;
            }
            else 
                break;
        }

        l=t+1;r=t;
        std::string maxCandRight = "";
        if (l < s.size()){
            while (l >= 0 && r < s.size()){ 
                if (s[l] == s[r]){
                    maxCandRight = s.substr(l,r-l+1);
                    if (l >0 && r < s.size() -1){
                        ++r ; 
                        --l ;
                    }
                    else 
                        break;
                }
                else 
                    break;
            }
        }
        maxCand = (maxCand.size() > maxCandRight.size()) ? maxCand : maxCandRight;
        return maxCand;
    }
public:
    string longestPalindrome(string s) {
        std::string maxPalin = "";
        std::string curPalin = "";
        for (auto t = 0 ; t < s.size(); ++t){
            curPalin = helper(s,t);
            if (maxPalin.size() < curPalin.size())
                maxPalin = curPalin;
        }
        return maxPalin;
    }
};