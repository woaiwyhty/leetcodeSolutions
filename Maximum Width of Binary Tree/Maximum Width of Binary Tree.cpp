
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		for (int i = 0; i <= 100000; ++i) left[i] = 123456789, right[i] = -123456789;
		getWidthOfLevel(root, 0, 0);
		int res = 1, base = 2;
		for (int i = 1; i <= maxLevel; ++i) {
			int tmp = 0;
			if (left[i] == right[i]) {
				tmp = 1;
			} else if (left[i] <= 0 && right[i] <= 0) {
				// all in left side
				tmp = base / 2 - (base / 2 - abs(left[i])) - (abs(right[i]) - 1);
			}
			else if (left[i] >= 0 && right[i] >= 0) {
				// all in right side
				tmp = base / 2 - (base / 2 - right[i]) - (left[i] - 1);
			}
			else {
				tmp = base - (base / 2 - abs(left[i])) - (base / 2 - right[i]);
			}
			res = max(res, tmp); 
			base *= 2;
		}
		return res;
	}
private:
	int left[100005], right[100005], maxLevel = 0;
	void getWidthOfLevel(TreeNode* root, int level, int pos) {
		if (root == NULL || abs(pos) >= 123456789) {
			return;
		}
		maxLevel = max(maxLevel, level);
		left[level] = min(left[level], pos);
		right[level] = max(right[level], pos);
		if (root->left) {
			if (!level) {
				getWidthOfLevel(root->left, level + 1, pos - 1);
			}
			else {
				if (pos <= 0) {
					// left sub tree
					getWidthOfLevel(root->left, level + 1, pos * 2);
				}
				else {
					getWidthOfLevel(root->left, level + 1, pos * 2 - 1);
				} 
			}
		}
		if (root->right) {
			if (!level) {
				getWidthOfLevel(root->right, level + 1, pos + 1);
			}
			else {
				if (pos <= 0) {
					// left sub tree
					getWidthOfLevel(root->right, level + 1, pos * 2 + 1);
				}
				else {
					getWidthOfLevel(root->right, level + 1, pos * 2);
				}
			}
		}
	};
}sol;

int main()
{
	//TreeNode *root = new TreeNode(0);
	//root->left = new TreeNode(1);
	//root->right = new TreeNode(2);
	//root->left->left = new TreeNode(3);
	//root->right->right = new TreeNode(4);
	//root->left->left->left = new TreeNode(5);
	//root->right->right->right = new TreeNode(6);

	//TreeNode *root = new TreeNode(0);
	//root->left = new TreeNode(1);
	//root->left->left = new TreeNode(3);
	//root->left->right = new TreeNode(4);

	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(2);
	root->right->left = new TreeNode(3);

	cout << sol.widthOfBinaryTree(root);
    return 0;
}

