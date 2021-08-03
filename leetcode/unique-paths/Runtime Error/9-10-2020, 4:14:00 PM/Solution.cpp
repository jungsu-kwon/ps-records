// https://leetcode.com/problems/unique-paths

class Solution {
public:
	long long int factorial(int n )
	{
		long long int  factorial = 1 ;
		for (auto t = 1; t <= n; ++t){
			factorial *= t;
		}
		return factorial;
	}
    int uniquePaths(int m, int n) {
		int total_steps = m+n-2;
		int choose = m-1;
		return int(factorial(total_steps) / (factorial(choose) * factorial(total_steps-choose)));
    }
};
