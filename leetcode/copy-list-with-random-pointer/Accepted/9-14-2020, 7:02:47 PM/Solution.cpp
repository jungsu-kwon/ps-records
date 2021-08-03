// https://leetcode.com/problems/copy-list-with-random-pointer


class Solution {
private : 
	void insertCopyList(Node* head){
		auto curNode = head;
		Node* insertNode = nullptr;
		while (curNode != nullptr){
			insertNode = new Node(curNode->val);
			insertNode->random = curNode->random;
			auto nextNode = curNode->next;
			insertNode->next = nextNode;

			curNode->next = insertNode;
			curNode = nextNode;
		}
	}
	void changeRandom(Node* head){
		auto curNode = head;
		while (curNode != nullptr){
			auto copyNode = curNode->next;
			copyNode->random = (copyNode->random == nullptr) ? nullptr : copyNode->random->next;
			curNode = copyNode->next;
		}
	}
	
	void splitCopyList(Node* head){
		auto curNode = head;
		while (curNode != nullptr){
			auto copyNode = curNode->next;
			curNode->next = copyNode->next;
			curNode = curNode->next;
			copyNode->next = (curNode == nullptr) ? nullptr : curNode->next;
		}

	}

public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return nullptr;
		insertCopyList(head);
		auto copyHead = head->next;

		changeRandom(head);
		splitCopyList(head);

		return copyHead;
	}
};
