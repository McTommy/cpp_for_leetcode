//
// Created by shucheng on 17-10-16.
//
#include <vector>

using namespace std;

namespace twoSum2 {
    class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            int i = 0, j = numbers.size() - 1;
            while (i < j) {
                if (numbers[i] + numbers[j] == target)
                    break;
                if (numbers[i] + numbers[j] > target)
                    j--;
                else
                    i++;
            }
            vector<int> result = {i + 1, j + 1};
            return result;
        }
    };
}

