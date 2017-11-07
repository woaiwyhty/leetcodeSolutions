struct  node {
	int x, y, val;
	node(int xx, int yy, int vval) : x(xx), y(yy), val(vval) {}
};
class Solution {
public:
	int n, m;
	int posx[4] = { -1, 0, 1, 0 }, posy[4] = { 0, 1, 0, -1 };
	void update(int x, int y, vector<vector<int> >& ans, vector<vector<int> >rooms) {
		queue<node> q;
		q.push(node(x, y, 0));
		/*vector<vector<bool>> flag;
		for (int i = 0; i < n; ++i) {
			vector<bool> tmp(m, 0);
			flag.push_back(tmp);
		}*/
		while (!q.empty()) {
			node p = q.front();
			q.pop();
			ans[p.x][p.y] = min(ans[p.x][p.y], p.val);
			for (int i = 0; i < 4; ++i) {
				int nx = p.x + posx[i], ny = p.y + posy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m 
					&& rooms[nx][ny] != -1 && rooms[nx][ny] == 2147483647 && p.val + 1 < ans[nx][ny]) {
					q.push(node(nx, ny, p.val + 1));
				}
			}
		}
	}
	void wallsAndGates(vector<vector<int>>& rooms) {
		int inf = 2147483647;
		n = rooms.size();
		if (n > 0) m = rooms[0].size();

		vector<vector<int> >ans;
		for (int i = 0; i < n; ++i) {
			vector<int> tmp(m, 2147483647);
			ans.push_back(tmp);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (rooms[i][j] < inf && rooms[i][j] != -1) {
					update(i, j, ans, rooms);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (rooms[i][j] != -1) 
					rooms[i][j] = ans[i][j];
			//	printf("%d ", rooms[i][j]);
			}
			//printf("\r\n");
		}
	}
}sol;
