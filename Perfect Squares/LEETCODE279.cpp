class Solution {
public:
	int numSquares(int n) {
		vector<int> f(n + 5, 2147483647);
		f[0] = 0;
		int x = sqrt(n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; i - j * j >= 0; ++j) {
				f[i] = min(f[i], f[i - j * j] + 1);
			}
		}
		return f[n];
	}
}sol;
