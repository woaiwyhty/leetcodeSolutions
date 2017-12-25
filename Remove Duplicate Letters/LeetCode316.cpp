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
	string removeDuplicateLetters(string s) {
		string res = "";
		int len = s.length(), cnt[30]; bool exist[30];
		for (int i = 0; i < 30; ++i) cnt[i] = 0, exist[i] = 0;
		for (int i = 0; i < len; ++i) {
			int ch = s[i] - 'a';
			cnt[ch]++;
		}
		stack<int> sta;
		for (int i = 0; i < len; ++i) {
			int ch = s[i] - 'a';
			cnt[ch]--;
			if (!exist[ch]) {
				while (!sta.empty() && sta.top() > ch && cnt[sta.top()] > 0) {
					int t = sta.top();
					exist[t] = 0; sta.pop();
				}
				sta.push(ch);
				exist[ch] = 1;
			}
		}
		string tmp = "";
		while (!sta.empty()) tmp += (sta.top() + 'a'), sta.pop();
		for (int i = 0; i < tmp.length(); ++i) {
			int idx = tmp.length() - i - 1;
			res += tmp[idx];
		}
		return res;
	}
}sol;
int main() {
	cout << sol.removeDuplicateLetters(string("cbacdcbc")).c_str();
	return 0;
}
