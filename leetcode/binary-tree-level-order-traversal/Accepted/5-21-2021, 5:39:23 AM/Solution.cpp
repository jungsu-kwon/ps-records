// https://leetcode.com/problems/binary-tree-level-order-traversal

#include <vector>
#include <queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (!root) return ans;
        
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while (bfs.size())
        {
            auto bfs_size = bfs.size();
            vector<int> level;
            for (auto i = 0; i < bfs_size; ++i)
            {
                auto node = bfs.front();
                bfs.pop();

                level.push_back(node -> val);

                if (node -> left) bfs.push(node->left);
                if (node -> right) bfs.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};