#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <stack> 
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word1.length() > word2.length()) {
			string t = word2;
			word2 = word1;
			word1 = t;
		}
		int len1 = word1.length(), len2 = word2.length(), maxCnt = 0;
		if (!len1 || !len2) return max(len1, len2);
		vector< vector<int> > f(len1);
		vector< vector<bool> > g(len1);
		const int sb = 214748364;
		for (int i = 0; i < len1; ++i) {
			vector<int> tmp(len2, 0);
			vector<bool> tmp1(len2, 0);
			f[i] = tmp; g[i] = tmp1;
			for (int j = 0; j < len2; ++j) {
				if (word1[i] == word2[j]) {
					f[i][j] = (i && j) ? f[i - 1][j - 1] : abs(i - j);
				}
				else {
					int x = (i && j) ? f[i - 1][j - 1] + 1 : sb;
					int y = (j) ? f[i][j - 1] + 1 : sb;
					int z = (i) ? f[i - 1][j] + 1 : sb;
					f[i][j] = min(x, min(y, z));
					f[i][j] = (!i && !j) ? 1 : f[i][j];
				}
			}

		}
		return f[len1 - 1][len2 - 1];
	}
}sol;
int main() {
	int arr[] = { 6,6,0,4,8,7,6,4,7,5 }, n = 6;

	cout << sol.minDistance(string("aabc"), string("dbcd"));
	return 0;
}
