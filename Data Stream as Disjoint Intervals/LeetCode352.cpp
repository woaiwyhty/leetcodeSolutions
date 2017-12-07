#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <stack> 
#include <queue>
#include <iostream>
using namespace std;
/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
bool com(const Interval a, const Interval b)
{
	if (a.start == b.start) return a.end > b.end;
	return a.start < b.start;
}
class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {
		total = 0;
	}

	void addNum(int val) {
		if (ref.find(val) != ref.end()) return;
		int x = -1, y = -1;
		if (ref.find(val - 1) != ref.end()) x = ref[val - 1];
		if (ref.find(val + 1) != ref.end()) y = ref[val + 1];
		if (x == -1 && y == -1) {
			Interval temp(val, val);
			merge.push_back(temp);
			ref[val] = total++;
		}
		else if (x == -1) {
			merge[y].start = val;
			ref[val] = y;
		}
		else if (y == -1) {
			merge[x].end = val;
			ref[val] = x;
		}
		else {
			merge[x].end = merge[y].end;
			merge[y].start = merge[x].start;
			ref[val] = x;
		}
	}

	vector<Interval> getIntervals() {
		int sz = merge.size();
		vector<Interval> ans, m1;
		m1 = merge;
		sort(m1.begin(), m1.end(), com);
		int nowl = -1, nowr = -1;
		for (int i = 0; i < sz; ++i) {
			if(i && m1[i].start == m1[i - 1].start) continue;
			if (nowl == -1) nowl = m1[i].start, nowr = m1[i].end;
			else if (m1[i].start > nowr + 1) {
				ans.push_back(Interval(nowl, nowr));
				nowl = m1[i].start, nowr = m1[i].end;
			}
			else {
				nowl = min(nowl, m1[i].start);
				nowr = max(nowr, m1[i].end);
			}
		}
		if(nowl != -1) ans.push_back(Interval(nowl, nowr));
		return ans;
	}

private:
	map<int, int> ref;
	vector<Interval> merge;
	int total;
}sol;

int main() {
	int arr[] = { 6,6,0,4,8,7,6,4,7,5 }, n = 6;
	for (int i = 0; i < n; ++i) {
		sol.addNum(arr[i]);
		vector<Interval> fk = sol.getIntervals();
		int sz = fk.size();
		for (int j = 0; j < sz; ++j) {
			cout << "[" << fk[j].start << "," << fk[j].end << "], ";
		}
		cout << endl;
	}

	return 0;
}
