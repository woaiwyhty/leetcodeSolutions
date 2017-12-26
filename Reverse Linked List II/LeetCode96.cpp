class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *st = head, *beforeM = NULL, *last = NULL, *afterN = NULL, *nodeM = NULL, *nodeN = NULL;
		int nowPos = 1;
		while (st != NULL) {
			ListNode *next = st->next;
			if (nowPos == m - 1) beforeM = st;
			if (nowPos == n + 1) {
				afterN = st;
				break;
			}
			if (nowPos == m) nodeM = st;
			if (nowPos == n) nodeN = st;
			if (nowPos > m && nowPos <= n) {
				st->next = last;
			}
			last = st;
			st = next;
			++nowPos;
		}
		nodeM->next = afterN;
		if (beforeM != NULL) {
			beforeM->next = nodeN;
		}
		else {
			return nodeN;
		}
		return head;
	}
}sol;
