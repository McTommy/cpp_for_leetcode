//
// Created by shucheng on 17-10-17.
//
#include <set>
#include <vector>

using namespace std;

namespace intersectionofTwoArrays {
    class Solution {
    public:
        vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
            set<int> s;
            for (int num : nums2)
                s.insert(num);
            set<int> resultSet;
            for (int num : nums1) {
                if (s.find(num) != s.end())
                    resultSet.insert(num);
            }
            return vector<int>(resultSet.begin(), resultSet.end());
        }
    };
}
