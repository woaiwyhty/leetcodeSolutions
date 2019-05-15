#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
private:
    int n, m;
    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
    void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<char>>& grid) {
        visited[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && grid[nx][ny] == '1') {
                    dfs(nx, ny, visited, grid);
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (!n) return 0;
        m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j] || grid[i][j] == '0') continue;
                ++ans;
                dfs(i, j, visited, grid);
            }
        }
        return ans;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}