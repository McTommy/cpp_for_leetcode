//
// Created by shucheng on 17-10-16.
//
#include <vector>

using namespace std;

namespace minimumSizeSubarraySum {
    class Solution {
    public:
        int minSubArrayLen(int s, vector<int> &nums) {
            int l = 0, r = -1;
            int sum = 0;
            int res = nums.size() + 1;
            while (l < nums.size()) {
                if (r + 1 < nums.size() && sum < s) {
                    r++;
                    sum += nums[r];
                } else {
                    sum -= nums[l++];
                }
                if (sum >= s)
                    res = min(res, r - l + 1);
            }
            if (res == nums.size() + 1)
                return 0;
            return res;
        }
    };
}

