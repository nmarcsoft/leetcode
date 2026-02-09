#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string countAndSayProcess(int n, string &init) {
    int i = 0;
    int counter = 0;
    string next_step = "";
    while (i < init.size()) {
      char checker = init[i];
      counter = 0;
      while (i < init.size() && checker == init[i]) {
        i++;
        counter++;
      }
      string toAdd = std::to_string(counter);
      next_step += toAdd;
      next_step.push_back(checker);
    }

    return next_step;
  };

  string countAndSay(int n) {
    string init = "1";

    for (int i = 1; i < n; i++) {
      init = countAndSayProcess(n, init);
    }

    return init;
  }
};

int main(void) {

  Solution sol;

  cout << sol.countAndSay(4) << endl;

  return 0;
}
