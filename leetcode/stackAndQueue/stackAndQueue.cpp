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

#include "functional"
#include "../list/LinkedListStructure.h"
#include "structure.h"

using namespace std;

namespace stackAndQueue {
    class Solution {
    private:
        bool static myCmp(int a, int b) {
            return a % 10 > b % 10;
        }

        bool static LinkedListCmp(ListNode *l, ListNode *r) {
            return l->val > r->val;
        }

    public:

        bool isValid(string s) {
            stack<char> stack;
            for (char i : s) {
                if (i == '(' || i == '[' || i == '{')
                    stack.push(i);
                else {
                    if (stack.empty())
                        return false;

                    char c = stack.top();
                    stack.pop();

                    char match = NULL;
                    switch (i) {
                        case ')':
                            match = '(';
                            break;
                        case '}':
                            match = '{';
                            break;
                        case ']':
                            match = '[';
                            break;
                        default:
                            break;
                    }

                    if (c != match)
                        return false;
                }
            }
            return stack.empty();
        }

        int evalRPN(vector<string> &tokens) {
            unordered_map<string, function<int(int, int)>> map = {
                    {"+", [](int a, int b) { return a + b; }},
                    {"-", [](int a, int b) { return a - b; }},
                    {"*", [](int a, int b) { return a * b; }},
                    {"/", [](int a, int b) { return a / b; }},
            };
            stack<int> stack;
            for (string &s : tokens) {
                if (!map.count(s)) {
                    stack.push(stoi(s));
                } else {
                    int op1 = stack.top();
                    stack.pop();
                    int op2 = stack.top();
                    stack.pop();
                    stack.push(map[s](op2, op1));
                }
            }
            return stack.top();
        }

        string simplifyPath(string path) {
            string res, tmp;
            vector<string> stk;
            stringstream ss(path);
            while (getline(ss, tmp, '/')) {
                if (tmp.empty() or tmp == ".") continue;
                if (tmp == ".." and !stk.empty()) stk.pop_back();
                else if (tmp != "..") stk.push_back(tmp);
            }

            for (string i : stk)
                res += "/" + i;

            return stk.empty() ? "/" : res;
        }

        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> res;
            if (root == nullptr)
                return res;

            stack<Command> stack;
            stack.push(Command("go", root));
            while (!stack.empty()) {
                Command command = stack.top();
                stack.pop();

                if (command.s == "print")
                    res.push_back(command.node->val);
                else {
                    assert(command.s == "go");
                    stack.push(Command("print", command.node));
                    if (command.node->right)
                        stack.push(Command("go", command.node->right));
                    if (command.node->left)
                        stack.push(Command("go", command.node->left));
                }
            }
            return res;

        }

        vector<vector<int>> levelOrderBottom(TreeNode *root) {
            vector<vector<int>> res;
            if (root == nullptr)
                return res;

            queue<pair<TreeNode *, int>> q;
            q.push(make_pair(root, 0));
            while (!q.empty()) {
                TreeNode *node = q.front().first;
                int level = q.front().second;
                q.pop();

                if (level == res.size())
                    res.emplace_back();
                res[level].push_back(node->val);

                if (node->left)
                    q.push(make_pair(node->left, level + 1));
                if (node->right)
                    q.push(make_pair(node->right, level + 1));
            }
            return vector<vector<int>>(res.rbegin(), res.rend());
        }

        vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
            vector<vector<int>> res;
            if (root == nullptr)
                return res;

            bool leftToRight = true;
            queue<TreeNode *> q;
            q.push(root);
            while (!q.empty()) {
                int size = q.size();
                vector<int> row(size);
                for (int i = 0; i < size; i++) {
                    TreeNode *now = q.front();
                    q.pop();
                    int number = leftToRight ? i : size - 1 - i;
                    row[number] = now->val;

                    if (now->left)
                        q.push(now->left);
                    if (now->right)
                        q.push(now->right);
                }
                leftToRight = !leftToRight;
                res.push_back(row);
            }
            return res;
        }

        int numSquares(int n) {
            queue<pair<int, int>> q;
            q.push(make_pair(n, 0));

            vector<bool> visited(static_cast<unsigned long>(n + 1), false);
            visited[n] = true;
            while (!q.empty()) {
                int num = q.front().first;
                int step = q.front().second;
                q.pop();
                if (num == 0)
                    return step;
                for (int i = 1; num - i * i >= 0; i++)
                    if (!visited[num - i * i]) {
                        q.push(make_pair(num - i * i, step + 1));
                        visited[num - i * i] = true;
                    }
            }
        }

        int ladderLength(string beginWord, string endWord, unordered_set<string> &wordDict) {
            unordered_set<string> head, tail, *phead, *ptail;
            head.insert(beginWord);
            tail.insert(endWord);
            int dist = 2;
            while (!head.empty() && !tail.empty()) {
                if (head.size() < tail.size()) {
                    phead = &head;
                    ptail = &tail;
                } else {
                    phead = &tail;
                    ptail = &head;
                }
                unordered_set<string> temp;
                for (auto word : *phead) {
                    wordDict.erase(word);
                    for (int p = 0; p < (int) word.length(); p++) {
                        char letter = word[p];
                        for (int k = 0; k < 26; k++) {
                            word[p] = static_cast<char>('a' + k);
                            if (ptail->find(word) != ptail->end())
                                return dist;
                            if (wordDict.find(word) != wordDict.end()) {
                                temp.insert(word);
                                wordDict.erase(word);
                            }
                        }
                        word[p] = letter;
                    }
                }
                dist++;
                swap(*phead, temp);
            }
            return 0;
        }

        void my_priority_queue() {
            srand(time(NULL));
            priority_queue<int, vector<int>, greater<int>> pq2;
            priority_queue<int, vector<int>, function<bool(int, int)>> pq3(myCmp);
        }

        vector<int> topKFrequent(vector<int> &nums, int k) {
            assert(k > 0);
            unordered_map<int, int> freq;
            for (int i : nums)
                freq[i]++;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            for (auto &iter : freq) {
                if (pq.size() == k) {
                    if (iter.second > pq.top().first) {
                        pq.pop();
                        pq.push(make_pair(iter.second, iter.first));
                    }
                } else
                    pq.push(make_pair(iter.second, iter.first));
            }

            vector<int> res;
            while (!pq.empty()) {
                res.push_back(pq.top().second);
                pq.pop();
            }
            return res;
        }

        ListNode *mergeKLists(vector<ListNode *> &lists) {
            priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(LinkedListCmp);

            for (auto l : lists)
                if (l) pq.push(l);

            if (pq.empty()) return nullptr;

            ListNode *head = pq.top();
            pq.pop();
            if (head->next) pq.push(head->next);
            ListNode *tail = head;
            while (!pq.empty()) {
                tail->next = pq.top();
                pq.pop();
                tail = tail->next;
                if (tail->next) pq.push(tail->next);
            }

            return head;
        }
    };
};
