#include <iostream>
#include <string>
#include <vector>

#include "leetcode_new/myList/LinkedListHelper.cpp"
#include "leetcode_new/myList/LinkedListStructure.h"

#include "leetcode_new/array/myArray.cpp"
#include "leetcode_new/search/mySearch.cpp"
#include "leetcode_new/myList/LinkedList.cpp"

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
    //helper
    LinkedListHelper::LinkedListHelper listHelper = LinkedListHelper::LinkedListHelper();

    //solution
    myArray::Solution solution = myArray::Solution();
    mySearch::Solution searchSolution = mySearch::Solution();
    LinkedList::Solution listSolution = LinkedList::Solution();
    //test data
    int testArray1[] = {1, 0, 1, 1};
    int testArray2[] = {3, 4, 7};
//    vector<int> testArray = {1, 2, 3, 4};
//    string string1 = "Op";
//    string string1 = "abcabcbb";

    //test function
//    auto result = searchSolution.threeSum(testArray);
//    bool result = solution.isOneBitCharacter(testArray);
//    vector<int> result = solution.twoSum(testArray, 19);
//    solution.sortColors(testArray);
//    bool result = solution.isPalindrome(string1);

    //list
    int listSize1 = sizeof(testArray1)/sizeof(int);
    int listSize2 = sizeof(testArray2)/sizeof(int);
    ListNode *testHead1 = listHelper.createLinkedList(testArray1, listSize1);
    ListNode *testHead2 = listHelper.createLinkedList(testArray2, listSize2);

    //show result
    listHelper.printLinkedList(testHead1);
//    listHelper.printLinkedList(testHead2);

//    ListNode *result = listSolution.insertionSortList(testHead1);
    bool boolResult = listSolution.isPalindrome(testHead1);
    cout << boolResult << endl;
//    listHelper.printLinkedList(result);
//    for (auto i : result)
//        for (auto j : i)
//            cout << j << endl;
//    cout << result <<endl;

    return 0;
}

