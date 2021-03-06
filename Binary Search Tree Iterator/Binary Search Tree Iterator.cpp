// Binary Search Tree Iterator.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
	stack<TreeNode*> minStack;
public:
	BSTIterator(TreeNode *root) {
		TreeNode *tmp = root;
		while (tmp) {
			minStack.push(tmp);
			tmp = tmp->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !minStack.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *tmp = minStack.top();
		minStack.pop();
		int minValue = tmp->val;
		tmp = tmp->right;
		if (tmp) {
			while (tmp) {
				minStack.push(tmp);
				tmp = tmp->left;
			}
		}
		return minValue;
	}
};
/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/
int main()
{
	TreeNode *root = new TreeNode(1);
	BSTIterator i = BSTIterator(root);
	cout << i.next();
    return 0;
}

