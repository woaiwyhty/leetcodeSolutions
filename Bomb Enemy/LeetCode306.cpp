class Solution {
public:
	int maxKilledEnemies(vector<vector<char>>& grid) {
		int n = grid.size(), m = 0;
		if (n) m = grid[0].size();
		vector<vector<int> > up(n), left(n), right(n), down(n);
		for (int i = 0; i < n; ++i) {
			vector<int> tmp_up(m), tmp_left(m);
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 'W') {
					tmp_up[j] = tmp_left[j] = 0;
				}
				else if (grid[i][j] == 'E') {
					tmp_up[j] = i >= 1 ? up[i - 1][j] + 1 : 1;
					tmp_left[j] = j >= 1 ? tmp_left[j - 1] + 1 : 1;
				}
				else {
					tmp_up[j] = i >= 1 ? up[i - 1][j] : 0;
					tmp_left[j] = j >= 1 ? tmp_left[j - 1] : 0;
				}
			}
			up[i] = tmp_up;
			left[i] = tmp_left;
		}
		for (int i = n - 1; i >= 0; --i) {
			vector<int> tmp_right(m), tmp_down(m);
			for (int j = m - 1; j >= 0; --j) {
				if (grid[i][j] == 'W') {
					tmp_right[j] = tmp_down[j] = 0;
				}
				else if (grid[i][j] == 'E') {
					tmp_right[j] = j < m - 1 ? tmp_right[j + 1] + 1 : 1;
					tmp_down[j] = i < n - 1 ? down[i + 1][j] + 1 : 1;
				}
				else {
					tmp_right[j] = j < m - 1 ? tmp_right[j + 1] : 0;
					tmp_down[j] = i < n - 1 ? down[i + 1][j] : 0;
				}
			}
			down[i] = tmp_down;
			right[i] = tmp_right;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == '0') {
					ans = max(ans, up[i][j] + down[i][j] + left[i][j] + right[i][j]);;
				}
			}
		}
		return ans;
	}
}sol;