// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
private: 
    int partition(std::vector<int> &keys,
                  std::map<int,int> &hash, 
                  int left, 
                  int right, 
                  int pivotIndex){

        // return storeIndex
        auto pivotValue = hash[keys[pivotIndex]];
        std::swap(keys[pivotIndex],keys[right]);
        auto storeIndex = left;

        for (auto t = left; t < right;++t){
            if (hash[keys[t]] < pivotValue){
                std::swap(keys[t],keys[storeIndex]);
                storeIndex += 1 ;
            }
        }
        std::swap(keys[storeIndex],keys[right]);
        return storeIndex;
    }
    void select(std::vector<int> &keys,
                std::map<int,int> &hash,
                int left,
                int right,
                int k)
    {
        if (left == right)
            return ;
        auto pivotIndex = (left + right) / 2 ;
        pivotIndex = partition(keys,hash,left,right,pivotIndex);

        if (pivotIndex == k){
            return;
        }
        else if (k < pivotIndex){
            select(keys,hash,left,pivotIndex-1,k);
            return;
        }
        else{
            select(keys,hash,pivotIndex+1,right,k);
            return;
        }
        return;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int,int> hash ; 
        for (auto num : nums){
            hash[num] += 1 ;
        }
        std::vector<int> keys;
        for (auto it = hash.begin(); it != hash.end(); ++it){
            keys.push_back(it->first);
        }
        select(keys,hash,0,keys.size()-1,k);
        std::vector<int> ans;
        for (auto t = k-1; t < keys.size();++t){
            ans.push_back(keys[t]);
        }
        return ans;
    }
};
