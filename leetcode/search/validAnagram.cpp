//
// Created by shucheng on 17-10-17.
//
#include <map>
#include <vector>

using namespace std;

namespace validAnagram {
    class Solution {
    public:
        bool isAnagram(string s, string t) {
            map<char, int> map1;
            int count = s.size();
            for (char letter : s)
                map1[letter]++;
            for (char letter : t)
                if (map1[letter] > 0) {
                    map1[letter]--;
                    count--;
                } else {
                    return false;
                }
            if (count)
                return false;
            return true;
        }
    };
}
