// https://leetcode.com/problems/sort-list

class Solution {
private:
	ListNode* mergeSort(ListNode* head,int listSize){
        
		if (listSize <= 1 || head ==nullptr)
			return head;
		ListNode* leftNode = head;
		ListNode* rightNode = head;
		ListNode* prevNode = nullptr;
		int rightInd = 0;
		while (rightInd < listSize /2 && rightNode != nullptr){
			prevNode = rightNode;
			rightNode = rightNode->next;
			rightInd += 1 ;

		}
		prevNode->next = nullptr;
		auto leftHead =  mergeSort(leftNode,listSize/2);
		auto rightHead = mergeSort(rightNode,listSize - (listSize/2));
		ListNode preHead(0);
		ListNode* curNode = &preHead;

		while (leftHead != nullptr && rightHead != nullptr){
			if (leftHead->val <= rightHead->val)
			{
				curNode->next = leftHead;
				leftHead = leftHead->next;
			}
			else{
				curNode->next = rightHead;
				rightHead = rightHead->next;
			}
			curNode = curNode->next;
		}
        if (rightHead != nullptr){
            curNode->next = rightHead;   
        }
        else if (leftHead != nullptr){
            curNode->next = leftHead;
        }

		return preHead.next;
	}

public:
	ListNode* sortList(ListNode* head) 
	{
		auto curNode = head;
		auto listSize  = 0 ;
		while (curNode != nullptr){
			++listSize;
			curNode = curNode->next;
		}

		return mergeSort(head,listSize);
	}
};

