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


class Solution {
public:
	int kEmptySlots(vector<int>& flowers, int k) {
		n = flowers.size();
		vector<int> t(n + 10, 0);
		tree = t;
		vector<bool> exist(20005, 0);
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			add(flowers[i], 1);
			exist[flowers[i]] = 1;
			if (flowers[i] + k + 1 <= n && exist[flowers[i] + k + 1]) {
				if (getsum(flowers[i] + k) - getsum(flowers[i]) == 0) {
					ans = i + 1;
					break;
				}
			}
			if (flowers[i] - k - 1 >= 1 && exist[flowers[i] - k - 1]) {
				if (getsum(flowers[i] - 1) - getsum(flowers[i] - k - 1) == 0) {
					ans = i + 1;
					break;
				}
			}
		}
		return ans;
	}
private:
	int n;
	vector<int> tree;
	int lowbit(int t)
	{
		return t&(-t);
	}
	void add(int x, int y)
	{
		for (int i = x; i <= n; i += lowbit(i))
			tree[i] += y;
	}
	int getsum(int x)
	{
		int ans = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ans += tree[i];
		return ans;
	}
}sol;
int main() {
	int arr[] = { 1, 3, 2 }, n = 3;
	vector<int> fk(n);
	for (int i = 0; i < n ; ++i) fk[i] = arr[i];
	cout << sol.kEmptySlots(fk, 1) << endl;
	return 0;
}
