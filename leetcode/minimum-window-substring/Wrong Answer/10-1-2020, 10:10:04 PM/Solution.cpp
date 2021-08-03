// https://leetcode.com/problems/minimum-window-substring

#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
private :
	int outOfTemplate = -1000;
	int inTemplate = -1;
public:
    string minWindow(string s, string t) {
		std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap;
		std::vector<int> vecLastOccurence('z' -'A' + 1 ,outOfTemplate);
		for (auto ch : t){
			vecLastOccurence[ch-'A'] = inTemplate;
		}
		int numChars = 0;
		int ind = 0;
		int nMinLen = s.size()+1;
		std::string  strAns = "";

		for (auto ch : s){
            
			if (vecLastOccurence[ch-'A'] >= inTemplate)
			{
				numChars += (vecLastOccurence[ch-'A'] == inTemplate);
                vecLastOccurence[ch-'A'] = ind;
                minHeap.push(ind);
				auto chHeapTop = s[minHeap.top()];
				while (minHeap.size() && vecLastOccurence[chHeapTop-'A'] != minHeap.top()){
					minHeap.pop();
					chHeapTop = s[minHeap.top()];
				}

				
				if (numChars == t.size()){
					strAns = (ind - minHeap.top() + 1 < nMinLen) ? s.substr(minHeap.top(),ind - minHeap.top()+1) : strAns;
					nMinLen = std::min(ind - minHeap.top() + 1 , nMinLen);
				}
			}
            ind += 1 ;
		}
		return strAns;


        
    }
};

