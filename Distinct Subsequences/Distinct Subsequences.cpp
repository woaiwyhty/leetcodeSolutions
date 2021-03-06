
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int lens = s.length(), lent = t.length();
		if (!lens || !lent) return 0;
		vector<vector<int>> f(lens);
		for (int i = 0; i < lens; ++i) {
			vector<int> tmp(lent, 0);
			tmp[0] = i ? f[i - 1][0] : 0;
			if (s[i] == t[0]) {
				tmp[0]++;
			}
			for (int j = 1; j <= i && j < lent; ++j) {
				if (s[i] != t[j]) {
					tmp[j] = f[i - 1][j];
					continue;
				}
				if (i) {
					tmp[j] = f[i - 1][j - 1] + f[i - 1][j];
				}
			}
			f[i] = tmp;
		}
		return f[lens - 1][lent - 1];
	}
}sol;

int main()
{
	string s = "rabbbit", t = "rabbit";
	cout << sol.numDistinct(s, t) << endl;
    return 0;
}

