// https://leetcode.com/problems/reverse-string

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    void helper(vector<char>& s, int start, int end)
    {
        if (start >= end) return;

        swap(s[start],s[end]);
        helper(s,start+1,end-1);
    }
public:
    void reverseString(vector<char>& s) {
        helper(s,0,s.size()-1);
    }
};