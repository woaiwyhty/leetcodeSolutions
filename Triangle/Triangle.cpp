
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector <int> f(n + 2), g(n + 2);
		if (!n) return 0;
		for (int i = 0; i < n; ++i) {
			int m = triangle[i].size();
			for (int j = 0; j <= m; ++j) f[j] = 123456789;
			for (int j = 0; j < m; ++j) {
				if(!j) f[j] = min(f[j], g[j] + triangle[i][j]);
				else {
					f[j] = min(f[j], g[j - 1] + triangle[i][j]);
					if (j != m - 1) f[j] = min(f[j], g[j] + triangle[i][j]);
				}
			}
			g = f;
		}
		int ans = 123456789;
		for (int i = 0; i < n; ++i) ans = min(ans, g[i]);
		return ans;
	}
}sol;

int main()
{
	int arr[][4] = { {2},{3, 4},{6, 5, 7},{4, 1, 8, 3} };
	vector<vector<int>> triangle(4);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j <= i; ++j) triangle[i].push_back(arr[i][j]);
	}
	cout << sol.minimumTotal(triangle) << endl;
    return 0;
}

