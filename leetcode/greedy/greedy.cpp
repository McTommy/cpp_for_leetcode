//
// Created by shucheng on 17-11-13.
//
#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cassert>

#include "../stackAndQueue/structure.h"

using namespace std;

namespace greedy {


    class Solution {
    private:
        struct Interval {
            int start;
            int end;

            Interval() : start(0), end(0) {}

            Interval(int s, int e) : start(s), end(e) {}
        };

        bool static compare_interval(const Interval &a, const Interval &b) {
            if (a.start != b.start)
                return a.start < b.start;
            return a.end < b.end;
        }

    public:
        int findContentChildren(vector<int> &g, vector<int> &s) {
            sort(g.begin(), g.end(), greater<int>());
            sort(s.begin(), s.end(), greater<int>());

            int si = 0, gi = 0;
            int res = 0;

            while (gi < g.size() && si < s.size()) {
                if (s[si] >= g[gi]) {
                    res++;
                    si++;
                    gi++;
                } else {
                    gi++;
                }
            }

            return res;
        }

        bool isSubsequence(string s, string t) {
            int index = 0;
            for (auto c : t)
                if (c == s[index])
                    index ++;

            if (index == s.size())
                return true;
            return false;
        }

        int eraseOverlapIntervals(vector<Interval> &intervals) {
            if (intervals.size() == 0) return 0;

            sort(intervals.begin(), intervals.end(), compare_interval);

            vector<int> memo(intervals.size(), 1);
            for (int i = 1; i < intervals.size(); i++)
                for (int j = 0; j < i; j++)
                    if (intervals[i].start >= intervals[j].end)
                        memo[i] = max(memo[i], 1 + memo[j]);

            int res = 0;
            for (auto i : memo)
                res = max(res, i);

            return intervals.size() - res;
        }


    };
}
