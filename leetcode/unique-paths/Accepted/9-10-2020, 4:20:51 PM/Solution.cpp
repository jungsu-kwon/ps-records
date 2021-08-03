// https://leetcode.com/problems/unique-paths

class Solution {
public:
	unsigned long long int factorial(int n,int start =1)
	{
		unsigned long long int factorial = 1 ;
		for (auto t = start+1; t <= n; ++t){
			factorial *= t;
		}
		return factorial;
	}
    int uniquePaths(int m, int n) {
		int total_steps = m+n-2;
		int choose = m-1;
		return int(factorial(total_steps,std::max(choose,total_steps-choose)) / factorial(std::min(choose,total_steps-choose)));

    }
};
