// https://leetcode.com/problems/kth-smallest-element-in-a-bst


class Solution {

private : 
	int count = 0;
	int target = 0;
	int found = 0 ;

	bool findKth(TreeNode* root){
		if (root == nullptr) return false ; 
		if (findKth(root->left))
			return true;
		++count;
		if (count == target){
			found = root->val;
			return true;
		}
		return findKth(root->right);



		return findKth(root->right);
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		target = k;
		findKth(root);
		return found;
			
	}
};
