// https://leetcode.com/problems/task-scheduler

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
		auto numAlphabet = 'Z' - 'A' + 1 ;
		std::vector<int> counter(numAlphabet,0);
		auto maxCount = 0;
		auto numMaxTasks = 0;

		for (auto task : tasks){
			counter[task-'A'] += 1 ;
			if (counter[task-'A'] >  maxCount){
				numMaxTasks = 1;
				maxCount = counter[task-'A'];
			}
			else if (counter[task-'A'] == maxCount)
				numMaxTasks += 1 ;
		}

		auto nonBottleNeck = tasks.size() - maxCount;
		auto initIdle = n * (maxCount-1);

		if (initIdle < nonBottleNeck)
			return tasks.size();
		return (maxCount-1) * (n+1) + numMaxTasks;
		
    }
};


