#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
bool cmp(pair<string, int> &x, pair<string, int> &y) {
    if (x.second != y.second) return x.second > y.second;
    return x.first < y.first;
}
class AutocompleteSystem {
private:
    vector<pair<string, int>> m_info;
    vector<string> m_sentence;
    vector<int > m_times;
    string word;
    int matchLen;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        m_sentence.clear();
        m_times.clear();
        word = "";
        m_sentence = sentences, m_times = times;

        m_info.clear();
        matchLen = 0;
        int sz = m_sentence.size();
        for (int i = 0; i < sz; ++i) {
            m_info.push_back(make_pair(m_sentence[i], m_times[i]));
        }
        sort(m_info.begin(), m_info.end(), cmp);
    }

    vector<string> input(char c) {
        if (c == '#') {
            m_info.clear();
            matchLen = 0;
            if (word.length()) {
                int idx = -1;
                for (int i = 0; i < m_sentence.size(); ++i) {
                    if (m_sentence[i] == word) {
                        idx = i;
                        break;
                    }
                }
                if (idx != -1) {
                    m_times[idx]++;
                } else {
                    m_sentence.push_back(word);
                    m_times.push_back(1);
                }
            }
            word = "";
            int sz = m_sentence.size();
            for (int i = 0; i < sz; ++i) {
                m_info.push_back(make_pair(m_sentence[i], m_times[i]));
            }
            sort(m_info.begin(), m_info.end(), cmp);

            return vector<string>();
        }

        auto st = m_info.begin();
        while (st != m_info.end()) {
            string s = st->first;
            if (s.length() <= matchLen || s[matchLen] != c) {
                st = m_info.erase(st);
            } else ++st;
        }

        vector<string> ans;
        int sz = m_info.size() > 3 ? 3 : m_info.size();
        for (int i = 0; i < sz; ++i) {
            ans.push_back(m_info[i].first);
        }
        ++matchLen;
        word += c;
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}