// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

#include <unordered_set>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     // TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
 
class Solution {
private:
    bool find_node(TreeNode* root, int val,unordered_set<int>& hash)
    {
        if (!root) return root;
        if (root -> val == val)
            hash.insert(root->val);

        else if (find_node(root->left,val,hash))
        {
            hash.insert(root->left->val);
            hash.insert(root->val);
        }

        else if (find_node(root->right,val,hash))
        {
            hash.insert(root->right->val);
            hash.insert(root->val);
        }

        return hash.find(root->val) != hash.end();
    }
    bool in_hash(unordered_set<int>& hash, TreeNode* node)
    {
        if (!node) return false;
        return hash.find(node->val) != hash.end();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<int> hash_q;
        unordered_set<int> hash_p;

        if (!root) return root;
        find_node(root,p->val,hash_p);
        find_node(root,q->val,hash_q);

        auto cur_node = root;
        while (cur_node)
        {
            auto p_root  = in_hash(hash_p,cur_node);
            auto p_left  = in_hash(hash_p,cur_node->left);
            auto p_right = in_hash(hash_p,cur_node->right);

            auto q_root  = in_hash(hash_q,cur_node);
            auto q_left  = in_hash(hash_q,cur_node->left);
            auto q_right = in_hash(hash_q,cur_node->right);

            if (p_root || q_root)
                return cur_node;
            else if (p_left && q_left)
                cur_node = cur_node -> left;
            else if (p_right && q_right)
                cur_node = cur_node -> right;
            else return cur_node;
        }
        return root;

        
    }
};