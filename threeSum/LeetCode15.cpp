#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	vector< vector<int> > threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int sz = nums.size();
		int l = 0, m = 1, r = sz - 1;
		vector< vector<int> > ans;
		while (l < sz) {
			m = l + 1, r = sz - 1;
			while (m < r) {


				int sum = nums[l] + nums[r] + nums[m];
				if (sum < 0) {
					++m;
				}
				else if (sum > 0) {
					--r;
				}
				else {
					vector<int> tmp(3);
					tmp[0] = nums[l], tmp[1] = nums[m], tmp[2] = nums[r];
					int ansSz = ans.size();
					bool flag = 1;
					for (int i = 0; i < ansSz; ++i) {
						if (ans[i][0] == tmp[0] && ans[i][1] == tmp[1] && ans[i][2] == tmp[2]) {
							flag = 0;
							break;
						}
					}
					if (flag) ans.push_back(tmp);
					++m; --r;
				}
			}
			++l;
		}
		return ans;
	}
}sol;
int main() {
	int arr[] = { 1, 0, 1, 2, -1, -4 }, n = 6;
	vector<int> fk;
	for(int i = 0 ; i < n ; ++i)
		fk.push_back(arr[i]);
	sol.threeSum(fk);
	return 0;
}
