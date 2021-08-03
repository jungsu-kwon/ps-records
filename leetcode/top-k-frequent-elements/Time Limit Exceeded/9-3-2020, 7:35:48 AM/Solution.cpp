// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    int partition(std::vector<int>& keys,
                  std::map<int,int> &hash,
                  int left, int right,int pivotIndex
                 ){
        std::swap(keys[pivotIndex],keys[right]);
        auto pivotValue = hash[keys[right]];
        auto storeIndex = left ;
        for (auto t = 0 ; t < keys.size()-1;++t ){
            if (hash[keys[t]] < pivotValue){
                std::swap(keys[t],keys[storeIndex]);
                storeIndex += 1;
            }
        }
        std::swap(keys[storeIndex],keys[right]);
        //std::cout << "#########"<<std::endl;
        //std::cout << "k : " << pivotIndex <<std::endl;
        //for (auto key : keys){
        //    std::cout << "key : " << key <<" "<< hash[key] 
        //        << std::endl;
        //}
        //std::cout << "#########"<<std::endl;
        return storeIndex;
    }
    int SelectTopK(std::vector<int>& keys,
                    std::map<int,int> &hash,
                   int left,int right, int k){
        if (left == right){
            return keys[left];
        }
        auto pivotIndex = (left + right) / 2 ;
        //std::cout << "pivontIndex : " << pivotIndex << std::endl;
        //std::cout << " k : " << k << std::endl;
        pivotIndex = partition(keys,hash,left,right,pivotIndex);
        if (pivotIndex == k)
        {
            //std::cout << "ret val : " << keys[k] <<std::endl;
            return keys[k];
        }
        else if (pivotIndex < k){
           return SelectTopK(keys,hash,pivotIndex+1,right,k) ;
        }
        else
           return SelectTopK(keys,hash,left,pivotIndex-1,k) ;
        return -1;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // construct hash map
        std::map<int,int> hash ;
        for (auto num : nums){
            hash[num] += 1 ;
        }
        // store index into vector
        std::vector<int> index;
        for (auto t = hash.begin();t != hash.end();++t){
            index.push_back(t->first);
        }
        // select top k index
        std::vector<int> ans ;
        for (auto t = 0 ; t < k ; ++t){
            ans.push_back(SelectTopK(index,
                                     hash,
                                     0,
                                     index.size()-1,
                                     index.size()-t-1));
        }
        // return the answers
        return ans;
    }
};