#include <iostream>
#include <string>
#include <vector>
#include "leetcode_new/array/myArray.cpp"
#include "leetcode_new/search/mySearch.cpp"

using namespace std;

int test(int n) {
    int sum = 0;
    while (n != 0) {
        int number = n % 10;
        sum += number * number;
        n = n / 10;
    }
    return sum;
}

int main() {
    //solution
    myArray::Solution solution = myArray::Solution();
    mySearch::Solution searchSolution = mySearch::Solution();
    //test data
    vector<int> testArray = {-1, 0, 1, 2, -1, -4};
//    string string1 = "Op";
//    string string1 = "abcabcbb";

    //test function
    auto result = searchSolution.threeSum(testArray);
//    bool result = solution.isOneBitCharacter(testArray);
//    vector<int> result = solution.twoSum(testArray, 19);
//    solution.sortColors(testArray);
//    bool result = solution.isPalindrome(string1);

    //show result
    for (auto i : result)
        for (auto j : i)
            cout << j << endl;
//    cout << result <<endl;

    return 0;
}

