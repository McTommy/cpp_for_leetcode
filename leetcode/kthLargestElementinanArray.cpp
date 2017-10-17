//
// Created by shucheng on 17-10-16.
//

#include <vector>
#include <cassert>

using namespace std;

namespace kthLargestElementinanArray {
    class Solution {
    public:
        int findKthLargest(vector<int> &nums, int k) {
            int left = 0, right = nums.size();
            while (true) {
                int pos = partition(nums, left, right);
                if (pos == k - 1)
                    return nums[pos];
                if (pos > k - 1) right = pos - 1;
                else left = pos + 1;
            }
        }

        int partition(vector<int> &nums, int left, int right) {
            int pivot = nums[left];
            int l = left + 1, r = right;
            while (l <= r) {
                if (nums[l] < pivot && nums[r] > pivot)
                    swap(nums[l++], nums[r--]);
                if (nums[l] >= pivot) l++;
                if (nums[r] <= pivot) r--;
            }
            swap(nums[left], nums[r]);
            return r;
        }
    };
}
