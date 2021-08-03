// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode  head;
        ListNode *pHead = &head,*pPrev = &head;
        int nCarry = 0 ;
        int nSum = 0 ;
        while ( nCarry || l1 || l2){
            nSum = (l1 ? l1->val :0) + (l2? l2->val : 0)  + nCarry ; 
            nCarry = nSum / 10 ;
            ListNode* pCur = new ListNode(nSum%10);
            
            l1 = (l1? l1->next : l1);
            l2 = (l2? l2->next : l2);
            pPrev->next = pCur ; 
            pPrev = pCur;
            
        }
       return pHead->next;
    }
};