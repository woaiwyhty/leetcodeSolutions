class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *st = head, *ans = NULL, *last = NULL;
		while (st != NULL) {
			ListNode *next = st->next;
			if (next == NULL) {
				ans = st;
			}
			st->next = last;
			last = st;
			st = next;
		}
		
		return ans;
	}
}sol;
