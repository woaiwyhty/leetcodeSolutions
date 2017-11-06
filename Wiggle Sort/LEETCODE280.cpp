class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int sz = nums.size();
		vector<int> a(sz);
		for (int i = 0; i < sz; ++i)
			a[i] = nums[i];
		sort(a.begin(), a.end());
		int l = 0, r = sz - 1;
		for (int i = 0; i < sz; ++i) {
			if (l > r) break;
			if ((i & 1) == 0) nums[i] = a[l++];
			else nums[i] = a[r--];
		}
	}
}sol;