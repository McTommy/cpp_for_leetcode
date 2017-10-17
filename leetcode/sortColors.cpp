//
// Created by shucheng on 17-10-16.
// quick sort 3 ways
//
#include <vector>
#include <cassert>

using namespace std;

namespace sortColors {
    class Solution {
    public:
        void sortColors(vector<int> &nums) {
            int zero = -1, i = 0, two = nums.size();
            while (i < two) {
                if (nums[i] == 1)
                    i++;
                else if (nums[i] == 0)
                    swap(nums[++zero], nums[i++]);
                else
                    swap(nums[i], nums[--two]);
            }
//            int count[3] = {0};
//            for (int num : nums) {
//                assert(num >= 0 && num <= 2);
//                count[num]++;
//            }
//
//            int index = 0;
//            for (int i = 0; i < count[0]; i++)
//                nums[index++] = 0;
//            for (int i = 0; i < count[1]; i++)
//                nums[index++] = 1;
//            for (int i = 0; i < count[2]; i++)
//                nums[index++] = 2;
        }
    };
}

