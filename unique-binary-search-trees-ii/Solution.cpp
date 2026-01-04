#include "Solution.hpp"
#include <cstddef>
#include <vector>

/*
 * Given an integer n, return all the structurally unique BST's
 * (binary search trees), which has exactly n nodes of unique values from 1 to n.
 * Return the answer in any order.
 */

TreeNode *generateForReq(TreeNode *parent, int i, int x) {

    if (parent == nullptr)
        return nullptr;

    if (i > x)
        return parent;

    TreeNode head(x);

    if (parent->val < head.val) {
        parent->right = &head;
    } else {
        parent->left = &head;
    }

    generateForReq(&head, i + 1, x);

    return nullptr;
}

vector<TreeNode *> Solution::generateTrees(int x) {

    vector<TreeNode *> toReturn;
    for (int i = 1; i <= x; i++) {
        TreeNode parent(i);

        toReturn.push_back(generateForReq(&parent, i, x));
    }

    return toReturn;
}
