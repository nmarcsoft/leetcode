#include <vector>

using namespace std;

class Solution {
  public:
    bool isOneBitCharacter(vector<int> &bits) {
        vector<int>::size_type i = 0;
        vector<int>::size_type size = bits.size();

        while (i < size) {

            if (bits[i] == 0) {
                i++;
            } else {
                i += 2;
            }

            if (i == (size - 1))
                return !bits[i];
        }
        return false;
    }
};

int main(void) {}
