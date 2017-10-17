//
// Created by shucheng on 17-10-16.
//
#include <string>

using namespace std;

namespace validPalindrome {
    class Solution {
    public:
        bool isPalindrome(string s) {
            int i = 0, j = s.length() - 1;
            while (i < j) {
                if (isalnum(s[i]) == 0) {
                    i++;
                    continue;
                }
                if (isalnum(s[j]) == 0) {
                    j--;
                    continue;
                }
                if (toupper(s[i++]) != toupper(s[j--]))
                    return false;
            }
            return true;
        }
    };
}
