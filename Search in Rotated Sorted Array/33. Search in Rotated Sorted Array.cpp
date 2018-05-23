class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1, m = l + r >> 1;
		while (l <= r) {
			m = l + r >> 1;
			if (target == nums[m]) return m;
			if (target == nums[l]) return l;
			if (target == nums[r]) return r;
			if (nums[m] < nums[l]) {
				if (target > nums[m] && target < nums[r]) l = m + 1;
				else r = m - 1;
			}
			else {
				if (target > nums[l] && target < nums[m]) r = m - 1;
				else l = m + 1;
			}
		}
		return -1;
	}
}sol;