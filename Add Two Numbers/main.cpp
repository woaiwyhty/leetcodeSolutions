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
    ListNode* addHelper(ListNode *curA, ListNode *curB, int addOn) {
        int x = addOn, newAddOn = 0;
        ListNode *aNext = nullptr, *bNext = nullptr;
        if (!curA && !curB) {
            if (addOn) return new ListNode(addOn);
            return nullptr;
        }
        if (curA) x += curA->val, aNext = curA->next;
        if (curB) x += curB->val, bNext = curB->next;
        if (x >= 10) x -= 10, newAddOn = 1;
        ListNode *now = new ListNode(x);
        now->next = addHelper(aNext, bNext, newAddOn);
        return now;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addHelper(l1, l2, 0);
    }
}sol;
int main() {
    return 0;
}