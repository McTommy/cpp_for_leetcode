#include <iostream>
#include <stack>
#include <queue>

#include "leetcode/list/LinkedList.cpp"
#include "leetcode/list/LinkedListHelper.cpp"

#include "leetcode/stackAndQueue/stackAndQueue.cpp"
#include "leetcode/stackAndQueue/stackAndQueueHelper.cpp"

#include "leetcode/recursion/recursionAndTree.cpp"
#include "leetcode/dynamicProgramming/dynamicProgramming.cpp"
#include "leetcode/greedy/greedy.cpp"

using namespace std;

int main() {
    greedy::Solution solution = greedy::Solution();
    int result;
//    vector<vector<int> > test = {{1, 2, 5}, {3, 2, 1}};
//    string string1 = "";
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    vector<int> nums = {1, 1 ,1 ,1 ,1};
    int m  = 5, n = 3;
    result = 1;
    if (find(strs.begin(), strs.end(), "1") != strs.end()){
        cout << result << endl;
    }

    return 0;
}