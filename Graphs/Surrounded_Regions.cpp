/*
------------------------------------------------------------
Problem : Surrounded Regions (LeetCode 130)
Pattern : Graph + Reverse DFS (Flood Fill)

Time Complexity : O(R × C)
Space Complexity : O(R × C)   // recursion stack in worst case

Idea:
- Start DFS from all boundary 'O' cells.
- Mark every connected boundary region as safe.
- Flip all remaining 'O' cells to 'X'.
- Restore safe cells back to 'O'.

Key Insight:
Instead of searching for regions to capture,
identify the regions that cannot be captured by
starting from the boundary.
------------------------------------------------------------
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
     int r = board.size();
     int c = board[0].size();

     if(r == 0 || c == 0) {
        return;
     }
     for(int i = 0; i < r; i++) {
        dfsHelper(i, 0, board);
        dfsHelper(i, c - 1, board);
     }
     for(int j = 0; j < c; j++) {
        dfsHelper(0, j, board);
        dfsHelper(r - 1, j, board);
     }
     for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if(board[i][j] == 'S') {
                board[i][j] = 'O';
            }
        }
     }   
    }
    void dfsHelper(int row, int column, vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        if(row < 0 || row >= r || column < 0 || column >= c || board[row][column] != 'O' ) {
            return;
        }
        board[row][column] = 'S'; // It's Safe
        dfsHelper(row + 1, column, board);
        dfsHelper(row - 1, column, board);
        dfsHelper(row, column + 1, board);
        dfsHelper(row, column  - 1, board);
    }
};