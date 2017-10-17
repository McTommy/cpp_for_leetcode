//
// Created by shucheng on 17-10-15.
//
#include <iostream>
#include <vector>

using namespace std;

namespace removeDuplicatesfromSortedArray2 {
    class Solution {
    public:
        int removeDuplicates(vector<int> &nums) {
            int i = 0;
            for (int n : nums)
                if (i < 2 || n > nums[i - 2])
                    nums[i++] = n;
            return i;
        }
    };
}