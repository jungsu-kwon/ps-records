// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<string> vecRows(numRows,"");
        auto chInd = 0 ;
        for (auto ch : s){
            auto remainder = chInd % (2*numRows -2);
            auto rowInd = (remainder > numRows-1 ) ? 2*numRows - remainder-2: remainder;
            vecRows[rowInd] += ch;
            chInd += 1 ;
        }
        std::string ansString ="" ; 
        for (auto str : vecRows){
            ansString += str;
        }
        return ansString;
    }
};