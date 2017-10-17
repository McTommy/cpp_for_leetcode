//
// Created by shucheng on 17-10-15.
//
#include <iostream>
#include <vector>

using namespace std;

namespace removeDuplicatesfromSortedArray {
    class Solution {
    public:
        int removeDuplicates(vector<int> &nums) {
            int i = 0;
            for (int j = 1; j < nums.size(); j++)
            {
                if (nums[j] == nums[j - 1])
                    i++;
                else
                    nums[j - i] = nums[j];
            }
            return nums.size() - i;
        }
    };
}