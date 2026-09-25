
/*
------------------------------------------------------------
Problem : Unique Paths II (LeetCode 63)
Pattern : Dynamic Programming (2D Grid DP)

Time Complexity : O(M × N)
Space Complexity : O(M × N)

Idea:
- dp[i][j] represents the number of unique paths from
  the top-left corner to cell (i, j).
- If a cell contains an obstacle, no path can pass through
  it, so dp[i][j] = 0.
- For every non-obstacle cell, paths can arrive from either
  above or from the left:
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
- Initialize dp[0][0] = 1 because there is one way to
  start at the top-left cell.
- If the starting cell itself is blocked, return 0.

Key Insight:
An obstacle contributes zero paths and automatically
prevents all paths from passing through that cell.
Otherwise, every valid path to a cell must come from
either the cell above or the cell to the left.

------------------------------------------------------------
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }                
                else {
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1]; 
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};