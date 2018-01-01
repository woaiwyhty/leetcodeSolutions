class Solution {
public:
	/*
	* @param heights: a vector of integers
	* @return: an integer
	*/
	int maxArea(vector<int> &heights) {
		// write your code here
		int sz = heights.size(), ans = 0;
		int l = 0, r = sz - 1;
		while (l < r) {
			ans = max(ans, (r - l) * min(heights[l], heights[r]));
			if (heights[l] > heights[r]) r--;
			else l++;
		}
		return ans;
	}
}sol;
