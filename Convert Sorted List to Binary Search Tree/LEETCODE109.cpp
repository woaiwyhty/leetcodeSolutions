class Solution {
public:
	TreeNode *root = NULL;
	vector <ListNode*> arr;
	TreeNode* build(TreeNode *now, int l, int r) {
		int mid = (l + r) >> 1;
		if (l > r) return now;
		now = new TreeNode(arr[mid]->val);
		now->left = build(now->left, l, mid - 1);
		now->right = build(now->right, mid + 1, r);
		return now;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		
		ListNode *st = head;
		while (st != NULL) {
			arr.push_back(st);
			st = st->next;
		}

		int n = arr.size();
		if (n == 0) return NULL;

		root = build(NULL, 0, n - 1);
		return root;
	}
}sol;
