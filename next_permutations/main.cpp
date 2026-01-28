#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {

    if (nums.size() == 1) {
      return;
    }

    unsigned int index_k = -1;
    unsigned int index_l = -1;

    for (vector<int>::size_type i = 0; i < nums.size() - 1; i++) {

      if (nums[i] < nums[i + 1]) {
        index_k = i;
      }
    }
    cout << "Index k = " << index_k << endl;

    if (index_k != -1 && nums.size() == 2) {
      swap(nums[0], nums[1]);
      return;
    }

    if (index_k == -1) {
      sort(nums.begin(), nums.end());
      return;
    }

    for (vector<int>::size_type i = index_k; i < nums.size(); i++) {

      if (nums[index_k] < nums[i]) {
        index_l = i;
      }
    }

    swap(nums[index_k], nums[index_l]);
    reverse(nums.begin() + index_k + 1, nums.end());

    cout << "Index l = " << index_l << endl;
  };

  void printer(vector<int> input) {
    for (auto &number : input) {
      cout << number;
      if (&number != &input.back()) {
        cout << ", ";
      }
    }
    cout << endl;
  }
};

// [ 1, 5, 3, 7] = [ 1 5 7 3] [1 7 3 5 ]
int main(void) {
  vector<int> input_one = {1, 3, 2};
  Solution a;
  a.nextPermutation(input_one);
  a.printer(input_one);
}
