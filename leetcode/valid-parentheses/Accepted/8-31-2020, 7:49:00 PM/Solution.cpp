// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isOpen(char ch){
        if (ch == '(' || ch == '[' || ch == '{')
            return true;
        return false;
    }
    bool isMatch(char ch1,char ch2){
        if (ch1 == '(' && ch2 == ')')
            return true;
        else if (ch1 == '[' && ch2 == ']')
            return true;
        else if (ch1 == '{' && ch2 == '}')
            return true;
        return false;
    }
        
    bool isValid(string s) {
        std::vector<char> vecStack;
        for (auto ch:s){
            if (isOpen(ch))
                vecStack.push_back(ch);
            else{
                if (!vecStack.size())
                    return false;
                char popped =  vecStack.back();
                vecStack.pop_back();
                if (!isMatch(popped,ch))
                    return false;
            }
        }
        if (vecStack.size()) 
            return false;
        return true;
    }
};