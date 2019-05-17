#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> exists(256, 0);
        vector<int> tmap(256, 0);
        vector<bool> leile(256, false);
        int lens = s.length(), lent = t.length(), sumt = lent;
        for (int i = 0; i < lent; ++i) ++tmap[t[i]], leile[t[i]] = true;

        int l = 0, r = 0;
        int ans = 2147483647, sl = -1, sr = -1;
        bool isCovered = false;
        while (l <= r && r < lens) {
            if (!isCovered) {
                exists[s[r]]++;
                if (leile[s[r]]) {
                    --tmap[s[r]];
                    //cout << s[r] << "  " << tmap[s[r]] << endl;
                    if (tmap[s[r]] >= 0) {
                        --sumt;
                        if (!sumt) {
                            // covered
                            isCovered = true;
                            if (r - l + 1 < ans) {
                                ans = r - l + 1;
                                sl = l, sr = r;
                            }
                            continue;
                        }
                    }
                }
                ++r;
            } else {
                exists[s[l]]--;
                if (leile[s[l]]) {
                    ++tmap[s[l]];
                    // cout << s[l] << "  " << tmap[s[l]] << endl;
                    if (tmap[s[l]] > 0) {
                        ++sumt;
                        isCovered = false;
                        if (r - l + 1 < ans) {
                            ans = r - l + 1;
                            sl = l, sr = r;
                        }
                        ++r;
                    }
                }
                ++l;
            }
        }
        if (ans == 2147483647) return "";
        return s.substr(sl, sr - sl + 1);
    }
}solution;
int main() {
    cout << solution.minWindow("ADOBECODEBANC", "AAAAAAAAAA");
    return 0;
}