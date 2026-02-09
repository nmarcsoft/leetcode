#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
  bool isPalindrome(string s) {
    for (string::size_type i = 0; i < s.size() / 2; i++) {
      if (s[i] != s[s.size() - 1 - i]) {
        return 0;
      }
    }
    return 1;
  }

public:
  string longestPalindrome(string s) {

    string current, longest;

    if (s.size() <= 1) {
      return s;
    }
    longest = s[0];

    if (s.size() == 2) {
      if (isPalindrome(s)) {
        return s;
      }
      return longest;
    }
    current = std::string(s.begin(), s.end());
    if (isPalindrome(current))
      return current;

    for (string::size_type end = s.size(); end > 0; end--) {
      for (string::size_type start = 0; start < s.size(); start++) {

        string current = string(s.begin() + start, s.begin() + start + end);

        if (isPalindrome(current)) {
          return current;
        }
      }
    }
    return "";
  };
};

int main(void) {

  Solution sol;

  cout << "(bab)" << sol.longestPalindrome("ttbabad") << endl;

  return 0;
}
