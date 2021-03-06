class Solution {
private:
	bool isSame(string s, int st, int ed) {
		for (int i = st; i < ed; ++i) {
			if (s[i] != s[i + 1]) return false;
		}
		return true;
	}
public:
	bool isMatch(string s, string p) {
		int n = s.length(), m = p.length();
		vector<bool> canPass(m + 1);
		for (int i = 0; i < m; i += 2) {
			if (i + 1 < m) {
				if (p[i + 1] == '*') canPass[i] = canPass[i + 1] = 1;
				else break;
			}
			else canPass[i] = (p[i] == '*');
		}
		if (!m && !n) return true;
		if (!n) return canPass[m - 1];
		vector<vector<int> > f(n + 1);
		for(int i = 0 ; i < n ; ++i) {
			vector<int> tmp(m + 1);
			f[i] = tmp;
			for (int j = 0; j < m; ++j) {
				if (p[j] == '*') {
					if (j) {
						char c = p[j - 1];
						if(j >= 2) f[i][j] |= f[i][j - 2];
						//if (i && j >= 2 && s[i] == p[j - 1]) f[i][j] |= f[i - 1][j - 2];
						for (int k = i; k >= 0; --k) {
							if (c == '.') {
								if (j > 2) {
									if (k) f[i][j] |= f[k - 1][j - 2];
									//else f[i][j] = 1;
									if (canPass[j - 2] && !k) f[i][j] = 1;
								}
								else {
									if(k) f[i][j] |= f[k - 1][0];
									else if(j <= 1) f[i][j] = 1;
								}
								if (f[i][j]) break;
							} else if (isSame(s, k, i)) {
								if (s[i] == p[j - 1]) {
									if (j > 2) {
										if(k) f[i][j] |= f[k - 1][j - 2];
										//else f[i][j] = 1;
										if (canPass[j - 2] && !k) f[i][j] = 1;
									}
									else {
										if (k) f[i][j] |= f[k - 1][0];
										else if(j <= 1) f[i][j] = 1;
									}
									if (f[i][j]) break;
								}
							}
							else break;
						}
					}
				}
				else if (p[j] == '.') {
					if (j && i) {
						f[i][j] |= f[i - 1][j - 1];
					}
					else if (!j && !i) f[i][j] = 1;
					else if (j && canPass[j - 1]) f[i][j] = 1;
				}
				else {
					if (j && i && s[i] == p[j]) f[i][j] |= f[i - 1][j - 1];
					else if (!j && !i && s[i] == p[j]) f[i][j] = 1;
					else if (j && canPass[j - 1] && s[i] == p[j]) f[i][j] = 1;
				}
			}
		}
		return f[n - 1][m - 1];
	}
}sol;