// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		auto n = matrix.size();
		// t is equal to row index
		std::vector<int> vecTemp(matrix.size(),0);
		for (auto t = 0 ; t < n /2; ++t){
			// save to temp before writing
			for(auto i = 0; i < n-1-2*t;++i){
				auto temp = matrix[t+i][n-1-t];
				matrix[t+i][n-1-t] = matrix[t][t+i];
				matrix[t][t+i] = matrix[n-1-t-i][t];
				matrix[n-1-t-i][t] = matrix[n-1-t][n-1-i-t];
				matrix[n-1-t][n-1-i-t] = temp;
			}
		}
        
    }
};
