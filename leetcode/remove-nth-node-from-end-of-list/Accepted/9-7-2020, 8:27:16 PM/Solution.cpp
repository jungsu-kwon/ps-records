// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::stack<ListNode*> stackNode;
        ListNode* curNode = head ;
        while (curNode != nullptr){
			stackNode.push(curNode);
			curNode = curNode->next;
		}
		ListNode *nextNode=nullptr;
		for (auto t = 0 ; t < n-1; ++t){
			nextNode = stackNode.top();
			stackNode.pop();
		}
		stackNode.pop();
        if (stackNode.size() == 0 )
            return head->next;
		auto prevNode = stackNode.top();
		prevNode->next = nextNode;
		return head;
    }
};
