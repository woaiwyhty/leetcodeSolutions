class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int dx[] = {0, -1, 0, 1, 0 }, dy[] = {0, 0, 1, 0, -1 };
		int n = matrix.size(), m;
		if (n) m = matrix[0].size();
		vector<int> ans;
		int direction = 2;// go right
		int x = 1, y = 1, cnt = 0;
		vector<vector<bool> > visited(n + 3);
		for (int i = 0; i < n + 3; ++i) {
			bool val = i == 0 || i > n ? 1 : 0;
			vector<bool> tmp(m + 3, val);
			tmp[0] = 1, tmp[m + 1] = 1;
			visited[i] = tmp;
		}
		while (cnt < n * m) {
			ans.push_back(matrix[x - 1][y - 1]);
			++cnt;
			visited[x][y] = 1;
			int nx = x + dx[direction], ny = y + dy[direction];
			if (direction == 2 && visited[nx][ny]) {
				// go right
				direction = 3;// go down
			}
			else if (direction == 1 && visited[nx][ny])
			{
				// now go up
				direction = 2;// then go right
			}
			else if (direction == 3 && visited[nx][ny]) {
				// now go down
				direction = 4;// then go left
			}
			else if (direction == 4 && visited[nx][ny]) {
				// now go left
				direction = 1;// then go up
			}
			nx = x + dx[direction], ny = y + dy[direction];
			x = nx, y = ny;
		}
		return ans;
	}
}sol;
