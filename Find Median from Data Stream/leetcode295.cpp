#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <functional>
#include <stack> 
#include <queue>
#include <iostream>
using namespace std;
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (leftQueue.empty()) leftQueue.push(num);
		else if (rightQueue.empty()) rightQueue.push(num);
		else {
			if (leftQueue.top() > num) leftQueue.push(num);
			else rightQueue.push(num);
		}
		while (!leftQueue.empty() && !rightQueue.empty() && leftQueue.top() > rightQueue.top()) {
			int t = leftQueue.top(), t1 = rightQueue.top();
			leftQueue.pop(); rightQueue.pop();
			leftQueue.push(t1); rightQueue.push(t);
		}
		int total = leftQueue.size() + rightQueue.size(), k = total / 2, k1 = total - k;
		while (leftQueue.size() > k) rightQueue.push(leftQueue.top()), leftQueue.pop();
		while (rightQueue.size() > k1) leftQueue.push(rightQueue.top()), rightQueue.pop();
	}

	double findMedian() {
		int total = leftQueue.size() + rightQueue.size();
		if (total & 1) return (double)rightQueue.top();
		else return (leftQueue.top() + rightQueue.top()) / 2.0;
	}
private:
	priority_queue<int, vector<int>, less<int> > leftQueue;
	priority_queue<int, vector<int>, greater<int> >rightQueue;
}sol;

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/
int main() {
	sol.addNum(3);
	sol.addNum(6);
	cout << sol.findMedian();
	return 0;
}
