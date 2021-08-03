// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

#include <algorithm>
#include<vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* helper(vector<int>::iterator pre_start,
                     vector<int>::iterator pre_end,
                     vector<int>::iterator in_start,
                     vector<int>::iterator in_end
    )
    {
        if (pre_start == pre_end || in_start == in_end)  
            return nullptr;

        auto root_val = *pre_start;

        auto root = new TreeNode(root_val);

        auto root_it = find(in_start,in_end,root_val);
        auto offset  = distance(in_start,root_it);

        root->left  = helper(pre_start+1,pre_start+1+offset,in_start,root_it);
        root->right = helper(pre_start+1+offset,pre_end,root_it+1,in_end);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
        
    }
};