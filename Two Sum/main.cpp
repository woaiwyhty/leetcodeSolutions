#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
private:
    unordered_map<int, int> mHashIdx;
    unordered_map<int, int> mHashTimes;

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        for (int i = 0 ; i < sz ; ++i) {
            mHashIdx[nums[i]] = i;
            if (mHashTimes.find(nums[i]) == mHashTimes.end()) {
                mHashTimes[nums[i]] = 1;
            } else ++mHashTimes[nums[i]];
        }
        for (int i = 0 ; i < sz ; ++i) {
            if (mHashIdx.find(target - nums[i]) != mHashIdx.end()) {
                if (mHashTimes[nums[i]] == 1 && target - nums[i] == nums[i]) continue;
                vector<int> ans(2, 0);
                ans[0] = i, ans[1] = mHashIdx[target - nums[i]];
                return ans;
            }
        }
        return vector<int>();
    }
}sol;
int main() {
    vector<int> a(3);
    a[0] = 3, a[1] = 2, a[2] = 4;
    sol.twoSum(a, 6);
    return 0;
}