#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    string serializeHelper(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        if (!root) return "";
        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == nullptr) {
                ans += ",null";
            } else {
                q.push(cur->left);
                q.push(cur->right);
                ans += "," + to_string(cur->val);
            }
        }
        return ans.substr(1, ans.length() - 1);
    }
    TreeNode* deserializeHelper(vector<string> &nodes){
        int sz = nodes.size();
        int cur = 0;
        queue<int> q;
        q.push(0);
        TreeNode *root = nullptr;
        vector<TreeNode*> leile(sz, nullptr);
        for (int i = 0; i < sz; ++i) {
            if (nodes[i] != "null") leile[i] = new TreeNode(atoi(nodes[i].c_str()));
        }
        while(!q.empty()) {
            int id = q.front(); q.pop();
            TreeNode *now = leile[id];
            if (!root) root = now;
            ++cur;
            if (cur >= sz) continue;
            if (nodes[cur] != "null") {
                cout << now->val << "->(left)" <<  leile[cur]->val << endl;
                now->left = leile[cur];
                q.push(cur);
            }
            ++cur;
            if (cur >= sz) continue;
            if (nodes[cur] != "null") {
                cout << now->val << "->(right)" <<  leile[cur]->val << endl;
                now->right = leile[cur];
                q.push(cur);
            }
        }
        return root;
    }
    vector<string> split(string s) {
        int len = s.length();
        string cur = "";
        vector<string> ans;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ',') {
                ans.push_back(cur);
                cur = "";
            } else {
                cur += s[i];
            }
        }
        if (cur.length()) ans.push_back(cur);
        return ans;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serializeHelper(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data);
        int sz = nodes.size();
        if (!sz) return nullptr;
        return deserializeHelper(nodes);
    }
}sol;

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
//    TreeNode *a = new TreeNode(1);
//    for (int i = 2; i <)
//    TreeNode *b = new TreeNode(2);
//    TreeNode *c = new TreeNode(3);
//    TreeNode *d = new TreeNode(4);
//    a->left = b, b->left = c, c->left = d;
    //cout << sol.serialize(a);
    sol.deserialize("1,2,3,null,null,4,5");
    return 0;
}