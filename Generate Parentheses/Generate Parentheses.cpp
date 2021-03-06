// Generate Parentheses.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	int total;
	vector<string> ans;
	void dfs(string now, int leftOpen, int leftClose) {
		if (!leftOpen && !leftClose) {
			ans.push_back(now);
			return;
		}

		int usedOpen = total - leftOpen, usedClose = total - leftClose;
		if (usedClose > usedOpen) return;
		if (leftOpen) {
			dfs(now + '(', leftOpen - 1, leftClose);
		}
		if (leftClose) {
			dfs(now + ')', leftOpen, leftClose - 1);
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		total = n;
		string emptyStr = "";
		dfs(emptyStr, n, n);
		return ans;
	}
}sol;

int main()
{
	vector<string> ans = sol.generateParenthesis(3);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].c_str() << endl;
	}
    return 0;
}

