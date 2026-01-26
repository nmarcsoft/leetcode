#include <algorithm>
#include <assert.h>
#include <atomic>
#include <cctype>
#include <iostream>
#include <map>
#include <ostream>

using namespace std;

class Solution {

    std::map<int, char> converter;

  public:
    string intToRoman(int num) {

        string toReturn;

        converter[1] = 'I';
        converter[5] = 'V';
        converter[10] = 'X';
        converter[50] = 'L';
        converter[100] = 'C';
        converter[500] = 'D';
        converter[1000] = 'M';

        while (num > 0) {

            if (num == 4) {
                toReturn.push_back('I');
                toReturn.push_back('V');
                num -= 4;
            } else if (num == 9) {
                toReturn.push_back('I');
                toReturn.push_back('X');
                num -= 9;
            } else if (num >= 40 && num < 50) {
                toReturn.push_back('X');
                toReturn.push_back('L');
                num -= 40;
            } else if (num >= 90 && num < 100) {
                toReturn.push_back('X');
                toReturn.push_back('C');
                num -= 90;
            } else if (num >= 400 && num < 500) {
                toReturn.push_back('C');
                toReturn.push_back('D');
                num -= 400;
            } else if (num >= 900 && num < 1000) {
                toReturn.push_back('C');
                toReturn.push_back('M');
                num -= 900;
            } else {
                if (num >= 1000) {
                    toReturn.push_back(converter[1000]);
                    num -= 1000;
                } else if (num >= 500) {
                    toReturn.push_back(converter[500]);
                    num -= 500;
                } else if (num >= 100) {
                    toReturn.push_back(converter[100]);
                    num -= 100;
                } else if (num >= 50) {
                    toReturn.push_back(converter[50]);
                    num -= 50;
                } else if (num >= 10) {
                    toReturn.push_back(converter[10]);
                    num -= 10;
                } else if (num >= 5) {
                    toReturn.push_back(converter[5]);
                    num -= 5;
                } else if (num >= 1) {
                    toReturn.push_back(converter[1]);
                    num -= 1;
                }
            }
        }

        // std::reverse(toReturn.begin(), toReturn.end());
        return toReturn;
    }
};

int main(int argc, char *argv[]) {
    Solution a;

    cout << a.intToRoman(58) << endl;
    cout << a.intToRoman(1994) << endl;

    return 0;
}
