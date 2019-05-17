#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int sz = A.size();
        int ans = 1;
        vector<vector<bool>> f(sz, vector<bool>(2, false));
        map<int, int> exist, exist1;
        f[sz - 1][0] = true;
        f[sz - 1][1] = true;
        exist[A[sz - 1]] = sz - 1;
        exist1[-A[sz - 1]] = sz - 1;
        for (int i = sz - 2; i >= 0; --i) {
            int x = A[i];
            map<int, int>::iterator itlow, itup;
            itlow = exist.lower_bound(x);
            itup = exist1.lower_bound(-x);
            if (itlow != exist.end())
                f[i][1] = f[itlow->second][0];
            if (itup != exist1.end())
                f[i][0] = f[itup->second][1];
            exist[A[i]] = i;
            exist1[-A[i]] = i;
            if (f[i][1]) ++ans;
        }
        return ans;
    }
}solution;
int main() {
//    map<int, int> exist;
//    exist[-10]=15;
//    exist[-15] = 20;
//    cout << exist.lower_bound(-12)->first << endl;
    int src[] = { 10,13,12,14,15 };
    int n = sizeof(src) / sizeof(src[0]);
    vector<int> dest(src, src + n);
    cout << solution.oddEvenJumps(dest);
    return 0;
}