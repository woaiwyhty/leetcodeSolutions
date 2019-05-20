#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int l = 0, r = 0, ans = 0;
        bool isRepeat = false;
        char repeatWord;
        vector<bool> exist(256, false);
        while (l <= r && r < len) {
            if (!isRepeat) {
                if (exist[s[r]]) {
                    ans = max(ans, r - l);
                    isRepeat = true;
                    repeatWord = s[r];
                } else
                    exist[s[r]] = true, ++r;
            } else {
                if (s[l] == repeatWord) {
                    ++l; ++r;
                    isRepeat = false;
                } else {
                    exist[s[l]] = false; ++l;
                }
            }
        }
        if (!isRepeat) ans = max(ans, r - l);
        return ans;
    }
}solution;
int main() {
    cout << solution.lengthOfLongestSubstring("pwwkew");
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}