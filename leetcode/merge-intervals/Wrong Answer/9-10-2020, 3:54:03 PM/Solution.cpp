// https://leetcode.com/problems/merge-intervals

class Solution {
public:
	bool overlap(std::vector<int> &interval1, std::vector<int> &interval2){
		if (interval2[0] < interval1[0]) return interval2[1] >= interval1[0];
		else return interval1[1] >= interval2[0];
	}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		std::vector<std::vector<int>> vecMerged;
		if (intervals.size() == 0 ) return vecMerged;

		std::sort(intervals.begin(),intervals.end(),
				[](const std::vector<int> &v1, std::vector<int> &v2){return v1[0] < v2[0];});

		vecMerged.push_back(intervals[0]);
		for (auto t = 0 ; t < intervals.size(); ++t){
			auto lastElem = vecMerged.back();
			if (overlap(lastElem,intervals[t]))
				vecMerged.back()[1] = intervals[t][1];
			else 
				vecMerged.push_back(intervals[t]);
		}
		
		return vecMerged;
        
    }
};
