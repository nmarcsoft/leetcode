#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {

        vector<int>::iterator it;
        it = nums.begin();
        while (it != nums.end()) {
            if (*it == val) {
                nums.erase(it);
            } else {
                it++;
            }
        }

        stable_sort(nums.begin(), nums.end());
        return nums.size();
    }
};

int main(void) {
    Solution runner;

    vector<int> nums = {3, 2, 2, 3};

    runner.removeElement(nums, 3);

    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        cout << *it << endl;
    }
}
