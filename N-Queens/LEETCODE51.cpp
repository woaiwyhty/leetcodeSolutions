class Solution {
public:
	vector<vector<string> > ans;
	void dfs(int arr[], int now, int n, int rowVal, int colVal, int tiltVal, int tiltVal1) {
		if (now == n) {
			vector<string> res;
			for (int i = 0; i < n; ++i) {
				string str = ".....................................";
				str[arr[i]] = 'Q';
				res.push_back(str.substr(0, n));
			}
			ans.push_back(res);
			return;
		}

		for (int i = 0; i < n; ++i) {
			if (rowVal >> now & 1) continue;
			if (colVal >> i & 1) continue;
			int tiltNum = -1, tiltNum1 = -1;
			tiltNum = now + i;
			tiltNum1 = now + (n - 1 - i);
			if (tiltVal >> tiltNum & 1) continue;
			if (tiltVal1 >> tiltNum1 & 1) continue;
			arr[now] = i;
			dfs(arr, now + 1, n, rowVal | (1 << now), colVal | (1 << i), tiltVal | (1 << tiltNum), tiltVal1 | (1 << tiltNum1));
			arr[now] = -1;
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		int arr[55];
		for (int i = 0; i < 55; ++i) arr[i] = -1;
		dfs(arr, 0, n, 0, 0, 0, 0);
		return ans;
	}
}sol; 