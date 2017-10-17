//
// Created by shucheng on 17-10-17.
//
#include <map>
#include <vector>

using namespace std;

namespace intersectionofTwoArrays {
    class Solution {
    public:
        vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
            map<int, int> record;
            for (int num : nums1)
                record[num]++;
            vector<int> res;
            for (int num : nums2)
                if (record[num] > 0){
                    res.push_back(num);
                    record[num]--;
                }

            return res;
        }
    };
}
