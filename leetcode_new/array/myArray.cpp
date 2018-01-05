//
// Created by shucheng on 17-12-27.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

namespace myArray {
    class Solution {
    public:
        int binarySearch(const int arr[], int n, int target) {

            int start = 0, end = n;
            while (start < end) {
                int mid = start - (start - end) / 2;
                if (arr[mid] == target) return mid;
                else if (arr[mid] > target) end = mid;
                else start = mid + 1;
            }

            return -1;
        }

        //283 Move Zeroes
        void moveZeroes(vector<int> &nums) {
            auto size = static_cast<int>(nums.size());
            int j = 0;

            for (int i = 0; i < size; i++) {
                if (nums[i] != 0)
                    nums[j++] = nums[i];

            }

            for (; j < size; j++)
                nums[j] = 0;
        }

        void moveZeros2(vector<int> &nums) {
            for (int i = 0, j = 0; i < nums.size(); i++)
                if (nums[i] != 0)
                    if (i != j)
                        swap(nums[i], nums[j++]);
                    else
                        j++;
        }

        //26. Remove Duplicates from Sorted Array
        int removeDuplicates(vector<int> &nums) {
            int size = nums.size();
            if (size < 2)
                return size;
            int j = 0;
            for (int i = 0; i < size; i++) {
                if (nums[i] > nums[j])
                    nums[++j] = nums[i];
            }
            return j + 1;
        }

        //27. Remove Element
        int removeElement(vector<int> &nums, int val) {
            int size = nums.size();
            if (size == 0) return 0;

            int j = 0;
            for (int i = 0; i < size; i++) {
                if (nums[i] != val)
                    nums[j++] = nums[i];
            }

            return j;
        }

        //80. Remove Duplicates from Sorted Array II
        int removeDuplicates2(vector<int> &nums) {
            int i = 0;
            for (int n : nums)
                if (i < 2 || n > nums[i - 2])
                    nums[i++] = n;
            return i;
        }

        //75. Sort Colors
        void sortColors(vector<int> &nums) {
            int size = nums.size();
            if (size == 0)
                return;
            int i = -1, j = 0, k = size;
            while (j < k) {
                if (nums[j] == 0) {
                    swap(nums[++i], nums[j++]);
                } else if (nums[j] == 1)
                    j++;
                else
                    swap(nums[j], nums[--k]);
            }
        }

        //88. Merge Sorted Array
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
            int i = m - 1, j = n - 1, tar = m + n - 1;
            while (j >= 0) {
                nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
            }
        }

        //215. Kth Largest Element in an Array
        int findKthLargest(vector<int> &nums, int k) {
//            int size = nums.size();
//            sort(nums.begin(), nums.end());
//            return nums[size - k];

            //partition
        }

        //167. Two Sum II - Input array is sorted
        //对撞指针
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> result;
            int size = numbers.size();
            if (size < 2) return result;

            int i = 0, j = size - 1;
            while (i < j) {
                if (numbers[i] + numbers[j] == target) {
                    result.push_back(i + 1);
                    result.push_back(j + 1);
                    return result;
                } else if (numbers[i] + numbers[j] < target)
                    i++;
                else
                    j--;
            }
            return result;
        }

        //125. Valid Palindrome
        bool isPalindrome(string s) {
            int start = 0, end = s.length() - 1;
            while (start < end) {
                if (!isalnum(s[start])) start++;
                else if (!isalnum(s[end])) end--;
                else {
                    if (tolower(s[start++]) != tolower(s[end--])) return false;
                }
            }
            return true;
        }

        //345. Reverse Vowels of a String
        //using find_first_of function
        string reverseVowels(string s) {
            int i = 0, j = static_cast<int>(s.size() - 1);
            while (i < j) {
                i = static_cast<int>(s.find_first_of("aeiouAEIOU", static_cast<unsigned long>(i)));
                j = static_cast<int>(s.find_last_of("aeiouAEIOU", static_cast<unsigned long>(j)));
                if (i < j) {
                    swap(s[i++], s[j--]);
                }
            }
            return s;
        }

        //11. Container With Most Water
        int maxArea(vector<int> &height) {
            int result = 0, i = 0, j = height.size() - 1, newArea;
            while (i < j) {
                if (height[i] > height[j]) {
                    newArea = height[j] * (j - i);
                    j--;
                } else {
                    newArea = height[i] * (j - i);
                    i++;
                }
                result = max(newArea, result);
            }
            return result;
        }

        //
        //209. Minimum Size Subarray Sum
        //滑动窗口
        int minSubArrayLen(int s, vector<int> &nums) {
            int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                while (sum >= s) {
                    minlen = min(minlen, i - start + 1);
                    sum -= nums[start++];
                }
            }
            return minlen == INT_MAX ? 0 : minlen;
        }

        //3. Longest Substring Without Repeating Characters
        int lengthOfLongestSubstring(string s) {
            int l = 0, r = -1, length = 0;
            int freq[256] = {0};

            while (l < s.size()) {
                if (r + 1 < s.size() && freq[s[r + 1]] == 0) {
                    r++;
                    freq[s[r]]++;
                } else {
                    freq[s[l++]]--;
                }

                length = max(length, r - l + 1);
            }
            return length;
        }

        //
        //438. Find All Anagrams in a String
        vector<int> findAnagrams(string s, string p) {
            vector<int> sv(256, 0), pv(256, 0);
            vector<int> result;
            int i;

            for (i = 0; i < p.size(); i++) {
                sv[s[i]]++;
                pv[p[i]]++;
            }
            if (sv == pv) result.push_back(0);

            for (int j = i; j < s.size(); j++) {
                sv[s[j - i]]--;
                sv[s[j]]++;
                if (sv == pv)
                    result.push_back(j - i + 1);
            }
            return result;
        }

        //717. 1-bit and 2-bit Characters
        bool isOneBitCharacter(vector<int> &bits) {
            int size = bits.size();
            int i = 0;
            while (i < size) {
                if (i == size - 1)
                    return true;
                if (bits[i] == 1)
                    i += 2;
                else
                    i++;
            }
            return false;
        }

        //566. Reshape the Matrix
        vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
            queue<int> record;
            vector<vector<int>> result(r, vector<int>(c, 0));
            for (auto i : nums)
                for (auto j :i)
                    record.push(j);
            if (record.size() != r * c)
                return nums;

            for (int i = 0; i < r; i++)
                for (int j = 0;j < c; j++) {
                    result[i][j] = record.front();
                    record.pop();
                }
            return result;
        }
    };
}

