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
	int maxCoins(vector<int>& nums) {
		int sz = nums.size();
		if (sz == 0) return 0;
		nums.push_back(0), nums.push_back(0);
		for (int i = sz - 1; i >= 0; --i) nums[i + 1] = nums[i];
		nums[0] = 1, nums[sz + 1] = 1;
		vector<vector<int>> f(sz + 2);
		for (int i = sz; i >= 1; --i) {
			vector<int> tmp(sz + 2, 0);
			f[i] = tmp;
			f[i][i] = nums[i] * nums[i - 1] * nums[i + 1]; //f[i][i]
			for (int j = i  + 1; j <= sz; ++j) {
				f[i][j] = max(f[i + 1][j] + nums[i] * nums[i - 1] * nums[j + 1], f[i][j - 1] + nums[j] * nums[i - 1] * nums[j + 1]);
				for (int k = i + 1; k <= j - 1; ++k) {
					f[i][j] = max(f[i][j], f[i][k - 1] + f[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);
				}
			}
		}
		return f[1][sz];
	}
}sol;
int main() {
	int arr[] = { 3, 1, 5, 8 }, n = 1;
	vector<int> fk(n);
	for (int i = 0; i < n ; ++i) fk[i] = arr[i];
	cout << sol.maxCoins(fk) << endl;
	return 0;
}
