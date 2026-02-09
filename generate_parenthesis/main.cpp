#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> generateParenthesisRec(vector<string> &toReturn, int open,
                                        int close, int n, string current) {

    if (open == close && open + close == n * 2) {
      toReturn.push_back(current);
    }

    if (open < n) {
      generateParenthesisRec(toReturn, open + 1, close, n, current + "(");
    }

    if (close < open) {
      generateParenthesisRec(toReturn, open, close + 1, n, current + ")");
    }

    return toReturn;
  }

public:
  vector<string> generateParenthesis(int n) {

    vector<string> toReturn;

    generateParenthesisRec(toReturn, 0, 0, n, "");

    return toReturn;
  }
};

void debug(vector<string> &toPrint) {

  for (string &it : toPrint) {
    cout << it << endl;
  }
}

int main(void) {
  Solution sol;
  vector<string> toPrint = sol.generateParenthesis(2);
  debug(toPrint);
  return 0;
}
