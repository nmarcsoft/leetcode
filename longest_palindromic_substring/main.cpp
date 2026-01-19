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

        for (string::size_type i = 0; i < s.size(); i++) {
            current.push_back(s[i]);
            for (string::size_type j = i + 1; j < s.size(); j++) {

                current.push_back(s[j]);

                if (isPalindrome(current)) {
                    if (current.size() > longest.size())
                        longest = current;
                }
            }
            current = "";
        }
        return longest;
    };
};

int main(void) {

    Solution sol;

    cout << "(bab)" << sol.longestPalindrome("babad") << endl;

    return 0;
}
