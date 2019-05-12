#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct UpgradeNode {
    TreeNode *x;
    UpgradeNode *left;
    UpgradeNode *right;
    int leftVal, rightVal, val;
    UpgradeNode(int l, int r, int v, TreeNode *temp) : leftVal(l), rightVal(r), val(v), x(temp), left(NULL), right(NULL) {}
};
class Solution {
public:
    int helper(TreeNode* root, int val) {
        if (root == nullptr) {
            return val;
        }
        root->val += helper(root->right, val);
        return helper(root->left, root->val);
    }
    TreeNode* bstToGst(TreeNode* root) {
        helper(root, 0);
        return root;
    }
}sol;
TreeNode* buildTreeByArray(vector<int> arr, int now) {
    int L = now * 2, R = now * 2 + 1;
    TreeNode *cur = new TreeNode(arr[now]), *ll = nullptr, *rr = nullptr;
    if (L < arr.size() && arr[L] != -1) {
        ll = buildTreeByArray(arr, L);
    }
    if (R < arr.size() && arr[R] != -1) {
        rr = buildTreeByArray(arr, R);
    }
    cur->left = ll, cur->right = rr;
    return cur;
}
int main() {
    int arr[] = {0, 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    vector<int> x;
    for (int i = 0 ; i <= 15; ++i) x.push_back(arr[i]);
    TreeNode *root = buildTreeByArray(x, 1);
    // cout << root->left->val;
    root = sol.bstToGst(root);
    cout << root->right->left->val;
    return 0;
}