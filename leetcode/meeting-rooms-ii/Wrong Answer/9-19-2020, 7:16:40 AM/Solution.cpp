// https://leetcode.com/problems/meeting-rooms-ii

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
		auto n = intervals.size();
		if (n == 0){
			return 0 ;
		}
		std::priority_queue<int,std::vector<int>,std::greater<int>> minQueue;
		std::sort(intervals.begin(),intervals.end(),[](const std::vector<int> &v1, 
													   const std::vector<int> &v2) { return v1[0] < v2[0];});

		int minRooms = 0;
		for (auto interval : intervals){
			auto start = interval[0];
			auto end = interval[1];
			while (minQueue.size() != 0 && minQueue.top() < start){
				minQueue.pop();
			}

			bool roomAvailable  =  bool(minRooms - minQueue.size()) ;
			minQueue.push(end);
			if (!roomAvailable){
				++minRooms;
			}
		}
		return minRooms;

        
    }
};
