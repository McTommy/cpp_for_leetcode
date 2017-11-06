//
// Created by shucheng on 17-11-1.
//
#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cassert>

#include "../stackAndQueue/structure.h"

using namespace std;

namespace recursionAndTree {
    class Solution {
    private:
        vector<string> res;
        const string letterMap[10] = {
                " ",
                "",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz",
        };

        bool isSymmetricHelper(TreeNode *p, TreeNode *q) {
            if (!p and !q)
                return true;
            else if (!p or !q)
                return false;
            if (p->val != q->val)
                return false;

            return isSymmetricHelper(p->left, q->right) and isSymmetricHelper(p->right, q->left);
        }

        int binaryTreeDepth(TreeNode *root) {
            if (!root) return 0;
            int l = 1, r = 1;
            l += binaryTreeDepth(root->left);
            r += binaryTreeDepth(root->right);
            return l > r ? l : r;
        }

        void isPathSum(TreeNode *node, int sum, vector<int> &path, vector<vector<int>> &paths) {
            if (!node) return;
            path.push_back(node->val);
            if (!node->left and !node->right and node->val == sum)
                paths.push_back(path);
            isPathSum(node->left, sum - node->val, path, paths);
            isPathSum(node->right, sum - node->val, path, paths);
            path.pop_back();
        }

        int findPath(TreeNode *node, int sum) {
            if (!node) return 0;
            int res = 0;

            if (node->val == sum) res += 1;
            res += findPath(node->left, sum - node->val);
            res += findPath(node->right, sum - node->val);
            return res;
        }

        bool isValidBST(TreeNode *node, TreeNode *minNode, TreeNode *maxNode) {
            if (!node) return true;
            if (minNode && node->val <= minNode->val || maxNode && node->val >= maxNode->val)
                return false;
            return isValidBST(node->left, minNode, node) && isValidBST(node->right, node, maxNode);
        }

        void findComb(const string &digits, int index, const string &s) {

            if (index == digits.size()) {
                res.push_back(s);
                return;
            }
            char c = digits[index];
            string letters = letterMap[c - '0'];
            for (auto i : letters) {
                findComb(digits, index + 1, s + i);
            }
        }

        void findPermutation(vector<int> nums, int index, int k, vector<vector<int>> &res) {
            if (index == k - 1) {
                res.push_back(nums);
                return;
            }
            for (int i = index; i < k; i++) {
                if (i != index && nums[i] == nums[index]) continue;
                swap(nums[i], nums[index]);
                findPermutation(nums, index + 1, k, res);
            }
        }

        void findPartition(string &s, int index, vector<string> &p, vector<vector<string>> &res) {
            if (index == s.length()) {
                res.push_back(p);
                return;
            }
            for (int i = index; i < s.length(); i++) {
                if (isPalindrome(s, index, i)) {
                    p.push_back(s.substr(index, i - index + 1));
                    findPartition(s, i + 1, p, res);
                    p.pop_back();
                }
            }
        }
        bool isPalindrome(const string &s, int begin, int end) {
            while(begin < end)
                if (s[begin++] != s[end--])
                    return false;
            return true;
        }

    public:
        int maxDepth(TreeNode *root) {
            if (root == nullptr)
                return 0;

            int leftMax = maxDepth(root->left);
            int rightMax = maxDepth(root->right);

            return max(leftMax, rightMax) + 1;
        }

        int minDepth(TreeNode *root) {
            if (!root) return 0;
            if (!root->left) return 1 + minDepth(root->right);
            if (!root->right) return 1 + minDepth(root->left);
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }

        TreeNode *invertTree(TreeNode *root) {
            if (root == nullptr)
                return root;

            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);

