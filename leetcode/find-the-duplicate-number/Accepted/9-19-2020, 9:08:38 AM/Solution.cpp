// https://leetcode.com/problems/find-the-duplicate-number

#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		auto fastNode = nums[nums[0]];
		auto slowNode = nums[0];
		while (fastNode != slowNode){
			slowNode = nums[slowNode];
			fastNode = nums[nums[fastNode]];
		}
        //std::cout << slowNode << " " << fastNode << std::endl;
		fastNode = 0;//nums[0];
		while (slowNode != fastNode){
			slowNode = nums[slowNode];
			fastNode = nums[fastNode];
		}
		return fastNode;

    }
};
