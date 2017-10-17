//
// Created by shucheng on 17-10-15.
//
#include <vector>

using namespace std;

namespace moveZeroes {
    class Solution {
    public:
        void moveZeroes(vector<int> &nums) {
            int i = 0;
            for (int j = 1; j < nums.size(); j++) {
                if (nums[i])
                    i++;
                else if (nums[j])
                    swap(nums[i++], nums[j]);
            }
        }
    };
}
