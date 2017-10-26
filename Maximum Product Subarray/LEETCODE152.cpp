class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		vector<int> dpMax(n), dpMin(n);
		if (!n) return 0;
		dpMax[0] = nums[0], dpMin[0] = nums[0];
		int ans = dpMax[0];
		for (int i = 1; i < n; ++i) {
			int tMax = dpMax[i - 1] * nums[i], tMin = dpMin[i - 1] * nums[i];
			dpMax[i] = max(max(tMax, tMin), nums[i]);
			dpMin[i] = min(min(tMin, tMax), nums[i]);
			ans = max(ans, dpMax[i]);
		}
		
		return ans;
	}
}sol;