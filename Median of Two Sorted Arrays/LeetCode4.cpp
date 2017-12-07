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
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
		int length_all = A.size() + B.size() , t = length_all / 2 , szA = A.size() , szB = B.size();
		if(length_all == 0) return 0.0;
		if(A.size() == 0) {
			if(length_all % 2 == 0) 
				return (double)(B[t - 1] + B[t > szB - 1 ? t - 1 : t]) / 2.0;
			else
				return (double)B[t];
		} else if(B.size() == 0) {
			if(length_all % 2 == 0) 
				return (double)(A[t - 1] + A[t > szA - 1 ? t - 1 : t]) / 2.0;
			else
				return (double)A[t];
		}
		if(length_all % 2 == 0) {
			int ans1 = findK(A , B , length_all / 2 , -1 , -1);
			int ans2 = findK(A , B , (length_all / 2) + 1 , -1 , -1);
			//printf_s("%d %d\n", ans1, ans2);
			return double(ans1 + ans2) / 2;
		} else {
			return (double)findK(A , B , (length_all / 2) + 1 , -1 , -1);
		}
    }
	int findK(vector <int> A , vector <int> B , int k , int stA , int stB) {
	    int lena = A.size() , lenb = B.size();
		int mk = min(k / 2 , lena) , mk1 = k - mk;
		if(A.size() - stA > B.size() - stB) return findK(B , A , k , stB , stA);
		if(stA == A.size() - 1)
			return B[stB + k];
		//printf_s("%d %d %d\n", stA, stB, k);
		if(k == 1) {
			int ans = 2147483645;
			if((stA + 1) <= (lena - 1)) 
				ans = min(ans , A[stA + 1]);
			if((stB + 1) <= (lenb - 1)) 
				ans = min(ans , B[stB + 1]);
			return ans;
		}
		if(A[stA + mk] < B[stB + mk1]) 
			return findK(A , B , k - mk , stA + mk , stB);
		else if(A[stA + mk] > B[stB + mk1])
			return findK(A , B , k - mk1 , stA , stB + mk1);
		else return A[stA + mk];
	}
}m_solo;
int main() {
	int arr[] = {5,2,1,2,1,5 }, n = 6;
	vector<int> fk;
	for(int i = 0 ; i < n ; ++i)
		fk.push_back(arr[i]);

	return 0;
}
