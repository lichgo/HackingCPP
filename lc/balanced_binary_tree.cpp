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
	bool isBalanced(TreeNode *root) {
		bool result = true;
		height(root, &result);
		return result;
	}

	int height(TreeNode* root, bool* result) {
		if (root == NULL) return 0;
		int leftHeight = height(root->left, result) + 1;
		int rightHeight = height(root->right, result) + 1;
		if (abs(leftHeight - rightHeight) > 1) *result = false;
		return (leftHeight > rightHeight ? leftHeight : rightHeight);
	}
};