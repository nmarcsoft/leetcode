#include "Solution.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    Solution Sol;
    vector<TreeNode *> returned = Sol.generateTrees(5);

    for (auto &it : returned) {
        cout << it->val << endl;
    }

    cout << "Hello World" << endl;
}
