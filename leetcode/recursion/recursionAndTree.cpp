//
// Created by shucheng on 17-11-1.
//
#include <iostream>
#include <queue>
#include <cmath>
#include <numeric>

#include "../stackAndQueue/structure.h"

using namespace std;

namespace recursionAndTree {
    class Solution {
    private:
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

        }
    };
}