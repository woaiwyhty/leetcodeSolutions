#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
	vector<string> split(string str, string keyword) {
		int sz = str.length(), stpos = 0, findpos = str.find(keyword, stpos);
		//cout << str << endl;
		vector<string> ans;
		while (findpos >= 0) {
			string sub = str.substr(stpos, findpos - stpos);
			//cout << sub << " " << stpos << " " << findpos << endl;
			stpos = findpos + keyword.length();
			findpos = str.find(keyword, stpos);
			ans.push_back(sub);
		}
		int t = stpos + keyword.length() - 1;
		if (t < sz) {
			//some str left here
			ans.push_back(str.substr(t, sz - t));
		}
		return ans;
	}
	int occurance(string str, string keyword) {
		int sz = str.length(), stpos = 0, findpos = str.find(keyword, stpos), cnt = 0, wordlen = keyword.length();
		while (findpos >= 0) {
			++cnt;
			stpos = findpos + wordlen;
			findpos = str.find(keyword, stpos);
		}
		return cnt;
	}
	int build_graph(vector<string> files) {
		int sz = files.size(), maxLayer = 0, ans = 0;
		string keyword("\t");
		int len = keyword.length();
		vector<int> layer(sz);
		for (int i = 0; i < sz; ++i) {
			int occ = occurance(files[i], keyword);
			int pos = files[i].find('.');
			bool isFile = pos >= 0;
			layer[occ] = occ > 0 ? layer[occ - 1] + files[i].length() - len * occ + 1 : files[i].length();
			if (isFile)
				ans = max(ans, layer[occ]);
		}
		return ans;
	}
	int lengthLongestPath(string input) {
		vector<string> res = split(input, string("\n"));
		return build_graph(res);
	}
}sol;
int main() {
	cout << sol.lengthLongestPath(string("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"));
	return 0;
}
