// https://leetcode.com/problems/unique-binary-search-trees-ii

#include <vector>
using namespace std;


class Solution {
private:
    void helper(vector<TreeNode*> &nodes,int start, int end)
    {
        if (start == end) 
        {
            nodes.push_back(new TreeNode(start));
            return;
        }
        else if (start > end) 
        {
            nodes.push_back(nullptr);
            return;
        }
       
        for (int root = start; root < end+1; ++root)
        {
            vector<TreeNode*> left_subtrees;
            helper(left_subtrees,start,root-1);
            
            vector<TreeNode*> right_subtrees;
            helper(right_subtrees,root+1,end);
            
            for (auto left:left_subtrees)
            {
                for (auto right:right_subtrees)
                {
                    TreeNode* root_node = new TreeNode(root);
                    root_node -> left = left;
                    root_node -> right = right;
                    nodes.push_back(root_node);
                }
            }
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans{};
        helper(ans,1,n);
        return ans;
        
    }
};