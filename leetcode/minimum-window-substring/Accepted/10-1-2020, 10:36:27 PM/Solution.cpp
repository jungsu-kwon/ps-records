// https://leetcode.com/problems/minimum-window-substring

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
private :
	int outOfTemplate = -1000;
	int inTemplate = -1;
	bool equal(std::unordered_map<int,int> &t, std::unordered_map<int,int> &m){
		for (auto k : t){
			if (m[k.first] < k.second)
				return false;
		}
		return true;
	}
public:
    string minWindow(string s, string t) {
		std::deque<int> minHeap;
		std::unordered_map<int,int> counter;
		std::unordered_map<int,int> templateCounter;
		for (auto ch : t){
			templateCounter[ch-'A'] += 1;
		}
		int ind = 0;
		int nMinLen = s.size()+1;
		std::string  strAns = "";

		for (auto ch : s){
            
			if (templateCounter.find(ch-'A') != templateCounter.end())
			{
				counter[ch-'A'] += 1 ;
                minHeap.push_back(ind);
				auto chHeapTop = s[minHeap.front()];
				while (minHeap.size() && counter[chHeapTop-'A'] > templateCounter[chHeapTop-'A']){
					minHeap.pop_front();
                    counter[chHeapTop-'A'] -= 1;
					chHeapTop = s[minHeap.front()];
				}


				if (equal(templateCounter,counter)){
					strAns = (ind - minHeap.front() + 1 < nMinLen) ? s.substr(minHeap.front(),ind - minHeap.front()+1) : strAns;
					nMinLen = std::min(ind - minHeap.front() + 1 , nMinLen);
				}
			}
            ind += 1 ;
		}
		return strAns;


        
    }
};


