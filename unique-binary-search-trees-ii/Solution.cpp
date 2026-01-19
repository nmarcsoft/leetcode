#include "Solution.hpp"
#include <cstddef>
#include <vector>

/*
 * Given an integer n, return all the structurally unique BST's
 * (binary search trees), which has exactly n nodes of unique values from 1 to n.
 * Return the answer in any order.
 */

TreeNode * generateAllTree(int head_number, int max) {

    auto *root = new TreeNode(head_number);

    if (head_number == 0)
        return nullptr;

    if (head_number > max)
        return nullptr;

    while (head_number != max) {

        root->left = generateAllTree(head_number - 1, max);
        root->right = generateAllTree(head_number, max);
        head_number = head_number - 1;

    }
    return root;
}


vector<TreeNode *> Solution::generateTrees(int x) {

    vector<TreeNode *> toReturn;
    for (int i = 1; i <= x; i++) {
        toReturn.push_back(generateAllTree(i, x));
    }

    return toReturn;
}
