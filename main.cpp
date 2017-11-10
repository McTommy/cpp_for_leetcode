#include <iostream>
#include <stack>
#include <queue>

#include "leetcode/list/LinkedList.cpp"
#include "leetcode/list/LinkedListHelper.cpp"

#include "leetcode/stackAndQueue/stackAndQueue.cpp"
#include "leetcode/stackAndQueue/stackAndQueueHelper.cpp"

#include "leetcode/recursion/recursionAndTree.cpp"
#include "leetcode/dynamicProgramming/dynamicProgramming.cpp"

using namespace std;

int main() {
    dynamicProgramming::Solution solution = dynamicProgramming::Solution();
    int result;
    // vector<vector<int> > test = {{1, 2, 5}, {3, 2, 1}};
    string string1 = "";
    vector<int> nums(3, 0);
    result = solution.rob(nums);
    cout << result << endl;
    return 0;
}