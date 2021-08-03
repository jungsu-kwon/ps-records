// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    // key = {value, prekey, postkey}
    unordered_map<int, vector<int>>  cache;
    int firstKey;
    int lastKey;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int retval = -1;
        if(cache.find(key) != cache.end()){
            retval = cache[key][0];
            
            // if searching key is the same is firstkey, then do nothing
            if(key == firstKey) {
                return retval;
            } else if(key == lastKey){
                lastKey = cache[lastKey][2];
                cache[lastKey][1] = -1;
            } else {
                // moving new key to first
                int currentKeyPre = cache[key][1];
                int currentKeyPost = cache[key][2];
                cache[currentKeyPre][2] = currentKeyPost;
                cache[currentKeyPost][1] = currentKeyPre;    
            }
            
            cache[key] = {retval, firstKey, -1};
            //moving firstKey one step behind the new first key
            cache[firstKey][2] = key;
            firstKey = key;
            
        }
        return retval;
    }
    
    void put(int key, int value) {
        // initial stage
        if(cache.size() == 0){
            cache[key] = {value, -1, -1};
            firstKey = key;
            lastKey = key;
        } 
        else {
            if(cache.find(key) != cache.end()){
                cache[key][0] = value;
                get(key);
                return;
            }
            cache[key] = {value, firstKey, -1};
            //moving firstKey one step behind the new first key
            cache[firstKey][2] = key;
            firstKey = key;
            
            // removing last Item
            if(cache.size() > capacity) {
                int tempLastKey = cache[lastKey][2];
                cache.erase(lastKey);
                lastKey = tempLastKey;
                cache[lastKey][1]  = -1;
            }
        }

    }
};