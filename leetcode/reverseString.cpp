//
// Created by shucheng on 17-10-16.
//
#include <string>

using namespace std;

namespace reverseString {
    class Solution {
    public:
        string reverseString(string s) {
            int i = 0, j = s.length() - 1;
            while (i < j) {
                swap(s[i++], s[j--]);
            }
            return s;
        }
    };
}

