#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    int findK(vector<int> &a, int la, int ra, vector<int> &b, int lb, int rb, int k) {
        int mid = k >> 1, mid1 = k - mid;
        if (la > ra && lb > rb) return -1;
        else if (la > ra) return b[lb + k - 1];
        else if (lb > rb) return a[la + k - 1];
        if (k == 1) return min(a[la], b[lb]);
        int aIndex = la + mid - 1, bIndex = lb + mid1 - 1; // since vector indexes starts from 0
        if (aIndex > ra) {
            bIndex += aIndex - ra;
            mid1 += aIndex - ra;
            mid  -= aIndex - ra;
            aIndex = ra;
        } else if (bIndex > rb) {
            aIndex += bIndex - rb;
            mid += bIndex - rb;
            mid1 -= bIndex - rb;
            bIndex = rb;
        }
        // cout << la << "  " << ra << "  " << lb << "  " << rb << "  " << k << endl;
        if (a[aIndex] == b[bIndex]) {
            return a[aIndex];
        } else if (a[aIndex] < b[bIndex]) {
            return findK(a, aIndex + 1, ra, b, lb, rb, k - mid);
        } else {
            return findK(a, la, ra, b, bIndex + 1, rb, k - mid1);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        int a = findK(nums1, 0, sz1 - 1, nums2, 0, sz2 - 1, ((sz1 + sz2) >> 1) + 1), b = 0;
        if (((sz1 + sz2) & 1) == 0) {
            b = findK(nums1, 0, sz1 - 1, nums2, 0, sz2 - 1, (sz1 + sz2) >> 1);
            return ((double)a + (double)b) / 2;
        }
        return (double)a;
    }
}solution;
int main() {
    int arr[] = { 2, 3, 4}, arr1[] = {1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums1(arr, arr + n);
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    vector<int> nums2(arr1, arr1 + n1);
    cout << solution.findMedianSortedArrays(nums1, nums2);
    return 0;
}