// https://leetcode.com/problems/number-of-islands

#include <vector>
#include <iostream>
using namespace std;
class Solution {
private : 
	std::vector<std::vector<int>> validChildren(std::vector<std::vector<char>> &grid,int i, int j){
		std::vector<std::vector<int>> vecChildren;
		std::vector<std::vector<int>> vecCands{{i-1,j},{i+1,j},{i,j-1},{i,j+1}};
		for (auto cand : vecCands){
			if (cand[0] >=0 && cand[0] < nHeight && cand[1] >=0 && cand[1] < nWidth)
                if (grid[cand[0]][cand[1]] == '1'){
                    grid[cand[0]][cand[1]] = 'v';
				    vecChildren.push_back(cand);    
                }
				
		}
		return vecChildren;
	}
	void bfs(std::vector<std::vector<char>> &grid,int i , int j){
		std::vector<std::vector<int>> coords{std::vector<int>{i,j}};
		grid[i][j] = 'v';
		while (coords.size() != 0){
			auto coordSize = coords.size();
			std::vector<std::vector<int>> newCoords;
			for (auto coord : coords){
				for (auto child : validChildren(grid,coord[0],coord[1])){
					newCoords.push_back(child);
				}
			}
			coords = newCoords;
		}



	}
public:
	int nWidth = 0 ;
	int nHeight = 0 ;
	int numIslands(vector<vector<char>>& grid) {
		nHeight = grid.size() ;
		nWidth = (nHeight == 0) ? 0 : grid[0].size();
		if (nHeight == 0 || nWidth == 0)
			return 0 ;

		int numIslands = 0;
		for (auto i = 0 ; i < nHeight ; ++i){
			for (auto j = 0 ; j < nWidth; ++j){
				if (grid[i][j] == '1'){
					bfs(grid,i,j);
					++numIslands ;
				}

			}
		}
		return numIslands;



			
	}
};
