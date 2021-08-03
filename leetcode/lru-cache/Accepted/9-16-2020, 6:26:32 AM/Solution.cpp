// https://leetcode.com/problems/lru-cache

class LRUCache {
public:

    int size;
    unordered_map<int, list<int>::iterator> key2node;
    unordered_map< int, int > key2val;
    list<int> lst;

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(key2val.find(key) == key2val.end()) return -1;
        lst.erase(key2node[key]);
        lst.push_front(key);
        key2node[key] = lst.begin();
        return key2val[key];
    }
    
    void put(int key, int value) {
        if(key2val.find(key) == key2val.end()){
            if(lst.size() == size){
                key2val.erase(lst.back());
                key2node.erase(lst.back());
                lst.pop_back();
            }
        }
        else{
            lst.erase(key2node[key]);
        }
        lst.push_front(key);
        key2node[key] = lst.begin();
        key2val[key] = value;
    }
};
