#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* R;
    int ans;
    int dfs(TreeNode *cur, int f) {
        int x = -2147483647;
        if (cur->left) {
            x = dfs(cur->left, f + cur->left->val);
        }

        int y = -2147483647;
        if (cur->right) {
            y = dfs(cur->right, f + cur->right->val);
        }
        ans = max(ans, cur->val);
        if (!cur->left && !cur->right) {
            x = cur->val;
            ans = max(ans, x);
            return x;
        } else if (cur->left && cur->right){
            ans = max(ans, x + y + cur->val);
            ans = max(ans, x + cur->val);
            ans = max(ans, y + cur->val);
        } else if(!cur->left) {
            ans = max(ans, y + cur->val);
        } else {
            ans = max(ans, x + cur->val);
        }

        return max(max(x, y), 0) + cur->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        R = root;
        ans = -2147483647;
        dfs(root, 0);
        return ans;
    }
}solution;
int main() {
    TreeNode *r = new TreeNode(1);
    TreeNode *a = new TreeNode(2);
    TreeNode *b = new TreeNode(-3);
    r->left = a, a->right = b;
    cout << solution.maxPathSum(r);
    return 0;
}