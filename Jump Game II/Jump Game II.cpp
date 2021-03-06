
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int sz = nums.size(), ans = 0;
		if (sz == 1 || sz == 0) return 0;
		for (int i = 0; i < sz; i) {
			int maxIdx = -1, maxVal = 0;
			if (i + nums[i] >= sz - 1) {
				++ans;
				break;
			}
			for (int j = i + 1; j <= i + nums[i]; ++j) {
				if (j + nums[j] >= maxVal) maxVal = j + nums[j], maxIdx = j;
			}
			i = maxIdx; ++ans;
		}
		return ans;
	}
}sol;

int main()
{
	int arr[] = { 2, 3, 1, 1, 4 };
	vector<int> iv(begin(arr), end(arr));
	cout << sol.jump(iv) << endl;
    return 0;
}

