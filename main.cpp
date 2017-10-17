#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <string>

//leetcode cpp source
//#include "leetcode/moveZeroes.cpp"
//#include "leetcode/removeElement.cpp"
//#include "leetcode/removeDuplicatesfromSortedArray.cpp"
//#include "leetcode/removeDuplicatesfromSortedArray2.cpp"
//#include "leetcode/sortColors.cpp"
//#include "leetcode/mergeSortedArray.cpp"
//#include "leetcode/kthLargestElementinanArray.cpp"
//#include "leetcode/twoSum2.cpp"
//#include "leetcode/validPalindrome.cpp"
//#include "leetcode/reverseString.cpp"
//#include "leetcode/minimumSizeSubarraySum.cpp"
//#include "leetcode/findAllAnagramsinaString.cpp"
//#include "leetcode/search/intersectionofTwoArrays.cpp"
//#include "leetcode/search/intersectionofTwoArrays2.cpp"
#include "leetcode/search/validAnagram.cpp"


using namespace std;


int main() {
//    vector<int> vector1 = {1, 2, 3, 2};
//    vector<int> vector2 = {1, 2, 2, 2};
//    intersectionofTwoArrays::Solution s;
//    vector<int> res = s.intersection(vector1, vector2);
//    auto itor = res.begin();
//    for (; itor != res.end(); itor++) {
//        cout << *itor << " ";
//    }
//    vector
//    vector<int> nums1 = {1, 5, 3, 2};
//    vector<int> nums2 = {2, 4, 6};
//    vector<int> vec[256];
//    minimumSizeSubarraySum::Solution s;
//    int result = s.minSubArrayLen(6, nums1);
//    cout << result << endl;
//    auto itor = nums1.begin();
//    for (; itor != nums1.end(); itor++) {
//        cout << *itor << " ";
//    }

//    string
    validAnagram::Solution s;
    string string1 = "A man, a plan, a canal: Panama";
    string string2 = "baa";
    bool results = s.isAnagram(string2, "ab");
//    for (int result : results) {
//        cout << result << endl;
//    }
    cout << results << endl;

//    search

    return 0;
}