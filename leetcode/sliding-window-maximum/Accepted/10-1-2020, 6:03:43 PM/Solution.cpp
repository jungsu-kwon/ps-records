// https://leetcode.com/problems/sliding-window-maximum

#include <deque>
#include <vector>
using namespace std;
class Solution {
private : 
	void cleanDeque(std::deque<int> &dequeInd,std::vector<int>&nums,int i,int k ){
		if (dequeInd.size() && dequeInd.front() == i-k)
			dequeInd.pop_front();
		while (dequeInd.size() && nums[dequeInd.back()] <  nums[i]){
			dequeInd.pop_back();
		}
	}
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		std::deque<int> dequeInd;
		std::vector<int> vecAns(nums.size()-k+1,0);
		
		// initialize deque
		for (auto t = 0; t < k; ++t){
			cleanDeque(dequeInd,nums,t,k);
			dequeInd.push_back(t);
		}
		vecAns[0] = nums[dequeInd.front()];

		for (auto t = k;t < nums.size(); ++t){
			cleanDeque(dequeInd,nums,t,k);
			dequeInd.push_back(t);
			vecAns[t-k+1] = nums[dequeInd.front()];
		}
		return vecAns;
    }
};
