// https://leetcode.com/problems/merge-k-sorted-lists

class Solution {
private : 
	ListNode* findMinNode(std::vector<ListNode*> &vecNodes){
		ListNode* foundNode = nullptr;
		int ind = 0; 
		int nFoundInd = -1;
		for (auto node : vecNodes){
			if (node != nullptr){
				if (foundNode == nullptr){
					foundNode = node;
                    nFoundInd = ind;
				}
				else {
					nFoundInd = (foundNode->val < node->val) ? nFoundInd : ind;
					foundNode = (foundNode->val < node->val) ? foundNode : node;
				}
			}
			ind += 1 ;
		}
        if (foundNode != nullptr){
            vecNodes[nFoundInd] = vecNodes[nFoundInd]->next;
        }
		    
        
		return foundNode;
		
	}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (!lists.size() ) return nullptr;
		ListNode * head = new ListNode;
		auto curNode = head;
		auto foundNode = findMinNode(lists);
		while (foundNode != nullptr){
			curNode->next = foundNode;
			curNode = curNode->next;
			foundNode = findMinNode(lists);
		}

		return head->next;
        
    }
};
