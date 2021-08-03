// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> vecAns(num+1,0);
        for (auto t = 0 ; t <= num;++t){
            vecAns[t] = __builtin_popcount(t);
        }
        return vecAns;
    }
};