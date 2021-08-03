// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int nLength = 0; 
    ListNode *getTail(ListNode *head){
        ListNode *curNode = head;
        ListNode *temp = nullptr;
        
        nLength = 0 ;
        
        while (curNode != nullptr){
            temp = curNode;
            curNode = curNode->next;
            nLength += 1;
        }
        return temp;
    }

        
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tailA,*tailB,*tempNode;
        tailA = getTail(headA);
        int nLengthA = nLength;
        tailB = getTail(headB);
        int nLengthB = nLength;
        
        if (tailA != tailB)
            return nullptr;
        
        int nStepA = (nLengthA > nLengthB )? nLengthA-nLengthB : 0;
        int nStepB = (nLengthA > nLengthB )? 0 : nLengthB-nLengthA;
        for (auto t = 0; t < nStepA; ++t){
            headA = headA->next;
        }
        for (auto t = 0; t < nStepB; ++t){
            headB = headB->next;
        }
        while (headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
        
        
        
    }
};