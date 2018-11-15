//
//  main.cpp
//  Employee Free Time
//
//  Created by yuhan_wu on 11/14/18.
//  Copyright © 2018 yuhan_wu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define inf 123456789

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        int numEmployees = schedule.size();
        if (!numEmployees) return vector<Interval>();
        vector<vector<Interval>> freeSchedule;
        for (int i = 0; i < numEmployees; ++i) {
            vector<Interval> temp;
            int numWorkSchedule = schedule[i].size();
            for (int j = 0; j < numWorkSchedule; ++j) {
                if (j == 0) {
                    if (schedule[i][j].start > 1)
                        temp.push_back(Interval(0, schedule[i][j].start));
                }
                if (j == numWorkSchedule - 1) {
                    if (j) {
                        int start = schedule[i][j - 1].end, end = schedule[i][j].start;
                        if (end > start)
                            temp.push_back(Interval(start, end));
                    }
                    temp.push_back(Interval(schedule[i][j].end, inf));
                } else {
                    if (!j) continue;
                    int start = schedule[i][j - 1].end, end = schedule[i][j].start;
                    if (end > start)
                        temp.push_back(Interval(start, end));
                }
            }
            freeSchedule.push_back(temp);
        }
        schedule = freeSchedule;
        vector<Interval> m_inter(schedule[0]);
        for (int i = 1; i < numEmployees; ++i) {
            int numIntervals = schedule[i].size(), resultInter = m_inter.size();
            int l = 0, r = 0;
            vector<Interval> temp;
            while (l < resultInter || r < numIntervals) {
                if (m_inter[l].start > schedule[i][r].end) {
                    ++r;
                    continue;
                }
                if (schedule[i][r].start > m_inter[l].end) {
                    ++l;
                    continue;
                }
                int start = -1, end = -1;
                if (schedule[i][r].end != inf && m_inter[l].end != inf) {
                    start = max(schedule[i][r].start, m_inter[l].start);
                    end = min(schedule[i][r].end, m_inter[l].end);
                    if (end > start) temp.push_back(Interval(start, end));
                    if (schedule[i][r].end > m_inter[l].end) {
                        ++l;
                        schedule[i][r].start = end;
                    } else if (schedule[i][r].end < m_inter[l].end){
                        ++r;
                        m_inter[l].start = end;
                    } else {
                        ++l; ++r;
                    }
                } else if (schedule[i][r].end == inf && m_inter[l].end != inf) {
                    start = max(schedule[i][r].start, m_inter[l].start);
                    end = m_inter[l].end;
                    schedule[i][r].start = end;
                    if (end > start) temp.push_back(Interval(start, end));
                    ++l;
                } else if (schedule[i][r].end != inf && m_inter[l].end == inf) {
                    start = max(schedule[i][r].start, m_inter[l].start);
                    end = schedule[i][r].end;
                    m_inter[l].start = end;
                    if (end > start) temp.push_back(Interval(start, end));
                    ++r;
                } else {
                    start = max(schedule[i][r].start, m_inter[l].start);
                    end = inf;
                    schedule[i][r].start = start;
                    if (end > start && i != numEmployees - 1) temp.push_back(Interval(start, end));
                    break;
                }
            }
            m_inter = temp;
            if (!m_inter.size()) break;
        }
        vector<Interval> result;
        for (int i = 0; i < m_inter.size(); ++i) {
            if (m_inter[i].start != 0) result.push_back(m_inter[i]);
        }
        return result;
    }
}sol;
int main(int argc, const char * argv[]) {
    vector<Interval> person1;
    person1.push_back(Interval(1, 3));
    person1.push_back(Interval(6, 7));
    vector<Interval> person2;
    person2.push_back(Interval(2, 4));
    vector<Interval> person3;
    person3.push_back(Interval(2, 5));
    person3.push_back(Interval(9, 12));
    vector<vector<Interval>> schedule;
    schedule.push_back(person1);
    schedule.push_back(person2);
    schedule.push_back(person3);
    vector<Interval> result = sol.employeeFreeTime(schedule);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].start << "   " << result[i].end << endl;
    }
    return 0;
}
