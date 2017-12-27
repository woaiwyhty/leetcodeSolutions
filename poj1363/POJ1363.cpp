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
bool check(int arr[], int n) {
	stack <int> s; bool visited[1005];
	for (int i = 1; i <= 1000; ++i) visited[i] = 0;
	int last = 0;
	for (int i = 0; i < n; ++i) {
		if (!s.empty() && visited[arr[i]] && s.top() != arr[i]) return false;
		else if (!visited[arr[i]]) {
			s.push(arr[i]); visited[arr[i]] = 1;
			s.pop();
		}
		else if (s.top() == arr[i]) s.pop();
		for (int j = last + 1; j < arr[i]; ++j) {
			if (!visited[j]) s.push(j), visited[j] = 1;
		}
		last = arr[i];
	}
	return true;
}
int main() {
	int n, arr[1005];
	for (int i = 0; i < 1000; ++i) arr[i] = 0;
	cin >> n;
	while (n) {
		int i = 0;
		while (true) {
			cin >> arr[i];
			if (!arr[i]) {
				cout << endl;
				break;
			}
			else {
				++i;
				if (i == n) {
					bool res = check(arr, n);
					if (res) cout << "Yes" << endl;
					else cout << "No" << endl;
					i = 0;
				}
			}
		}
		cin >> n;
	}
	return 0;
}