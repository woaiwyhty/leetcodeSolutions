#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.length(), ans = 0, last = 1;
        string ansStr;
        vector < vector<bool> > f(sz);
        if(sz == 1) return s;
        ans = 1, ansStr = s[0];
		for(int i = 0 ; i < sz ; ++i)  {
			vector <bool> tmp(sz, 0);
			f[i] = tmp;
			f[i][i] = 1;
			for(int j = i - 1 ; j >= 0 ; --j) {
				if(s[i] == s[j]) {
					f[i][j] = (i == j + 1) ? 1 : f[i - 1][j + 1];	
				}
				if(f[i][j] && (i - j + 1) > ans) {
					ans = i - j + 1;
					ansStr = s.substr(j, i - j + 1);
				} 
			}
		}
		return ansStr;
		
    }
}sol;
int main() {
	//cout << sol.longestPalindrome(string("cbba"));
	cout << sol.longestPalindrome(string("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"));
	return 0;
}
