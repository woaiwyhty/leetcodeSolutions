#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
bool cmp(const Interval &x, const Interval &y) {
	if(x.start != y.start)
		return x.start < y.start;
	return x.end > y.end;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int sz = intervals.size();
		
		vector <Interval> res;
		Interval last; int nowL = -1, nowR = -1;
		for(int i = 0 ; i < sz ; ++i) {
			if(i && intervals[i].start == intervals[i - 1].start) continue;
			Interval s = intervals[i];
			if((i && s.start > nowR) || !i) {
				if(i) res.push_back(Interval(nowL, nowR));
				nowL = s.start, nowR = s.end, last = s;
				continue;
			}
			nowR = max(nowR, s.end);
		}
		if(nowL != -1 && nowR != -1) res.push_back(Interval(nowL, nowR));
		return res;
    }
}sol;
int main() {
	int arr[][2] = {
		{ 1, 3 },
		{ 2, 7 },
		{ 2, 6 },
		{ 8, 10 },
		{ 15, 18 }
	};
	vector <Interval> fk;
	int n = 5;
	for(int i = 0 ; i < n ; ++i) {
		fk.push_back(Interval(arr[i][0], arr[i][1]));
	}
	vector<Interval> res = sol.merge(fk);
	n = res.size();
	for(int i = 0 ; i < n ; ++i)
		printf("%d %d\n", res[i].start, res[i].end);
	return 0;
}
