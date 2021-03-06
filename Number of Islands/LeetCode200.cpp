
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		build_graph(grid);
		vector<bool> visited(n * m, 0);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int nodeNum = i * m + j;
				if (visited[nodeNum] || grid[i][j] == '0') continue;
				//cout << i << "  " << j << endl;
				++ans;
				stack<int> s;
				s.push(nodeNum);
				visited[nodeNum] = 1;
				while (!s.empty()) {
					int node = s.top();
					//cout << node << endl;
					s.pop();
					for (int k = 0; k < edges[node].size(); ++k) {
						if (!visited[edges[node][k]]) {
							s.push(edges[node][k]);
							visited[edges[node][k]] = 1;
						}
					}
				}
			}
		}
		return ans;
	}
private:
	vector<vector<int>> edges;
	int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 }, n, m;
	void build_graph(vector<vector<char>>& grid) {
		n = grid.size();
		if (!n) return;
		m = grid[0].size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				vector<int> tmp;
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1') {
						tmp.push_back(nx * m + ny);
					}
				}
				edges.push_back(tmp);
			}
		}
	}
}sol;

int main()
{
	char arr[4][5] = { { '1', '1', '1', '1', '0' },{ '1', '1', '0', '1', '0' },{ '1', '1', '0', '0', '0' },{ '0', '0', '0', '0', '0' } };
	vector<vector<char>> grid;
	for (int i = 0; i < 4; ++i) {
		vector<char> tmp;
		for (int j = 0; j < 5; ++j) {
			tmp.push_back(arr[i][j]);
		}
		grid.push_back(tmp);
	}
	cout << sol.numIslands(grid) << endl;
    return 0;
}

