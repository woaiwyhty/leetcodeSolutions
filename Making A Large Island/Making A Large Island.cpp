
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
	int x, y;
	node(int a, int b) : x(a), y(b) {
	}
};
class Solution {
public:
	int n, m;
	int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
	int findMax(int changeX, int changeY, vector<vector<int>>& grid) {
		int ans = 0;
		queue <node> q;
		q.push(node(changeX, changeY));
		vector<vector<bool>> visited(n);
		for (int i = 0; i < n; ++i) {
			vector<bool> tmp(m, 0);
			visited[i] = tmp;
		}
		visited[changeX][changeY] = 1;
		while (!q.empty()) {
			node tmp = q.front();
			q.pop(); ++ans;
			for (int i = 0; i < 4; ++i) {
				int nx = tmp.x + dx[i], ny = tmp.y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && grid[nx][ny] == 1) {
					q.push(node(nx, ny));
					visited[nx][ny] = 1;
				}
			}
		}
		return ans;
	}
	int largestIsland(vector<vector<int>>& grid) {
		n = grid.size(), m = grid[0].size();
		int res = 0; bool isChanged = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j]) continue;
				grid[i][j] = 1;
				isChanged = true;
				res = max(res, findMax(i, j, grid));
				grid[i][j] = 0;
			}
		}
		if (!isChanged) {
			// all numbers are 1
			res = n * m;
		}
		return res;
	}
}sol;

int main()
{
	int arr[4][5] = { { 1, 1, 1, 1, 0 },{ 1, 1, 0, 1, 0 },{ 1, 1, 0, 0, 0 },{ 0, 0, 0, 0, 0 } };
	vector<vector<int>> grid;
	for (int i = 0; i < 4; ++i) {
		vector<int> tmp;
		for (int j = 0; j < 5; ++j) {
			tmp.push_back(arr[i][j]);
		}
		grid.push_back(tmp);
	}
	cout << sol.largestIsland(grid) << endl;
    return 0;
}

