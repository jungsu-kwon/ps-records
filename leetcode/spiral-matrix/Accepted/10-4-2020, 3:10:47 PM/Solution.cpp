// https://leetcode.com/problems/spiral-matrix

#include <vector>
using namespace std;
class Solution {
private :
	void helper(vector<vector<int>> &matrix,vector<int> &vecAns,int l, int r, int up, int down,int ind)
	{


		if (l > r || up > down) return;
		else if (l == r ){
			for (auto i = up; i != down+1; ++i){
				vecAns[ind] = matrix[i][l];
				ind += 1 ;
			}
		}
		else if (up == down){
			for (auto j = l; j != r + 1; ++j){
				vecAns[ind] = matrix[up][j];
				ind += 1;
			}
		}
		else {
			for (auto j = l; j < r+1; ++j)
			{
				vecAns[ind] = matrix[up][j];
				ind += 1;
			}
			for (auto i = up+1; i < down+1; ++i){
				vecAns[ind] = matrix[i][r];
				ind += 1;
			}

			for (auto j = r-1; j >= l; --j){
				vecAns[ind] = matrix[down][j];
				ind +=1 ;
			}

			for (auto i = down-1; i > up ; --i){
                vecAns[ind] = matrix[i][l];
				ind += 1 ;
			}
			helper(matrix,vecAns,l+1,r-1,up+1,down-1,ind);

		}


		

	}
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (!matrix.size() || !matrix[0].size()) return std::vector<int>{};
		auto l = 0, up = 0;
		auto r = matrix[0].size()-1, down = matrix.size()-1;
		std::vector<int> vecAns(matrix.size() * matrix[0].size(),0);
		auto ind = 0 ;

		helper(matrix,vecAns,l,r,up,down,ind);
		return vecAns;
    }
};
