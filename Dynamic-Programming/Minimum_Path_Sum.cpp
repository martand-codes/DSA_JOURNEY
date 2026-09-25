/*
------------------------------------------------------------
Problem : Minimum Path Sum (LeetCode 64)
Pattern : Dynamic Programming (2D Grid DP)

Time Complexity : O(M × N)
Space Complexity : O(1) Auxiliary Space

Idea:
- Use the input grid itself as the DP table.
- Each cell stores the minimum path sum required to
  reach that cell.
- The first row can only be reached from the left, so
  accumulate its values from left to right.
- The first column can only be reached from above, so
  accumulate its values from top to bottom.
- For every remaining cell, choose the cheaper path from
  either above or the left:
      grid[i][j] += min(grid[i - 1][j], grid[i][j - 1])

Key Insight:
Every valid path to an internal cell must come either
from the cell above or from the cell to the left. Therefore,
the minimum path to the current cell is its own cost plus
the smaller of those two previously computed path sums.

------------------------------------------------------------
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);                
            }
        }
        return grid[m - 1][n - 1];
    }
};