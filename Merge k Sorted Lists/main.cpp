#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* mergeTwo(ListNode *a, ListNode *b) {
        ListNode *curA = a, *curB = b;
        ListNode *start = nullptr, *last = nullptr;
        while(curA || curB) {
            int valA = 2147483647, valB = 2147483647;
            if (curA) valA = curA->val;
            if (curB) valB = curB->val;
            ListNode *now = nullptr;
            if (valA < valB)
                now = curA, curA = curA->next;
            else
                now = curB, curB = curB->next;
            if (!start) start = now, last = now;
            else last->next = now, last = now;
        }
        return start;
    }
    ListNode* divideAndConquer(vector<ListNode*> tmpList) {
        int sz = tmpList.size();
        if (sz == 0) return nullptr;
        if (sz == 1) return tmpList[0];
        vector<ListNode*> newList;
        ListNode *tmp = nullptr;
        for (int i = 0; i < sz; i += 2) {
            if (i == sz - 1)
                tmp = mergeTwo(tmpList[i], nullptr);
            else
                tmp = mergeTwo(tmpList[i], tmpList[i + 1]);

            newList.push_back(tmp);
        }
        return divideAndConquer(newList);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return divideAndConquer(lists);
    }
}solution;

ListNode* makeListByArr(int arr[], int n) {
    ListNode *last = nullptr, *start = nullptr;
    for (int i = 0 ; i < n - 1 ; ++i) {
        ListNode *now = new ListNode(arr[i]);
        if (!start) start = now, last = now;
        else last->next = now;
    }
    return start;
}
int main() {

    return 0;
}