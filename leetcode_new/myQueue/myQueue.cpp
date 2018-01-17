//
// Created by shucheng on 17-10-30.
//
#include <stack>
#include <iostream>
#include <string>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

#include "functional"
#include "../myList/LinkedListStructure.h"
#include "structure.h"

using namespace std;

namespace myQueue {
    class Solution {
    private:
        void rightSideViewRecursion(TreeNode *node, int level, vector<int> &res) {
            if (!node) return;
            if (res.size() < level) res.push_back(node->val);
            rightSideViewRecursion(node->right, level + 1, res);
            rightSideViewRecursion(node->left, level + 1, res);
        }

    public:
        //20. Valid Parentheses
        bool isValid(string s) {
            stack<char> record;

            for (auto i : s) {
                if (i == '{' || i == '[' || i == '(')
                    record.push(i);
                else {
                    if (record.empty()) return false;
                    char temp = record.top();
                    if ((temp == '[' && i == ']') || (temp == '{' && i == '}') || (temp == '(' && i == ')'))
                        record.pop();
                    else
                        return false;
                }
            }
            return record.empty();
        }

        //150. Evaluate Reverse Polish Notation
        int evalRPN(vector<string> &tokens) {
            stack<int> record;

            for (auto i : tokens) {
                if (i == "+" || i == "-" || i == "*" || i == "/") {
                    int second = record.top();
                    record.pop();
                    int first = record.top();
                    record.pop();
                    int temp;
                    if (i == "+") temp = first + second;
                    else if (i == "-") temp = first - second;
                    else if (i == "*") temp = first * second;
                    else temp = first / second;
                    record.push(temp);
                } else {
                    int val = std::stoi(i);
                    record.push(val);
                }
            }
            int result = record.top();
            record.pop();
            return result;
        }

        //71. Simplify Path
        string simplifyPath(string path) {
            string res, tmp;
            vector<string> stk;
            stringstream ss(path);
            while (getline(ss, tmp, '/')) {
                if (tmp == "" or tmp == ".") continue;
                if (tmp == ".." and !stk.empty()) stk.pop_back();
                else if (tmp != "..") stk.push_back(tmp);
            }
            for (auto str : stk) res += "/" + str;
            return res.empty() ? "/" : res;
        }

        //二叉树深度遍历
        //144. Binary Tree Preorder Traversal
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;
            if (root == nullptr) return res;
            stack<Command> commandStack;

            commandStack.push(Command("go", root));
            while (!commandStack.empty()) {
                Command command = commandStack.top();
                commandStack.pop();
                if (command.s == "print")
                    res.push_back(command.node->val);
                else {
                    if (command.node->right)
                        commandStack.push(Command("go", command.node->right));
                    if (command.node->left)
                        commandStack.push(Command("go", command.node->left));
                    commandStack.push(Command("print", command.node));
                }
            }
            return res;
        }

        //102. Binary Tree Level Order Traversal
        vector<vector<int>> levelOrder(TreeNode *root) {
            vector<vector<int>> result;
            if (!root) return result;

            queue<pair<TreeNode *, int>> record;
            record.push(make_pair(root, 0));
            while (!record.empty()) {
                TreeNode *node = record.front().first;
                int level = record.front().second;
                record.pop();
                if (level == result.size())
                    result.emplace_back();
                result[level].push_back(node->val);
                if (node->left)
                    record.push(make_pair(node->left, level + 1));
                if (node->right)
                    record.push(make_pair(node->right, level + 1));
            }
            return result;
        }

        //107. Binary Tree Level Order Traversal II
        vector<vector<int>> levelOrderBottom(TreeNode *root) {
            vector<vector<int>> result;
            if (!root) return result;

            queue<pair<TreeNode *, int>> record;
            record.push(make_pair(root, 0));
            while (!record.empty()) {
                TreeNode *node = record.front().first;
                int level = record.front().second;
                record.pop();
                if (level == result.size())
                    result.emplace_back();
                result[level].push_back(node->val);
                if (node->left)
                    record.push(make_pair(node->left, level + 1));
                if (node->right)
                    record.push(make_pair(node->right, level + 1));
            }
            reverse(result.begin(), result.end());
            return result;
        }

        //103. Binary Tree Zigzag Level Order Traversal
        vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
            vector<vector<int>> result;
            if (!root) return result;

            queue<TreeNode *> record;
            record.push(root);
            bool leftToRight = true;
            while (!record.empty()) {
                int size = record.size();
                vector<int> row(size);
                for (int i = 0; i < size; i++) {
                    TreeNode *node = record.front();
                    record.pop();

                    int place = leftToRight ? i : (size - i - 1);
                    row[place] = node->val;
                    if (node->left)
                        record.push(node->left);
                    if (node->right)
                        record.push(node->right);
                }
                leftToRight = !leftToRight;
                result.push_back(row);
            }
            return result;
        }

        //199. Binary Tree Right Side View
        vector<int> rightSideView(TreeNode *root) {
            vector<int> res;
            rightSideViewRecursion(root, 1, res);
            return res;
        }

        //279. Perfect Squares
        int numSquares1(int n) {
            vector<int> record(n + 1, INT_MAX);
            record[0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j * j <= i; j++) {
                    record[i] = min(record[i], record[i - j * j] + 1);
                }
            }
            return record[n];
        }
        int numSquares2(int n) {
            queue<pair<int, int>> record;
            record.push(make_pair(n, 0));

            vector<bool> visited(n + 1, false);
            visited[n] = true;

            while (!record.empty()) {
                int num = record.front().first;
                int step = record.front().second;
                record.pop();

                if (num == 0) return step;
                for (int i = 1; i * i <= num; i++)
                    if (!visited[num - i * i]) {
                        record.push(make_pair(num - i * i, step + 1));
                        visited[num - i * i] = true;
                    }
            }
        }

        //347. Top K Frequent Elements
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> record;
            for (auto i : nums)
                record[i]++;

            priority_queue<pair<int, int>> pq;
            for (auto j : record)
                pq.push(make_pair(j.second, j.first));

            vector<int> result;
            while (k--) {
                result.push_back(pq.top().second);
                pq.pop();
            }
            return result;
        }

    };
};
