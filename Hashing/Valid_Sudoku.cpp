/*
------------------------------------------------------------
Problem : Valid Sudoku (LeetCode 36)
Pattern : Hashing / Frequency Tracking

Time Complexity : O(1) for 9 × 9 Sudoku
Space Complexity : O(1)

Idea:
- Maintain three lookup tables to track whether each digit
  has already appeared:
    1. rows[r][val]   → digit in row r
    2. cols[c][val]   → digit in column c
    3. boxes[b][val]  → digit in 3 × 3 box b
- Traverse every cell of the board.
- Ignore empty cells represented by '.'.
- Convert each digit from '1'...'9' into an index 0...8.
- Calculate the corresponding 3 × 3 box using:
      box_idx = (r / 3) * 3 + (c / 3)
- If the digit already exists in its row, column, or box,
  the Sudoku configuration is invalid.
- Otherwise, mark the digit as seen in all three structures.

Key Insight:
A valid Sudoku requires every digit to appear at most once
in its row, column, and 3 × 3 box. Tracking these three
constraints simultaneously allows the board to be validated
in a single traversal.

------------------------------------------------------------
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int val = board[r][c] - '1';
                    int box_idx = (r / 3) * 3 + (c / 3);
                    if (rows[r][val] || cols[c][val] || boxes[box_idx][val]) {
                        return false;
                    }
                    rows[r][val] = 1;
                    cols[c][val] = 1;
                    boxes[box_idx][val] = 1;
                }
            }
        }
        
        return true;
    }
};