            return root;
        }

        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p == nullptr and q == nullptr)
                return true;

            if ((p == nullptr and q != nullptr) or (p != nullptr and q == nullptr) or (p->val != q->val))
                return false;

            return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        }

        bool isSymmetric(TreeNode *root) {
            if (!root)
                return true;
            return isSymmetricHelper(root->left, root->right);
        }

        bool isSymmetric2(TreeNode *root) {
            if (!root) return true;
            queue<TreeNode *> leftQ;
            queue<TreeNode *> rightQ;

            leftQ.push(root->left);
            rightQ.push(root->right);

            while (!leftQ.empty() and !rightQ.empty()) {
                TreeNode *left = leftQ.front();
                TreeNode *right = rightQ.front();

                leftQ.pop();
                rightQ.pop();

                if (!left && !right)
                    continue;
                if (!left || !right)
                    return false;

                if (left->val != right->val)
                    return false;

                leftQ.push(left->left);
                leftQ.push(left->right);
                rightQ.push(right->right);
                rightQ.push(right->left);
            }
            return true;
        }

        int countNodes(TreeNode *root) {
            if (!root) return 0;
            int hl = 0, hr = 0;
            TreeNode *l = root, *r = root;

            while (l) {
                hl++;
                l = l->left;
            }
            while (r) {
                hr++;
                r = r->right;
            }
            if (hl == hr) return static_cast<int>(pow(2, hl) - 1);

            return 1 + countNodes(root->left) + countNodes(root->right);
        }

        bool isBalanced(TreeNode *root) {
            if (!root) return true;

            int depthL, depthR;
            depthL = binaryTreeDepth(root->left);
            depthR = binaryTreeDepth(root->right);
            if (abs(depthL - depthR) > 1) return false;

            return isBalanced(root->left) && isBalanced(root->right);
        }

        bool hasPathSum(TreeNode *root, int sum) {
            if (!root) return false;
            if (root->val == sum and !root->left and !root->right)
                return true;
            if (root->val != sum and !root->left and !root->right)
                return false;

            sum -= root->val;
            return hasPathSum(root->left, sum) or hasPathSum(root->right, sum);
        }

        int sumOfLeftLeaves(TreeNode *root) {
            if (!root) return 0;
            if (root->left and !root->left->left and !root->left->right)
                return root->left->val + sumOfLeftLeaves(root->right);
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }

        vector<string> binaryTreePaths(TreeNode *root) {
            vector<string> res;

            if (!root) return res;

            if (!root->left and !root->right) {
                res.push_back(to_string(root->val));
                return res;
            }

            vector<string> leftS = binaryTreePaths(root->left);
            for (string i : leftS) {
                res.push_back(to_string(root->val) + "->" + i);
            }

            vector<string> rightS = binaryTreePaths(root->right);
            for (string i : rightS) {
                res.push_back(to_string(root->val) + "->" + i);
            }
            return res;
        }

        vector<vector<int>> pathSum(TreeNode *root, int sum) {
            vector<vector<int>> res;
            vector<int> path;
            isPathSum(root, sum, path, res);
            return res;
        }

        vector<vector<int>> pathSumByQueue(TreeNode *root, int sum) {
            vector<vector<int>> res;
            if (!root)
                return res;

            queue<pair<TreeNode *, vector<int>>> q;

            vector<int> vec;
            vec.push_back(root->val);
            q.push(make_pair(root, vec));

            while (!q.empty()) {
                TreeNode *cur = q.front().first;
                vector<int> numL = q.front().second, numR = q.front().second;

                q.pop();
                if (!cur->left and !cur->right and sum == accumulate(numL.begin(), numL.end(), 0))
                    res.push_back(numL);

                if (cur->left) {
                    numL.push_back(cur->left->val);
                    q.push(make_pair(cur->left, numL));
                }
                if (cur->right) {
                    numR.push_back(cur->right->val);
                    q.push(make_pair(cur->right, numR));
                }

            }
            return res;
        }

        int sumNumbers(TreeNode *root) {
            if (!root) return 0;
            int res = 0;

            queue<pair<TreeNode *, int>> q;
            q.push(make_pair(root, root->val));
            while (!q.empty()) {
                TreeNode *node = q.front().first;
                int value = q.front().second;
                q.pop();

                if (!node->left and !node->right)
                    res += value;
                if (node->left) q.push(make_pair(node->left, node->left->val + value * 10));
                if (node->right) q.push(make_pair(node->right, node->right->val + value * 10));

            }
            return res;
        }

        int pathSum3(TreeNode *root, int sum) {
            if (!root) return 0;
            int res = findPath(root, sum);
            res += pathSum3(root->left, sum);
            res += pathSum3(root->right, sum);
            return res;
        }

        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
            if (!root) return root;

            if (p->val < root->val and q->val < root->val)
                return lowestCommonAncestor(root->left, p, q);
            if (p->val > root->val and q->val > root->val)
                return lowestCommonAncestor(root->right, p, q);

            return root;
        }

        bool isValidBST(TreeNode *root) {
            return isValidBST(root, nullptr, nullptr);
        }

        TreeNode *deleteNode(TreeNode *root, int key) {
            if (!root) return root;
            if (root->val == key) {
                if (!root->right) {
                    TreeNode *left = root->left;
                    delete root;
                    return left;
                } else {
                    TreeNode *right = root->right;
                    while (right->left)
                        right = right->left;
                    swap(right->val, root->val);
                }
            }
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
            return root;
        }

        TreeNode *sortedArrayToBST(vector<int> &nums) {
            if (nums.empty()) return nullptr;
            if (nums.size() == 1) return new TreeNode(nums[0]);

            int middle = nums.size() / 2;
            auto *root = new TreeNode(nums[middle]);

            vector<int> left(nums.begin(), nums.begin() + middle);
            vector<int> right(nums.begin() + middle + 1, nums.end());

            root->left = sortedArrayToBST(left);
            root->right = sortedArrayToBST(right);

            return root;
        }

        int kthSmallest(TreeNode *root, int k) {
            stack<TreeNode *> stack1;

            TreeNode *p = root;
            while (p || !stack1.empty()) {
                while (p) {
                    stack1.push(p);
                    p = p->left;
                }
                p = stack1.top();
                if (k - 1 == 0)
                    return p->val;
                stack1.pop();
                k--;
                p = p->right;
            }
        }

        vector<string> letterCombinations(string digits) {
            res.clear();
            if (digits.empty())
                return res;
            findComb(digits, 0, "");
            return res;
        }

        vector<vector<int>> permuteUnique(vector<int> &nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            if (nums.empty())
                return res;
            findPermutation(nums, 0, nums.size(), res);
            return res;
        }

        vector<string> restoreIpAddresses(string s) {
            vector<string> res;
            string ans;
            for (int a = 1; a <= 3; a++)
                for (int b = 1; b <= 3; b++)
                    for (int c = 1; c <= 3; c++)
                        for (int d = 1; d <= 3; d++)
                            if (a + b + c + d == s.length()) {
                                int A = stoi(s.substr(0, a));
                                int B = stoi(s.substr(a, b));
                                int C = stoi(s.substr(a + b, c));
                                int D = stoi(s.substr(a + b + c, d));
                                if (A <= 255 && B <= 255 && C <= 255 && D <= 255)
                                    if ((ans = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." +
                                               to_string(D)).length() == s.length() + 3)
                                        res.push_back(ans);
                            }
            return res;
        }

        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> p;
            if (s.empty()) return res;
            findPartition(s, 0, p, res);
            return res;
        }
    };
}