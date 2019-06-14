#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    char ch;
    Node *children[26];
    int endFlag;
    Node(char a) :  ch(a), endFlag(-1) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};
int n, m;
int movx[4] = {0, -1, 0, 1}, movy[4] = {1, 0, -1, 0};
vector<string> ans;

vector<string> gWords;
class Trie {
private:
    Node *root;
    vector<Node*> id;
    vector<bool> isIn;
    void dfs( int x, int y, Node *now, vector<vector<char>>& board, vector<vector<bool>> &visit) {
        visit[x][y] = true;
        if (!now) return;
        cout << now->ch << "  " << x << "  " << y << endl;
        if (now->endFlag != -1) {
            if (!isIn[now->endFlag]) {
                ans.push_back(gWords[now->endFlag]);
                isIn[now->endFlag] = true;
            }
        }
        bool flag = false;
        for (int i = 0; i < 4; ++i) {
            int nx = x + movx[i], ny = y + movy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]
                && now->children[board[nx][ny] - 'a']) {
                visit[nx][ny] = true;
                dfs(nx, ny, now->children[board[nx][ny] - 'a'], board, visit);
                visit[nx][ny] = false;
            }
        }
        return;
    }
public:
    Trie(int n) {
        root = new Node('R');
        id = vector<Node*>(n, nullptr);
        isIn = vector<bool >(n, false);
    }
    ~Trie() {

    }
    void insert(string s, int index) {
        int len = s.length();
        Node *now = root;
        for (int i = 0; i < len; ++i) {
            char ch = s[i];
            if (!now->children[ch - 'a']) {
                now->children[ch - 'a'] = new Node(ch);
            }
            now = now->children[ch - 'a'];
        }
        now->endFlag = index;
        id[index] = now;
    }

    void find(vector<vector<char>>& board) {
        Node *now = root;
        for (int i = 0; i < 26; ++i) {
            if (now->children[i]) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < m; ++k) {
                        if (board[j][k] == i + 'a') {
                            vector<vector<bool>> visited(n, vector<bool>(m, false));
                            dfs(j, k, now->children[i], board, visited);
                        }
                    }
                }
            }
        }
    }

};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int sz = words.size();
        n = board.size();
        if (!n) return {};
        m = board[0].size();
        ans.clear();
        Trie trie(sz);
        for (int i = 0; i < sz; ++i) {
            trie.insert(words[i], i);
        }
        gWords = words;
        trie.find(board);
        return ans;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}