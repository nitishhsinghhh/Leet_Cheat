#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
	int sumRootToLeaf(TreeNode* root, int curr_val = 0) {
		if (!root)
			return 0;
		curr_val = curr_val * 2 + root->val;
		return root->left == root->right ? curr_val : sumRootToLeaf(root->left, curr_val) + sumRootToLeaf(root->right, curr_val);
	}
};

int main() {
	// Create the binary tree
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(0);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(1);

	Solution oSolution;
	int res = oSolution.sumRootToLeaf(root);
	cout << res << endl;

	TreeNode *root1 = new TreeNode(0);
	res = oSolution.sumRootToLeaf(root1);
	cout << res << endl;

	return 0;
}
