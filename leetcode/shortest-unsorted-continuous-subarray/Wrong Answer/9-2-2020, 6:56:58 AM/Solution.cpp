// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        // find left end of the range
        int firstDecrease = -1;
        for (auto t = 1; t < nums.size();++t ){
           if (nums[t] < nums[t-1]){
               firstDecrease = t;
               break;
           }
        }
        if (firstDecrease ==-1)
            return 0;
        
        // find right end of the range
        int lastDecrease = firstDecrease;
        for (auto t = firstDecrease; t < nums.size();++t){
            if (nums[t] < nums[t-1] || nums[t] < nums[firstDecrease-1]){
                lastDecrease = t;
            }
        }
        auto minMax = std::minmax_element(nums.begin()+firstDecrease,
                                          nums.begin()+lastDecrease);
        int mini = *minMax.first;
        int maxi = *minMax.second;
        std::cout<<"mini :" << mini << " maxi : " << maxi  << std::endl;
        
        int lowerBound = int(std::upper_bound(nums.begin(),
                                              nums.begin()+firstDecrease,
                                              mini)
                            -nums.begin()) ;
        int upperBound = int(std::lower_bound(nums.begin()+lastDecrease,
                                              nums.end(),maxi)-nums.begin());
        upperBound += int(nums[upperBound] == maxi);
          
        std::cout << "lower bound : " << lowerBound 
                  << " upper bound : " << upperBound << std::endl;
        
        return std::max(upperBound,lastDecrease) -
            std::min(firstDecrease,lowerBound);
        
        
        
        
        
        
        
        
    }
};