#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
struct Node {
    char ch;
    Node *children[26];
    int endFlag;
    Node(char a) :  ch(a), endFlag(-1) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};
class Trie {
private:
    Node *root;
    vector<Node*> id;
    vector<int> ans;
    void dfs(Node *cur) {
        if (cur->endFlag != -1) ans.push_back(cur->endFlag);
        for (int i = 0; i < 26; ++i) {
            if (cur->children[i] == nullptr) continue;
            dfs(cur->children[i]);
        }
    }
public:
    Trie(int n) {
        root = new Node('R');
        id = vector<Node*>(n, nullptr);
    }
    ~Trie() {

    }
    void insert(string s, int index, int mode) {
        int len = s.length();
        Node *now = root;
        if (mode == 1) {
            for (int i = len - 1; i >= 0; --i) {
                char ch = s[i];
                if (!now->children[ch - 'a']) {
                    now->children[ch - 'a'] = new Node(ch);
                }
                now = now->children[ch - 'a'];
            }
        } else {
            for (int i = 0; i < len; ++i) {
                char ch = s[i];
                if (!now->children[ch - 'a']) {
                    now->children[ch - 'a'] = new Node(ch);
                }
                now = now->children[ch - 'a'];
            }
        }
        now->endFlag = index;
        id[index] = now;
    }

    vector<int> find(string s, int mode) {
        int len = s.length();
        Node *now = root;
        bool notComplete = false;
        ans.clear();
        if (mode == 1) {
            for (int i = len - 1; i >= 0; --i) {
                char ch = s[i];
                if (!now->children[ch - 'a']) {
                    notComplete = true;
                    break;
                }
                now = now->children[ch - 'a'];
            }

        } else {
            for (int i = 0; i < len; ++i) {
                char ch = s[i];
                if (!now->children[ch - 'a']) {
                    notComplete = true;
                    break;
                }
                now = now->children[ch - 'a'];
            }
        }
        if (notComplete) return {};
        dfs(now);
        return ans;
    }
};

class Solution {
    bool check(string s, int i, int j) {
        int l = i, r = j;
        //cout << s << "   " << i <<"   " << j << endl;
        while (l <= j) {
            if (s[l] != s[r]) return false;
            ++l, --r;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        Trie m_trie(n), m_reverse(n);
        vector<vector<int>> ans;
        int emptyIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (words[i].length() == 0) {
                emptyIdx = i;
                continue;
            }
            m_trie.insert(words[i], i, 0);
            m_reverse.insert(words[i], i, 1);
        }
        if (emptyIdx != -1) {
            for (int i = 0; i < n; ++i) {
                if (i != emptyIdx && check(words[i], 0, words[i].length() - 1)) {
                    vector<int> temp(2);
                    temp[0] = i, temp[1] = emptyIdx;
                    ans.push_back(temp);
                    temp[1] = i, temp[0] = emptyIdx;
                    ans.push_back(temp);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == emptyIdx) continue;
            vector<int> lists = m_trie.find(words[i], 1);
            int sz = lists.size(), len = words[i].length();
            for (int j = 0; j < sz; ++j) {
                if (lists[j] == i) continue;
                if (check(words[lists[j]], len, words[lists[j]].length() - 1)) {
                    vector<int> temp(2);
                    temp[0] = lists[j], temp[1] = i;
                    ans.push_back(temp);
                }
            }

            lists = m_reverse.find(words[i], 0);
            sz = lists.size();
            for (int j = 0; j < sz; ++j) {
                int lj = lists[j];
                if (lj == i || words[lj].length() == len) continue;
                if (check(words[lj], 0, words[lj].length() - len - 1)) {
                    vector<int> temp(2);
                    temp[0] = i, temp[1] = lists[j];
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
}solution;

int main() {
    string x[] = {"a","ab"};
    vector<string> s;
    for (int i = 0; i < 2; ++i) s.push_back(x[i]);
    solution.palindromePairs(s);
    return 0;
}