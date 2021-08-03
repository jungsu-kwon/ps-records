// https://leetcode.com/problems/unique-binary-search-trees


class Solution {
public:
	int helper(int numNodes,std::vector<int> &vecDp)
	{
		if (vecDp[numNodes] != -1)
			return vecDp[numNodes] ;
		int curTrees = 0;
		for (auto numLeft = 0 ; numLeft < numNodes; ++numLeft){
			auto numRight = numNodes - numLeft - 1 ;
			curTrees += helper(numLeft,vecDp) * helper(numRight,vecDp);
		}

		return curTrees;
	}
	int numTrees(int n) {
		std::vector<int> vecDp(n+1,-1);
		vecDp.front() = 1;
		for (auto t = 1 ; t <= n ; ++t){
			vecDp[t] = helper(t, vecDp);
		}
		return vecDp.back();
	}
};
