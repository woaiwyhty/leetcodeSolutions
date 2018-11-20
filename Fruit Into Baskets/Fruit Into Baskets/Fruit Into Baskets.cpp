// Fruit Into Baskets.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int l = 0, r = 0, cnt = 0, ans = 0;
		int n = tree.size();
		vector<int> selected(2, -1);
		vector<int> times(n, 0);
		while (l < n && r < n) {
			//cout << l << "  " << r << "  " << times[2] << endl;
			if (!cnt) {
				selected[0] = tree[r];
				++cnt;
				++times[tree[r]];
				ans = max(ans, r - l + 1);
				++r;
			} else if (cnt == 1) {
				++times[tree[r]];
				if (selected[0] != tree[r]) {
					selected[1] = tree[r];
					++cnt;
				}
				ans = max(ans, r - l + 1);
				++r;
			} else if (cnt == 2) {
				++times[tree[r]];
				if (selected[0] != tree[r] && selected[1] != tree[r]) {
					while (l < r) {
						--times[tree[l]];
						if (!times[tree[l]]) {
							if (selected[0] == tree[l]) {
								selected[0] = selected[1];
								selected[1] = tree[r];
							}
							else if (selected[1] == tree[l]) {
								selected[1] = tree[r];
							}
							++l;
							ans = max(ans, r - l + 1);
							break;
						}
						++l;
					}
					++r;
				} else {
					ans = max(ans, r - l + 1);
					++r;
				}
			}
		}
		return ans;
	}
}sol;

int main()
{
	vector<int> sb = { 0,1,2 };
	cout << sol.totalFruit(sb);
    return 0;
}

