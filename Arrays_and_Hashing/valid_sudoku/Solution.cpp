#include <array>
#include <vector>
#include <unordered_set>
#include <cctype>


class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    bool result = true;
    std::array<std::unordered_set<char>, 9> squares; 
    std::array<std::unordered_set<char>, 9> rows;
    std::array<std::unordered_set<char>, 9> colunms;
    
    int digits_count_rows[9] = {0};
    int digits_count_columns[9] = {0};   
    int digits_count_squares[9] = {0};
    int squares_index = 0;

    for (int j = 0; j < 9; j++) {
      squares_index = (j / 3) * 3;
      for (int i = 0; i < 9; i++) {
        if (std::isdigit(board[j][i])) {
          rows[j].insert(board[j][i]);
          colunms[i].insert(board[j][i]);
          squares[squares_index + i/3].insert(board[j][i]);
          digits_count_rows[j]++;
          digits_count_columns[i]++;
          digits_count_squares[squares_index+i/3]++;
        }
      }
    }
    for (int it = 0; it < 9; it++) {
      if (rows[it].size() != digits_count_rows[it]) {
        return false;
      }
      if (colunms[it].size() != digits_count_columns[it]) {
        return false;
      }
      if (squares[it].size() != digits_count_squares[it]) {
        return false;
      }
    }
    return result;
  }
};
