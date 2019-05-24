#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size(), cnt = 0;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] > 0) ++cnt;
        }
        nums.push_back(-1);
        for (int i = 0; i < sz; ++i) {
            if (nums[i] > 0 && nums[i] <= cnt && nums[i] != i) {
                int st = i;
                while (nums[st] != st && nums[st] <= cnt && nums[st] > 0) {
                    int j = nums[st];
                    int t = nums[j];
                    if (t == nums[st]) break;
                    nums[j] = nums[st];
                    nums[st] = t;
                }
            }
        }
        for (int i = 1;i <= cnt; ++i) {
            if (nums[i] != i) return i;
        }
        return cnt + 1;
    }
}solution;
int main() {
    int src[] = { 1,1,2,3,2,5,6,6,4,4,3 };
    int n = sizeof(src) / sizeof(src[0]);
    vector<int> dest(src, src + n);
//    vector<int> dest;
//    for (int i = 0; i <= 5; ++i) dest.push_back(i), dest.push_back(-i);
    cout << solution.firstMissingPositive(dest);
    return 0;
}