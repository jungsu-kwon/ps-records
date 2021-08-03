// https://leetcode.com/problems/merge-k-sorted-lists

class Solution {
private : 
	ListNode* findMinNode(std::vector<ListNode*> &vecNodes,std::unordered_set<int> &setValidInds){
		ListNode* foundNode = nullptr;
		int nFoundInd = -1;
		for (auto t : setValidInds)
		{
			auto node = vecNodes[t];
			if (foundNode == nullptr){
				foundNode = node;
				nFoundInd = t;
			}
			else {
				nFoundInd = (foundNode->val < node->val) ? nFoundInd : t;
				foundNode = (foundNode->val < node->val) ? foundNode : node;
			}

		}
        if (foundNode != nullptr){
            vecNodes[nFoundInd] = vecNodes[nFoundInd]->next;
			if (vecNodes[nFoundInd] == nullptr)
				setValidInds.erase(nFoundInd);
        }
		    
        
		return foundNode;
		
	}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (!lists.size() ) return nullptr;
		std::unordered_set<int> setValidInds;
		auto ind = 0;
		for (auto node : lists){
			if (node != nullptr)
				setValidInds.insert(ind);
			ind += 1 ;
		}
		ListNode * head = new ListNode;
		auto curNode = head;
		auto foundNode = findMinNode(lists,setValidInds);
		while (foundNode != nullptr){
			curNode->next = foundNode;
			curNode = curNode->next;
			foundNode = findMinNode(lists,setValidInds);
		}

		return head->next;
        
    }
};
