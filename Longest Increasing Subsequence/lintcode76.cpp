class Solution {
public:
    /*
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
     int myStack[10005], sz;
int binarySearch(int x, int l, int r) {
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (myStack[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}
int findLIS(vector < int > s) {
	int n = s.size();
	myStack[++sz] = s[0];
	for (int i = 1; i < n; ++i) {
		if (s[i] > myStack[sz]) {
			myStack[++sz] = s[i];
		}
		else {
			int pos = binarySearch(s[i], 1, sz);
			myStack[pos] = s[i];
		}
	}
	return sz;
}

    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        if(nums.size() == 0) return 0;
        return findLIS(nums);
    }
};