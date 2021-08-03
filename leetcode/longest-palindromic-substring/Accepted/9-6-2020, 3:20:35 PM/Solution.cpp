// https://leetcode.com/problems/longest-palindromic-substring


class Solution {
private : 
    std::string helper(const string &s,int l,int r ){
        while(l >=0 && r < s.size() && s[r] == s[l]){
            //std::cout << s[r] << " " << s[l] << " " << s.substr(l,r-l+1) << std::endl;
            ++r;--l;
        }
        return s.substr(l+1,r-l-1);
    }
public:
    string longestPalindrome(string s) {
        std::string maxPalin = "";
        std::string curPalinOdd = "";
        std::string curPalinEven = "";
        std::string curPalin = "";
        for (auto t = 0 ; t < s.size(); ++t){
            curPalinEven = helper(s,t,t+1);
            curPalinOdd = helper(s,t,t);
            //std::cout << "CurPalinEven : "  << curPalinEven << " curPalinOdd " << curPalinOdd << std::endl;
            curPalin = (curPalinEven.size() > curPalinOdd.size()) ? curPalinEven : curPalinOdd;
            maxPalin = (maxPalin.size() > curPalin.size()) ? maxPalin : curPalin;
        }
        return maxPalin;
    }
};
