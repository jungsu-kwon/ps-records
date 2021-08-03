// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        std::string prevString = countAndSay(n-1);
        std::vector<char> vecAns;
        char prevChar = prevString[0];
        int count = 0;
        for (auto ch : prevString){
            if (ch == prevChar){
                count += 1; 
            }

            else{
                vecAns.push_back('0'+count);
                vecAns.push_back(prevChar);
                prevChar = ch;
                count = 1;
            }
            
        }
        vecAns.push_back('0'+count);
        vecAns.push_back(prevChar);
        return std::string(vecAns.begin(),vecAns.end());
        
    }
};
//"111221"
