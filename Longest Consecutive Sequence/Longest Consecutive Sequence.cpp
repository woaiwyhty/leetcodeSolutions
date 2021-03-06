// Longest Consecutive Sequence.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<int> f;
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set <int> m_set;
		int n = nums.size(), ans = 0, cnt;
		for (int i = 0; i < n; ++i) {
			m_set.insert(nums[i]);
		}
		for (int i = 0; i < n; ++i) {
			cnt = 0;
			if (m_set.find(nums[i]) != m_set.end()) {
				int cur = nums[i];
				while (m_set.find(cur) != m_set.end()) {
					m_set.erase(cur);
					++cur;
					++cnt;
				}
				cur = nums[i] - 1;
				while (m_set.find(cur) != m_set.end()) {
					m_set.erase(cur);
					--cur;
					++cnt;
				}
				ans = max(ans, cnt);
			}
		}
		return ans;
	}
}sol;

int main()
{
	int arr[] = { 100, 2, 3, 4, 123,54235, 1, 0, 5 };
	vector<int> s;
	for (int i = 0; i < 9; ++i) s.push_back(arr[i]);
	cout << sol.longestConsecutive(s) << endl;

    return 0;
}

