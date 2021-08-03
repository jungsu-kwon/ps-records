// https://leetcode.com/problems/lru-cache

#include <iostream>
#include <unordered_map>
#include <algorithm>

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
		if (hash.find(key) != hash.end())
		{
			auto curNode = hash[key];
			bringFront(curNode);
			return curNode->val;
		}
		return -1;
	}
	void print(){
		auto curNode = head;
		while (curNode != nullptr){
			std::cout << curNode->key << " " << curNode->val << std::endl;
			curNode = curNode->next;
		}
	}
	void bringFront(LinkedList* node){
		auto prevNode = node->prev;
		auto nextNode = node->next;

		if (prevNode != nullptr && nextNode != nullptr)
		{
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
		}

		auto firstNode = head->next;
		head->next = node;
		node->prev = head;

		node->next = firstNode;
		firstNode->prev = node;


	}

	void put(int key, int value) 
	{
		if (hash.find(key) != hash.end())
		{
			hash[key]->val = value;
			bringFront(hash[key]);
			return ;
		}
		LinkedList* nodeToAdd = nullptr;
		if (num_elems == num_max_elems)
		{
			auto nodeToPop = tail->prev;
			hash.erase(nodeToPop->key);

			nodeToAdd = nodeToPop;
			nodeToAdd->key = key;
			nodeToAdd->val = value;
			
		}
		else
		{
			nodeToAdd = new LinkedList(key,value);
		}
		hash[key] = nodeToAdd;
		num_elems = std::min(num_elems+1,num_max_elems);
		bringFront(nodeToAdd);

	}
};

/**
 *  * Your LRUCache object will be instantiated and called as such:
 *   * LRUCache* obj = new LRUCache(capacity);
 *    * int param_1 = obj->get(key);
 *     * obj->put(key,value);
 *      */
