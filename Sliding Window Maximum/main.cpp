#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size(), curMax = -2147483647;
        vector<int> ans;
        deque<int> s;
        for (int i = 0; i < k; ++i) {
            while(!s.empty() && nums[i] > s.back()) {
                s.pop_back();
            }
            s.push_back(nums[i]);
        }
        if (!s.empty()) ans.push_back(s.front());
        for (int i = 1; i + k - 1 < sz; ++i) {
            if (!s.empty() && nums[i - 1] == s.front()) {
                s.pop_front();
            }
            while(!s.empty() && nums[i + k - 1] > s.back()) {
                s.pop_back();
            }
            s.push_back(nums[i + k - 1]);
            ans.push_back(s.front());
        }
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        return ans;
    }
}solution;


int main() {
    int src[] = { 100,59,-48,43,35,-49,48,-36,-64,-13,-7,-29,87 };
    int n = sizeof(src) / sizeof(src[0]);
    vector<int> dest(src, src + n);
    solution.maxSlidingWindow(dest, 10);
    return 0;
}