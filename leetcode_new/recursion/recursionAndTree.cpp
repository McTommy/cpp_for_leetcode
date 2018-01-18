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

#include "../myQueue/structure.h"

using namespace std;

namespace recursionAndTree {
    class Solution {
    public:
        //104. Maximum Depth of Binary Tree
        int maxDepth(TreeNode* root) {
            if (root == nullptr) return 0;

            return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
        }

        //111. Minimum Depth of Binary Tree
        int minDepth(TreeNode* root) {
            if (!root) return 0;
            if (!root->left) return 1 + minDepth(root->right);
            if (!root->right) return 1 + minDepth(root->left);
            return min(minDepth(root->left) + 1, minDepth(root->right) + 1);
        }

        //226. Invert Binary Tree
        TreeNode* invertTree(TreeNode* root) {
            if (!root) return root;
            TreeNode *temp = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(temp);
            return root;
        }

        //100. Same Tree
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (!q && !p) return true;
            if ((!q && p) || (q && !p)) return false;
            if (p->val != q->val) return false;
            return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        }

        //
        //101. Symmetric Tree
        bool isSymmetric(TreeNode* root) {

        }

        //222. Count Complete Tree Nodes
        int countNodes(TreeNode* root) {

        }

        //110. Balanced Binary Tree
        bool isBalanced(TreeNode* root) {

        }

        //112. Path Sum
        bool hasPathSum(TreeNode* root, int sum) {

        }
    };
}