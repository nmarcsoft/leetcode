#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
  bool isColumnValid(vector<vector<char>> &board, int index) {

    char already[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (unsigned int i = 0; i < 9; i++) {
      if (board[i][index] != '.') {
        if (already[board[i][index] - 48] > 0) {
          return false;
        }
        already[board[i][index] - 48]++;
      }
    }

    return true;
  }

  bool isLineValid(vector<vector<char>> &board, int index) {

    char already[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (unsigned int i = 0; i < 9; i++) {
      if (board[index][i] != '.') {
        if (already[board[index][i] - 48] > 0) {
          return false;
        }
        already[board[index][i] - 48]++;
      }
    }

    return true;
  }

  bool isSquareValid(vector<vector<char>> &board, int index) {

    char already[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    unsigned int borne_min_ligne = (index * 3) % 6;
    unsigned int borne_min_column = (index * 3) % 6;

    unsigned int multiplicator = index / 3;
    borne_min_column *= multiplicator;
    borne_min_ligne *= multiplicator;

    for (unsigned int i = borne_min_ligne; i < borne_min_ligne + 3; i++) {
      for (unsigned int j = borne_min_column; j < borne_min_column + 3; j++) {
        if (board[i][j] != '.') {
          if (already[board[i][j] - 48] > 0) {
            return false;
          } else
            already[board[i][j] - 48]++;
        }
      }
    }

    return true;
  }

public:
  bool isValidSudoku(vector<vector<char>> &board) {
    // Check all colum
    for (int i = 0; i < 9; i++) {
      if (!isColumnValid(board, i))
        return false;
    }

    for (int i = 0; i < 9; i++) {
      if (!isLineValid(board, i))
        return false;
    }

    for (int i = 0; i < 9; i++) {
      if (!isSquareValid(board, i))
        return false;
    }
    return true;
  }
};

int main(void) {

  vector<vector<char>> input = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  Solution sol;

  cout << sol.isValidSudoku(input) << endl;
  return 0;
}
