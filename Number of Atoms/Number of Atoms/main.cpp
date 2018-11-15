//
//  main.cpp
//  Number of Atoms
//
//  Created by yuhan_wu on 11/15/18.
//  Copyright © 2018 yuhan_wu. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<int> m_stack;
        string pendingAtom = "";
        int pos = 0;
        while(pos < formula.length()) {
            char ch = formula[pos];
            //cout << ch << endl;
            if (ch == '(') {
                m_stack.push(-(pos + 1));
                ++pos;
            }
            else if (ch == ')') {
                if (m_stack.empty()) return string("");
                int leftPos = -m_stack.top() - 1;
                m_stack.pop();
                pendingAtom = formula.substr(leftPos + 1, pos - leftPos - 1);
                int countPos = pos + 1, count = 0;
                while (formula[countPos] >= '0' && formula[countPos] <= '9') {
                    count = count * 10 + formula[countPos] - '0';
                    ++countPos;
                }
                if (!count) count = 1;
                string parsedStr = parseSimpleStr(pendingAtom, count);
                int tempLen = countPos - leftPos;
                formula.replace(leftPos, tempLen, parsedStr);
                pos += (parsedStr.length() - tempLen) + 1;
            } else ++pos;
        }
        countToMap(formula);
        string result = "";
        for (map<string,int>::iterator it = times.begin(); it != times.end(); ++it) {
            result.append(it->first);
            if (it->second > 1) result.append(to_string(it->second));
        }
        return result;
    }
private:
    void addToMap(string key, int value) {
        if (times.find(key) == times.end())
            times[key] = value;
        else
            times[key] += value;
    }
    void countToMap(string str) {
        str += 'A';
        int len = str.length(), mode = 0;
        string result = "", cur = "", originCount = "";
        for (int i = 0; i < len; ++i) {
            char ch = str[i];
            if (mode == 0) {
                mode = 1;
                cur = ch;
            } else if (mode == 1) {
                if (ch >= 'A' && ch <= 'Z') {
                    addToMap(cur, 1);
                    cur = ch;
                    originCount = "";
                }
                else if (ch >= 'a' && ch <= 'z') cur += ch;
                else {
                    originCount = ch;
                    mode = 2;
                }
            } else if (mode == 2) {
                // digits
                if (ch >= '0' && ch <= '9') originCount += ch;
                else {
                    addToMap(cur, atoi(originCount.c_str()));
                    cur = ch;
                    originCount = "";
                    mode = 1;
                }
            }
        }
    }
    string parseSimpleStr(string str, int count) {
        str += 'A';
        int len = str.length(), mode = 0;
        string result = "", cur = "", originCount = "";
        for (int i = 0; i < len; ++i) {
            char ch = str[i];
            if (mode == 0) {
                mode = 1;
                cur = ch;
            } else if (mode == 1) {
                if (ch >= 'A' && ch <= 'Z') {
                    result.append(cur + to_string(count));
                    cur = ch;
                    originCount = "";
                }
                else if (ch >= 'a' && ch <= 'z') cur += ch;
                else {
                    originCount = ch;
                    mode = 2;
                }
            } else if (mode == 2) {
                // digits
                if (ch >= '0' && ch <= '9') originCount += ch;
                else {
                    result.append(cur + to_string(atoi(originCount.c_str()) * count));
                    cur = ch;
                    originCount = "";
                    mode = 1;
                }
            }
        }
        return result;
    }
    map<string, int> times;
}sol;

int main(int argc, const char * argv[]) {
    cout << sol.countOfAtoms(string("K4(ON(SO3)2)2"));
    return 0;
}
