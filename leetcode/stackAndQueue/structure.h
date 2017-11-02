//
// Created by shucheng on 17-11-1.
//

#ifndef ALGORITHM_STRUCTURE_H
#define ALGORITHM_STRUCTURE_H

#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Command {
    string s;
    TreeNode *node;

    Command(string s, TreeNode *node) : s(s), node(node) {}
};

#endif //ALGORITHM_STRUCTURE_H
