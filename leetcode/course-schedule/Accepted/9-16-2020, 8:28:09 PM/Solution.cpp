// https://leetcode.com/problems/course-schedule

#include <vector>
#include <iostream>
using namespace std;

class Solution {
private : 
	bool dfs(int classInd, std::vector<int> &visited, std::vector<int> &recurStack, std::vector<std::vector<int>> &graph){
		// return false if revisit visited nodes
		recurStack[classInd] = 1;
		visited[classInd] = 1;
		
		for (auto neighbor : graph[classInd])
		{
			if (visited[neighbor] == 0)
			{
				if ( !dfs(neighbor,visited,recurStack,graph))
					return false;
			}
			else if (recurStack[neighbor])
			{
				return false;
			}
		}
		recurStack[classInd] = 0;
		return true;

	}
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		std::vector<std::vector<int>> graph(numCourses);
		for (auto pre : prerequisites)
			graph[pre[0]].push_back(pre[1]);

		std::vector<int> visited(numCourses,0);
		std::vector<int> recurStack(numCourses,0);

		for (auto classInd = 0 ; classInd < numCourses; ++classInd){
			if (visited[classInd] == 0 ){
				if (dfs(classInd,visited,recurStack,graph) == false)
					return false;
				
			}

		}
		return true;


				
	}
};
