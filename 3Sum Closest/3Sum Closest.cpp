// 3Sum Closest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size(), l = 0, r = n - 1, ans = 2147483647, sumAns = 0;
		sort(nums.begin(), nums.end());
		for (int i = 1; i < n - 1; ++i) {
			int l = 0, r = n - 1, diff;
			while (l < i && r > i) {
				cout << l << "  " << i << "  " << r << endl;
				diff = (nums[l] + nums[r] + nums[i] - target);
				if (ans > abs(diff)) ans = abs(diff), sumAns = nums[l] + nums[r] + nums[i];
				if (!diff) return  nums[l] + nums[r] + nums[i];
				else if (diff > 0) r--;
				else l++;
			}
		}
		return sumAns;
	}
}sol;

int main()
{
	int arr[] = { -55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33 };
	vector<int> nums;
	for (int i = 0; i < 13; ++i) nums.push_back(arr[i]);
	for (int i = 0; i < 13; ++i) {
		for (int j = i + 1; j < 13; ++j) {
			for (int k = j + 1; k < 13; ++k)
				if (arr[i] + arr[j] + arr[k] == 0) {
					cout << arr[i] << "   " << arr[j] << "   " << arr[k] << endl;

				}
		}
	}
	cout << sol.threeSumClosest(nums, 0);
    return 0;
}

