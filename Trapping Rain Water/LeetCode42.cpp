#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack> 
#include <iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int sz = height.size(), ans = 0;
        s.push(0);
        for(int i = 1 ; i < sz ; ++i) {
        	int t = s.top(), last;
        	if(height[i] >= height[t]) {
        		last = t; s.pop();
        		while(!s.empty() && height[i] >= height[s.top()]) {
        			t = s.top(); s.pop();
        			ans += (height[t] - height[last]) * (i - t - 1);
        			last = t;
				}
				if(!s.empty()) ans += (height[i] - height[last]) * (i - s.top() - 1);
 			}
 			s.push(i);
		}
		return ans;
    }
}sol;
int main() {
	int arr[] = {5,2,1,2,1,5 }, n = 6;
	vector<int> fk;
	for(int i = 0 ; i < n ; ++i)
		fk.push_back(arr[i]);
	cout << sol.trap(fk) << endl;
	return 0;
}
