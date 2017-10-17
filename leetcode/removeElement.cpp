//
// Created by shucheng on 17-10-15.
//
#include <iostream>
#include <vector>

using namespace std;

namespace removeElement {
    class Solution {
    public:
        int removeElement(vector<int> &nums, int val) {
            int i = 0;
            for (int j = 1; j < nums.size(); j++) {
                if (nums[i] != val)
                    i++;
                else if (nums[j] != val)
                    swap(nums[i++], nums[j]);
            }
            return i;
        }
    };
}
