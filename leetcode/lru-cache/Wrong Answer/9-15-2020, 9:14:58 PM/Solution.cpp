// https://leetcode.com/problems/lru-cache


struct LinkedList {
    int val;
	int key;
    LinkedList *next;
	LinkedList *prev;

    LinkedList(int k,int x) : key(k), val(x), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
	int num_elems = 0 ; 
	int num_max_elems = 0 ;
	std::unordered_map<int,LinkedList*> hash;
	LinkedList* head; 
	LinkedList* tail;

	LRUCache(int capacity) {
		num_max_elems = capacity;
		head = new LinkedList(0,0);
		tail = new LinkedList(0,0);
		head->next = tail;
		tail->prev = head;

	}

	int get(int key) {
		auto itFound = hash.find(key);
		if (itFound != hash.end()){
			auto curNode = hash[key];
			auto prevNode = curNode->prev;
			auto nextNode = curNode->next;

			prevNode->next = nextNode;
			nextNode->prev = prevNode;

			auto firstNode = head->next;
			head->next = curNode;
			curNode->prev = head;

			curNode->next = firstNode;
			firstNode->prev = curNode;
			return itFound->second->val;
		}

		return -1;
	}


	void put(int key, int value) 
	{
        

		LinkedList* nodeToPut = nullptr;
		if (num_elems == num_max_elems){
			auto lastNode = tail->prev;
			auto prevNode = lastNode->prev;
			prevNode->next = tail;
			tail->prev = prevNode;
			hash.erase(lastNode->key);

			nodeToPut = lastNode;
			nodeToPut->key = key;
			nodeToPut->val = value;
		}
		else 
			nodeToPut = new LinkedList(key,value);

		hash[nodeToPut->key] = nodeToPut;

		auto firstNode = head->next;
		head->next = nodeToPut;
		nodeToPut->prev = head;
		
		firstNode->prev = nodeToPut;
		nodeToPut->next = firstNode;
        num_elems = std::min(num_max_elems,num_elems+1);
		
	}
};

/**
 *  * Your LRUCache object will be instantiated and called as such:
 *   * LRUCache* obj = new LRUCache(capacity);
 *    * int param_1 = obj->get(key);
 *     * obj->put(key,value);
 *      */
