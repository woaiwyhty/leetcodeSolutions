#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <stack> 
#include <queue>
#include <iostream>
using namespace std;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* merge(ListNode *l1, ListNode *l2) {
		ListNode* curr1 = l1; ListNode* curr2 = l2;
		ListNode* head = new ListNode(-1), *now = head;
		while (curr1 != NULL && curr2 != NULL) {
			if (curr1->val < curr2->val) {
				now->next = curr1;
				curr1 = curr1->next;
			}
			else {
				now->next = curr2;
				curr2 = curr2->next;
			}
			now = now->next;
		}
		if (curr2 != NULL) curr1 = curr2;
		while (curr1 != NULL) {
			now->next = curr1;
			curr1 = curr1->next;
			now = now->next;
		}
		return head->next;
	}
	ListNode* mergeHelper(vector<ListNode*> lists) {
		int sz = lists.size(), k = sz / 2 + (sz % 2), cnt = 0;
		if (sz == 1) return lists[0];
		if (sz == 0) return NULL;
		vector<ListNode*> tmp(k, NULL);
		for (int i = 0; i < sz - 1; i += 2) {
			tmp[cnt++] = merge(lists[i], lists[i + 1]);
		}
		if (sz % 2) tmp[cnt++] = lists[sz - 1];
		return mergeHelper(tmp);
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return mergeHelper(lists);
	}
}sol;
int main() {
	vector<ListNode*> l(3, NULL);
	//for (int i = 0; i < 2; ++i) {
	//	l[i] = new ListNode(1);
	//	ListNode *head = l[i];
	//	for (int j = 2; j <= 5; ++j) {
	//		head->next = new ListNode(j);
	//		head = head->next;
	//	}
	//}
	l[0] = new ListNode(2);
	l[2] = new ListNode(-1);

	ListNode *res = sol.mergeKLists(l);
	while (res != NULL) {
		cout << res->val << endl;
		res = res->next;
	}
	//cout << sol.minDistance(string("e"), string("abe"));
	return 0;
}
