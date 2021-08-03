// https://leetcode.com/problems/queue-reconstruction-by-height

#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		auto numPersons = people.size();
		if (numPersons == 0 ) return std::vector<std::vector<int>>{};
		std::vector<std::vector<int>> queue(numPersons,std::vector<int>{-1,-1});

		std::sort(people.begin(),people.end(),[](std::vector<int> &v1,std::vector<int> &v2){return v1[0] < v2[0];});

		for (auto person : people){
			auto frontCount = 0;
			auto targetCount = person[1];
			auto ind = 0 ;
            
			while (frontCount != targetCount )
			{
				if (queue[ind][0] == -1 || queue[ind][0] == person[0]){
					++frontCount;
				}
				++ind;
			}
            while (queue[ind][0] != -1)
                ++ind;
			queue[ind] = person;
		}
		return queue;
        
    }
};
