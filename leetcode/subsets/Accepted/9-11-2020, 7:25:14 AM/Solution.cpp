// https://leetcode.com/problems/subsets

class Solution {
private : 
	void increment(std::vector<int> &binary){
		auto carry = 1;
		for (auto it = binary.begin();it != binary.end(); ++it){
			*it += carry;
			carry = (*it==2);
			*it = (carry)? 0 : *it;
		}
	}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		std::vector<std::vector<int>> vecAns;
		if (nums.size() == 0){
            vecAns.push_back({});
            return vecAns;
            
        } 
		std::vector<int> binary(nums.size(),0);

	
		for (auto t = 0; t < std::pow(2,nums.size());++t){
			std::vector<int> ans;

			auto ind=0;
			for (auto bit : binary){
				if (bit) 
					ans.push_back(nums[ind]);
				++ind;
			}
			vecAns.push_back(ans);
			increment(binary);
		}
		return vecAns;
    }
};