// https://leetcode.com/problems/subarray-sum-equals-k

#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0 ;

		auto sum = 0 ;
		int count = 0;
		std::unordered_map<int,int> hash;
        hash[0] = 1;
		for (auto t = 0; t < nums.size(); ++t){
			sum += nums[t];
            if (hash.find(k-sum) != hash.end()){
                count += hash[k-sum];
            }
			hash[sum] += 1;

		}
   
		return count; 
    }
};


