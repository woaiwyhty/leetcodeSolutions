#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> f(len1 + 5, vector<int>(len2 + 5, 2147483647));
        word1 = " " + word1, word2 = " " + word2;
        f[0][0] = 0;
        for (int i = 1; i <= len1; ++i) f[i][0] = i;
        for (int i = 1; i <= len2; ++i) f[0][i] = i;
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len1; ++j) {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + (word1[i] == word2[j] ? 0 : 1));
                f[i][j] = min(f[i][j], min(f[i - 1][j], f[i][j - 1]) + 1);
                cout << i << "  " << j << "  " << f[i][j] << endl;
            }
        }
        return f[len1][len2];
    }
}solution;

int main() {
    cout << solution.minDistance("horse", "ros");
    return 0;
}