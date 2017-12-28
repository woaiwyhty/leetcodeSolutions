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
	int calculate(string str) {
		stack<int> s;
		int len = str.length(), curr = 0;
		for (int i = 0; i < len; ++i) {
			char ch = str[i];
			if (ch == '(') { //12345
				if (curr) s.push(curr);
				curr = 0;
				s.push(12345);
			}
			else if (ch == ')') { //54321
				int tmp = 0, lastval = 0;
				if (curr) s.push(curr);
				curr = 0;
				while (!s.empty() && s.top() != 12345) {
					int t = s.top();
					if (t == 11111 || t == 22222) {
						if (t == 22222) lastval *= -1;
						tmp += lastval;
						lastval = 0;
					}
					else {
						lastval = t;
					}
					s.pop();
				}
				if (lastval) tmp += lastval;
				//cout << tmp << endl;
				s.pop();
				s.push(tmp);
			}
			else if (ch == ' ') {
				if (curr) s.push(curr);
				curr = 0;
			}
			else if (ch == '+' || ch == '-') {
				if (curr) s.push(curr);
				if (ch == '+') s.push(11111);
				else s.push(22222);
				curr = 0;
			}
			else if(ch >= '0' && ch <= '9') {
				curr = curr * 10 + ch - '0';
				if (i == len - 1) s.push(curr);
			}
		}
		int tmp = 0, lastval = 0;
		while (!s.empty()) {
			int t = s.top();
			if (t == 11111 || t == 22222) {
				if (t == 22222) lastval *= -1;
				tmp += lastval;
				lastval = 0;
			}
			else {
				lastval = t;
			}
			s.pop();
		}
		if (lastval) tmp += lastval;
		return tmp;
	}
}sol;
int main() {
	cout << sol.calculate(string("1-(2+3-(4+(5-(1-(2+4-(5+6))))))"));
	return 0;
}
