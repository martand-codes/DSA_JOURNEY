/*
------------------------------------------------------------
Problem : Create Grid
Pattern : 2D Arrays + Matrix Initialization

Time Complexity : O(M * N)
Space Complexity : O(M * N)

Idea:
- Initialize an M x N grid filled with '#'.
- Replace every cell in the first row with '.'.
- Replace every cell in the last column with '.'.
- Return the constructed grid.

Key Insight:
A vector<string> can represent a 2D character grid.
Initialize the entire grid with the required default
character, then modify the specified boundaries.

The first row is accessed using grid[0], and the last
column is accessed using grid[i][N - 1].

------------------------------------------------------------
*/

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        for (int j = 0; j < n; j++) {
            grid[0][j] = '.';
        }
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }
        return grid;
    }
};