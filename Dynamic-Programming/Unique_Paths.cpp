/*
------------------------------------------------------------
Problem : Unique Paths (LeetCode 62)
Pattern : Dynamic Programming (2D Grid DP)

Time Complexity : O(M × N)
Space Complexity : O(M × N)

Idea:
- dp[i][j] represents the number of unique paths from
  the top-left corner to cell (i, j).
- The first row and first column contain only one possible
  path because movement is restricted to right and down.
- For every other cell, a path can arrive either from the
  cell above or from the cell to the left:
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

Key Insight:
Every path reaching a cell must come from either above
or from the left. Therefore, the total number of paths
to a cell is the sum of the paths to those two previous
cells.

------------------------------------------------------------
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                
            }
        }
        return dp[m - 1][n - 1];
    }
};