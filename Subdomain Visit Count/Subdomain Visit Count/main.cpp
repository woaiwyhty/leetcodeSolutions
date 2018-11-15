//
//  main.cpp
//  Subdomain Visit Count
//
//  Created by yuhan_wu on 11/14/18.
//  Copyright © 2018 yuhan_wu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> times;
        int sz = cpdomains.size();
        for (int i = 0; i < sz; ++i) {
            int pos = cpdomains[i].find(' '), count = 0;
            string temp = "";
            if (pos == -1) {
                temp = cpdomains[i];
                count = 1;
            } else {
                temp = cpdomains[i].substr(pos + 1, cpdomains[i].length() - pos - 1);
                count = atoi(cpdomains[i].substr(0, pos).c_str());
            }
            if (times.find(temp) == times.end())
                times[temp] = count;
            else
                times[temp] += count;
            int len = temp.length();
            for (int j = len - 1; j >= 0; --j) {
                if (temp[j] == '.') {
                    string subdomain = temp.substr(j + 1, len - j - 1);
                    if (times.find(subdomain) == times.end()) times[subdomain] = count;
                    else times[subdomain] += count;
                }
            }
        }
        vector<string> result;
        for (map<string, int>::iterator i = times.begin(); i != times.end(); ++i) {
            cout << to_string(i->second) + " " + i->first << endl;
            result.push_back(to_string(i->second) + " " + i->first);
        }
        return result;
    }
}sol;

int main(int argc, const char * argv[]) {
    vector<string> test;
    test.push_back("9001 discuss.leetcode.com");
    sol.subdomainVisits(test);
    return 0;
}
