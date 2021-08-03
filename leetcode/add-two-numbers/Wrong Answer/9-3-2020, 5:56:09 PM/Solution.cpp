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
   
private:
    int convertToNumber(ListNode* l1){
        if (l1 == nullptr)
            return 0;
        auto res = 0;
        auto curNode = l1;
        while (curNode != nullptr){
            res += curNode->val;
            if (curNode->next != nullptr)
                res *= 10;
            curNode = curNode->next;
        }
        return res;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto sum = convertToNumber(l1) + convertToNumber(l2);
        std::vector<int> resNums;
        while (sum > 0 ){
            resNums.push_back(sum % 10);
            sum /= 10;
        }
             
        ListNode *preHead = new ListNode();
        ListNode *curNode = preHead;
        for (auto it = resNums.begin(); it != resNums.end(); ++it){
            curNode->next = new ListNode(*it);
            curNode = curNode->next;
        }
        return preHead->next;
    }
};