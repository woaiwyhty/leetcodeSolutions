class Solution {
public:
	/*
	* @param s: A string
	* @param dict: A dictionary of words dict
	* @return: A boolean
	*/
	bool wordBreak(string &s, unordered_set<string> &dict) {
		// write your code here
		int len = s.length(), maxSize = 0;
		vector<bool> f(len + 5, 0);
		for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
			string str = *it; int len = str.length();
			maxSize = max(maxSize, len);
		}
		if (len == 0) return true;
		for (int i = 0; i < len; ++i) {
			for (int j = i - 1; j >=0 && (i - j) <= maxSize; --j) {
				if (f[j] && dict.find(s.substr(j + 1, i - j)) != dict.end()) {
					f[i] = 1;
					break;
				}
			}
			if (dict.find(s.substr(0, i + 1)) != dict.end()) f[i] = 1;
		}
		return f[len - 1];
	}
}sol;