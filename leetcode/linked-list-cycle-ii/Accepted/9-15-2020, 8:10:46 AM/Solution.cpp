// https://leetcode.com/problems/linked-list-cycle-ii


class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr) return nullptr;
		ListNode* fastNode = head->next;
		ListNode* slowNode = head;
		std::vector<ListNode*> vecSlowNodes;
		while (fastNode != nullptr)
		{
            vecSlowNodes.push_back(slowNode);
			if (fastNode == slowNode){
				break;
			}

			fastNode = (fastNode->next == nullptr) ? nullptr : fastNode->next->next;
			slowNode = slowNode->next;
		}
		// no cycle
		if (fastNode == nullptr) return nullptr;
		// cycle exists 
		std::vector<ListNode*> vecFastNodes;
		for (auto t = 0; t < vecSlowNodes.size(); ++t){
			fastNode = fastNode->next;
            vecFastNodes.push_back(fastNode);
		}
        auto itSlow = vecSlowNodes.rbegin();
        auto itFast = vecFastNodes.rbegin();
        for (; itSlow != vecSlowNodes.rend() ;++itSlow, ++itFast){
            if (*itSlow != *itFast)
                return (*itSlow)->next;
        }
        return vecFastNodes[0];
	}
};

