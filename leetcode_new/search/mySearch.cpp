//
// Created by shucheng on 17-12-28.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

namespace mySearch {
    class Solution {
    public:
        //set
        //349. Intersection of Two Arrays
        vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
            unordered_set<int> first, result;
            vector<int> res;
            for (auto i : nums1)
                first.insert(i);

            for (auto j : nums2)
                if (first.find(j) != first.end())
                    result.insert(j);

            for (auto k : result)
                res.push_back(k);

            return res;
        }

        //map
        //c++ map:有默认值
        //350. Intersection of Two Arrays II
        vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
            unordered_map<int, int> record;
            vector<int> result;
            for (auto i : nums1)
                if (record.find(i) == record.end())
                    record.insert(make_pair(i, 1));
                else
                    record[i]++;

            for (auto j : nums2)
                if (record.find(j) != record.end() && record[j] > 0) {
                    record[j]--;
                    result.push_back(j);
                    if (record[j] == 0)
                        record.erase(j);
                }

            return result;
        }

        //set 与 map　O(logn)　平衡二叉树实现
        //unordered_set unordered_map O(1) 哈希表实现

        //242. Valid Anagram
        bool isAnagram(string s, string t) {
            unordered_map<char, int> sMap, tMap;
            for (auto i : s)
                sMap[i]++;
            for (auto j : t)
                tMap[j]++;
            return sMap == tMap;
        }

        //202. Happy Number
        bool isHappy(int n) {
            unordered_set<int> record;
            while (n != 1) {
                if (record.find(n) != record.end())
                    return false;
                record.insert(n);
                n = eachNumberSquareSum(n);
            }
            return true;
        }

        //
        //290. Word Pattern
        bool wordPattern(string pattern, string str) {
            unordered_map<char, int> p2i;
            unordered_map<string, int> w2i;
            istringstream in(str);
            int i = 0, n = pattern.size();
            for (string word; in >> word; i++) {
                if (i == n || p2i[pattern[i]] != w2i[word])
                    return false;
                p2i[pattern[i]] = w2i[word] = i + 1;
            }
            return i == n;
        }

        //205. Isomorphic Strings
        bool isIsomorphic(string s, string t) {
            int m1[256] = {0}, m2[256] = {0}, n = s.size();
            for (int i = 0; i < n; i++) {
                if (m1[s[i]] != m2[t[i]]) return false;
                m1[s[i]] = i + 1;
                m2[t[i]] = i + 1;
            }
            return true;
        }

        //
        //451. Sort Characters By Frequency
        string frequencySort(string s) {
            unordered_map<char, int> record;
            vector<string> store(s.size() + 1, "");
            string result;

            for (auto i : s)
                record[i]++;

            for (auto j : record) {
                int freq = j.second;
                char c = j.first;
                store[freq].append(freq, c);
            }

            for (int k = store.size() - 1; k >= 0; k--) {
                result += store[k];
            }
            return result;
        }

        //1. Two Sum
        vector<int> twoSum(vector<int> &nums, int target) {
            unordered_map<int, int> record;
            vector<int> result;

            for (int i = 0; i < nums.size(); i++) {
                if (record.find(target - nums[i]) != record.end()) {
                    result.push_back(record[target - nums[i]]);
                    result.push_back(i);
                    return result;
                } else {
                    record.insert(make_pair(nums[i], i));
                }
            }
        }

        //
        //15. 3Sum
        vector<vector<int>> threeSum(vector<int> &nums) {
            vector<vector<int> > res;

            sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size(); i++) {

                int target = -nums[i];
                int front = i + 1;
                int back = nums.size() - 1;

                while (front < back) {

                    int sum = nums[front] + nums[back];

                    // Finding answer which start from number num[i]
                    if (sum < target)
                        front++;

                    else if (sum > target)
                        back--;

                    else {
                        vector<int> triplet(3, 0);
                        triplet[0] = nums[i];
                        triplet[1] = nums[front];
                        triplet[2] = nums[back];
                        res.push_back(triplet);

                        // Processing duplicates of Number 2
                        // Rolling the front pointer to the next different number forwards
                        while (front < back && nums[front] == triplet[1]) front++;

                        // Processing duplicates of Number 3
                        // Rolling the back pointer to the next different number backwards
                        while (front < back && nums[back] == triplet[2]) back--;
                    }

                }

                // Processing duplicates of Number 1
                while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                    i++;

            }

            return res;
        }

        //16. 3Sum Closest
        int threeSumClosest(vector<int> &nums, int target) {
            int nums_size = nums.size();
            int closest = nums[0] + nums[1] + nums[2];

            sort(nums.begin(), nums.end());
            for (int first = 0; first < nums_size - 2; first++) {
                if (first > 0 && nums[first] == nums[first - 1]) continue;
                int second = first + 1;
                int third = nums_size - 1;
                while (second < third) {
                    int curSum = nums[first] + nums[second] + nums[third];
                    if (curSum == target) return curSum;
                    if (abs(target - curSum) < abs(target - closest))
                        closest = curSum;

                    if (curSum > target) third--;
                    else second++;
                }
            }
            return closest;
        }

        //454. 4Sum II
        int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
            unordered_map<int, int> record;
            for (auto i : C)
                for (auto j : D)
                    record[i + j]++;

            int res = 0;
            for (auto i : A)
                for (auto j : B)
                    if (record.find(-i - j) != record.end())
                        res += record[-i - j];
            return res;
        }

        //447. Number of Boomerangs
        int numberOfBoomerangs(vector<pair<int, int>> &points) {
            int res = 0;
            for (int i = 0; i < points.size(); i++) {
                unordered_map<int, int> record;
                for (int j = 0; j < points.size(); j++) {
                    if (i != j) {
                        auto dis = (points[i].first - points[j].first) * (points[i].first - points[j].first) +
                                   (points[i].second - points[j].second) * (points[i].second - points[j].second);
                        record[dis]++;
                    }
                }
                for (auto r : record) {
                    res += r.second * (r.second - 1);
                }
            }
            return res;
        }

        //219. Contains Duplicate II
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            if (nums.size() < 2) return false;
            unordered_set<int> record;

            for (int i = 0; i < nums.size(); i++) {
                if (record.find(nums[i]) != record.end())
                    return true;
                record.insert(nums[i]);
                if (record.size() == k + 1)
                    record.erase(nums[i-k]);
            }
            return false;
        }

        //220. Contains Duplicate III
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            if (nums.size() < 2) return false;
            set<long long> record;

            for (int i = 0; i < nums.size(); i++) {
                if (record.lower_bound((long long)nums[i] - (long long)t) != record.end()
                    && *record.lower_bound((long long)nums[i] - (long long)nums[i] + (long long)t))
                    return true;
                record.insert((long long)nums[i]);
                if (record.size() == (k + 1))
                    record.erase(nums[i - k]);
            }
            return false;
        }


    private:
        int eachNumberSquareSum(int n) {
            int sum = 0;
            while (n != 0) {
                int number = n % 10;
                sum += number * number;
                n = n / 10;
            }
            return sum;
        }
    };
}
