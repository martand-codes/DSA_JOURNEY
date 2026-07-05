// Problem: Word Search (LeetCode 79)
// Pattern: Grid Backtracking + DFS
// TC: O(m × n × 4^L)
// SC: O(L)
//
// Idea:
// Try every cell as a starting point.
// Match characters recursively.
// Mark visited cells temporarily.
// Explore 4 directions.
// Restore the board during backtracking.

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int column = board[0].size();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < column; c++) {
                if (helper(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, string& word, int row, int column, int index ) {
        // Base Cases:

        if(index == word.size()) {
            return true; // Answer Case
        }
        if(row < 0 || column < 0) {
            return false; // Checking for negative index
        }
        if(row >= board.size() || column >= board[0].size()) {
            return false; // Out of Bound
        }
        if (board[row][column] != word[index]) {
            return false; // For word not matching
        }

        char temp = board[row][column];
        board[row][column] = '*';

        bool found = helper(board, word, row, column + 1, index + 1) ||
                     helper(board, word, row + 1, column, index + 1) ||
                     helper(board, word, row - 1, column, index + 1) ||
                     helper(board, word, row, column - 1, index + 1) ;

        board[row][column] = temp; // BackTracking

        return found;
    }

};