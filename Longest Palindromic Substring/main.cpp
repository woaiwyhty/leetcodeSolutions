#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int ans = 0, sl = -1, sr = -1;
        for (int i = 0; i < len; ++i) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && l < len && r >= 0 && r < len && s[l] == s[r]) {
                --l;
                ++r;
            }
            ++l, --r;
            if (r - l + 1 > ans) {
                ans = r - l + 1;
                sl = l, sr = r;
            }
            l = i, r = i + 1;
            while (l >= 0 && l < len && r >= 0 && r < len && s[l] == s[r]) {
                --l;
                ++r;
            }
            ++l, --r;
            if (r - l + 1 > ans) {
                ans = r - l + 1;
                sl = l, sr = r;
            }
        }
        if (ans == 0) return "";
        return s.substr(sl, sr - sl + 1);
    }
}solution;
int main() {
    solution.longestPalindrome("babad");
    return 0;
}