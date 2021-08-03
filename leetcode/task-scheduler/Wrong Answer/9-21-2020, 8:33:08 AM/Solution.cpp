// https://leetcode.com/problems/task-scheduler

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
		std::unordered_map<int,int> counter;
		if (tasks.size() == 0 ) return 0;
		auto numTasks = tasks.size();
		auto ind = 0;
		auto maxi = 0;


		while (ind != tasks.size()-1){
			auto count = 0 ;
			auto prevChar = tasks[ind];
			while (ind != tasks.size()-1 && tasks[ind] == prevChar){
				ind += 1;
				count += 1 ;
			}
            if (ind == tasks.size()-1) ++count;
			counter[count] += 1;
			maxi = std::max(maxi,count);
		}
		auto initIdle = std::max(0,n-counter[maxi]+1)*(maxi-1);
		auto nonBottleNeck = numTasks - maxi*counter[maxi];
        std::cout << nonBottleNeck << std::endl;
        std::cout << initIdle << std::endl;
        std::cout << maxi << std::endl;
		if (initIdle == 0 || initIdle < nonBottleNeck)
			return tasks.size();
		return (maxi-1)*(n+1) + counter[maxi];
    }
};


