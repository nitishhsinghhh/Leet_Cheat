#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root, int num = 0) {
		if (!root)
			return 0;
		num = num * 10 + root->val;
		return root->left == root->right ? num : sumNumbers(root->left, num) + sumNumbers(root->right, num);
	}
};

int main() {
	Solution oSolution;

	//  create the binary tree
  // Input: root = [1,2,3]
	TreeNode *root  = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);	
	int res = oSolution.sumNumbers(root);
	cout << "The Sum Root to Leaf Numbers is: " << res << endl;

  // Input: root = [4,9,0,5,1]
	TreeNode *root1 = new TreeNode(4);
	root1->left = new TreeNode(9);
	root1->right = new TreeNode(0);
	root1->left->left = new TreeNode(5);
	root1->left->right = new TreeNode(1);

	res = oSolution.sumNumbers(root1);
	cout << "The Sum Root to Leaf Numbers is: " << res << endl;

	return 0;
}

/*
Output:
The Sum Root to Leaf Numbers is: 25
The Sum Root to Leaf Numbers is: 1026
*/
