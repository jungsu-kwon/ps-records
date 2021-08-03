// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

#include <algorithm>
#include <iostream>
#include <vector>
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
    TreeNode* helper(vector<int>::iterator in_start, 
                     vector<int>::iterator in_end, 
                     vector<int>::iterator post_start, 
                     vector<int>::iterator post_end)
    {
        if (in_start == in_end || post_start == post_end) return nullptr;
        auto root_val = *(post_end - 1);
        
        auto root = new TreeNode(root_val);

        auto root_it = find(in_start,in_end,root_val);

        auto offset = distance(in_start,root_it);
        root -> left  = helper(in_start,root_it,post_start,post_start+offset);
        
        root -> right = helper(root_it+1,in_end,post_start+offset,post_end-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
        
    }
};