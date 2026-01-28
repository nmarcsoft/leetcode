#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    bool triple_zero = false;

    bool noAlreadyIn(vector<vector<int>> result, vector<int> add) {
        int cpt = 0;
        for (auto &it : result) {
            cpt = 0;
            for (vector<int>::size_type i = 0; i < add.size(); i++) {

                if (find(it.begin(), it.end(), add[i]) != it.end()) {
                    cpt++;
                }
            }
            if (cpt == 3)
                return false;
        }

        return true;
    };

  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> toReturn;

        for (vector<int>::size_type i = 0; i < nums.size(); i++) {

            for (vector<int>::size_type j = i + 1; j < nums.size(); j++) {

                for (vector<int>::size_type k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> toAdd = {nums[i], nums[j], nums[k]};
                        if (noAlreadyIn(toReturn, toAdd)) {
                            toReturn.push_back(toAdd);
                        }
                    }
                }
            }
        }

        return toReturn;
    }

    void printer(vector<vector<int>> input) {

        cout << "[";

        for (vector<vector<int>>::size_type i = 0; i < input.size(); i++) {
            cout << "[";
            for (vector<int>::size_type j = 0; j < input[i].size(); j++) {
                cout << input[i][j];
                if (j != input[i].size())
                    cout << ",";
            }
            cout << "]";
        }
        cout << "]";
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
    Solution a;
    vector<vector<int>> result = a.threeSum(nums);
    a.printer(result);

    return 0;
}
