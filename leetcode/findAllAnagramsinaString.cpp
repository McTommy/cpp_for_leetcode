//
// Created by shucheng on 17-10-16.
//
#include <string>
#include <vector>

using namespace std;

namespace findAllAnagramsinaString {
    class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> pv(256,0), sv(256,0), res;
            if (s.size() < p.size())
                return res;

            for (int i = 0; i < p.size(); i++) {
                pv[p[i]]++;
                sv[s[i]]++;
            }
            if (pv == sv)
                res.push_back(0);
            for (int i = p.size(); i < s.size(); i++) {
                sv[s[i]]++;
                sv[s[i-p.size()]]--;
                if (sv == pv)
                    res.push_back(i-p.size()+1);
            }
            return res;
        }
    };
}