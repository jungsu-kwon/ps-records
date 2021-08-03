// https://leetcode.com/problems/palindrome-linked-list

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
    int getLength(ListNode* head){
        if (head == nullptr)
            return 0;
        int nLength = 0 ;
        while (head != nullptr)
        {
            nLength += 1 ;
            head = head->next;
        }
        return nLength;
    }
    ListNode* proceedNTimes(ListNode* head,int n){
        ListNode* curNode  = head;
        // will not perform validity check for performance issue
        for (auto t = 0; t < n;++t)
            curNode = curNode->next;
        return curNode;
    }
    ListNode* invertNodes(ListNode* head){
        ListNode* curNode = head;
        ListNode* prevNode = nullptr;
        ListNode* tempNode = nullptr;
        while(curNode != nullptr){
            tempNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = tempNode;
        }
        //for (auto node = prevNode; node != nullptr; node = node->next)
        //    std::cout << node->val << endl;
        return prevNode;
    }

    bool isPalindrome(ListNode* head) {
       // compute length of ll 
        int nLength = getLength(head);
        if (nLength <= 1)
            return true;
        // get mid node
        ListNode* leftNode = proceedNTimes(head,(nLength/2)-1);
        ListNode* rightNode = (nLength % 2) ? leftNode->next->next : leftNode->next;
        leftNode->next = nullptr;
        
        
        // invert left half
        leftNode = invertNodes(head);
        
        while(leftNode != nullptr){
            if (leftNode->val != rightNode->val)
                return false;
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }
        return true;
        
        
    }
};