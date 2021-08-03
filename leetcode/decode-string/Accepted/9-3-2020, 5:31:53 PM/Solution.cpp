// https://leetcode.com/problems/decode-string


class Solution {
private : 
    void Times(std::vector<char> &stack){
        std::string withinParan = "";
        char popped = stack.back();
        stack.pop_back();
        while (popped != '['){
            withinParan += popped;
            popped = stack.back();
            stack.pop_back();
        }
        int nTimes =  0, nDigit = 1;

        while (stack.size() >0 && std::isdigit(stack.back())){
            auto ch = stack.back();
            stack.pop_back();
            nTimes += nDigit*(ch - '0');
            nDigit *= 10;
        }

        for (auto t = 0 ; t < nTimes; ++t){
            for (auto it = withinParan.rbegin();it != withinParan.rend();++it){
                stack.push_back(*it);
            }
        }
    }
public:
    string decodeString(string s) {
        std::vector<char> stack;
        for (auto ch : s){
            // you need to determine if s  == ] or not
            if (ch == ']'){
                Times(stack);
            }
            else
                stack.push_back(ch);
        }
        std::string ans = "";
        for (auto t = 0 ; t < stack.size(); ++t)
            ans += stack[t];
        return ans;
    }
};