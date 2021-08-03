// https://leetcode.com/problems/partition-labels

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private :
	bool overlap(std::vector<int> &v1, std::vector<int> &v2){
		if (v1[1] > v2[0]) return true;
		return false;
	}
public:
    vector<int> partitionLabels(string S) {
		std::vector<int> vecAns;
		if (S.size() == 0) return vecAns;

		std::vector<int> lastOccurence('Z'-'A'+1,-1);
		std::vector<int> firstOccurence('Z'-'A'+1,S.size());

		auto ind = 0;
		for (auto ch : S){
			firstOccurence[ch-'a'] = std::min(ind,firstOccurence[ch-'a']);
			lastOccurence[ch-'a'] = std::max(ind,lastOccurence[ch-'a']);
            ++ind;
		}
		ind = 0;
		std::vector<std::vector<int>> vecStartEnd;
		for (auto last : lastOccurence){
			if (last != -1){
				auto start = firstOccurence[ind];
				std::vector<int> vecChStartEnd{start,last};
				vecStartEnd.push_back(vecChStartEnd);
			}
			++ind;
		}

		std::sort(vecStartEnd.begin(),vecStartEnd.end(),[] (std::vector<int> &v1,std::vector<int> &v2) {return v1[0] < v2[0];});
		std::vector<std::vector<int>> vecStack;

		for (auto startEnd : vecStartEnd){
			if (vecStack.size() ==0) {
				vecStack.push_back(startEnd);
			}
			else if (overlap(vecStack.back(),startEnd)){
				vecStack.back()[1] = std::max(vecStack.back()[1],startEnd[1]);
			}
			else {
				vecStack.push_back(startEnd);
			}
		}

		for (auto split : vecStack)
			vecAns.push_back(split[1]-split[0] + 1);
		return vecAns;
        
    }
};
