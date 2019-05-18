#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct point {
    int val, idx;
    point(int x, int y) : idx(x), val(y) { }
};
bool compare(point x, point y) {
    return x.val < y.val;
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int sz = points.size();
        vector<point> lists(sz, point(0, 0));
        for (int i = 0; i < sz; ++i) lists[i] = point(i, points[i][0] * points[i][0] + points[i][1] * points[i][1]);
        sort(lists.begin(), lists.end(), compare);
        vector<vector<int>> ans(K);
        for (int i = 0; i < K; ++i) {
            int id = lists[i].idx;
            ans[i].push_back(points[id][0]);
            ans[i].push_back(points[id][1]);
        }
        return ans;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}