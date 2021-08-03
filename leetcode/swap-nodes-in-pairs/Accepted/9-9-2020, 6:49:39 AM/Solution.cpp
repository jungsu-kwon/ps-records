// https://leetcode.com/problems/swap-nodes-in-pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		ListNode *curNode1, *curNode2;
		ListNode *prevNode, *nextNode;

		ListNode *preHead = new ListNode;
		preHead->next = head;
		prevNode = preHead;

		while (prevNode != nullptr){
			curNode1 = prevNode->next;

			if (curNode1 == nullptr || curNode1->next == nullptr) 
				return preHead->next;

			curNode2 = curNode1->next;
			nextNode = curNode2->next;

			prevNode->next = curNode2;
			curNode1->next = nextNode;
			curNode2->next = curNode1;

			//std::swap(curNode1,curNode2);
			prevNode = curNode1;
		}
		return preHead->next;
        
    }
};
