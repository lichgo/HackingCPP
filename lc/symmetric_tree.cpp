/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if (root == NULL) return true;
		return _sym(root->left, root->right);
	}

	bool _sym(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		if (p == NULL || q == NULL || p->val != q->val || !_sym(p->left, q->right) || !_sym(p->right, q->left)) return false;
		return true;
	}
};