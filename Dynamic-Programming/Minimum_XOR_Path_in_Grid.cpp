/*
------------------------------------------------------------
Problem : Minimum Cost / Minimum XOR Path in a Grid
Pattern : Dynamic Programming + Bit Manipulation + Hashing

Time Complexity : O(M * N * K)
Space Complexity : O(M * N * K)

Idea:
- Create a 2D DP table where each cell stores an
  unordered_set of all possible XOR values for paths
  reaching that cell.
- Initialize dp[0][0] with grid[0][0].
- Traverse the grid from top-left to bottom-right.
- For each cell:
    - Propagate XOR values from the cell above.
    - Propagate XOR values from the cell to the left.
    - XOR each previous value with the current cell value.
- At the destination, find and return the minimum XOR
  value among all possible paths.

Key Insight:
Moving only right or down means every path to a cell
must come from either its top neighbor or its left neighbor.

For every previous XOR value:

    newXor = previousXor ^ grid[r][c]

Because XOR is path-dependent, a cell can have multiple
possible XOR values. An unordered_set stores distinct
values and avoids duplicate states.

Here, K represents the maximum number of distinct XOR
values stored per cell.

------------------------------------------------------------
*/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));
        dp[0][0].insert(grid[0][0]);
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r > 0) {
                    for (int val : dp[r - 1][c]) {
                        dp[r][c].insert(val ^ grid[r][c]);
                    }
                }
                if (c > 0) {
                    for (int val : dp[r][c - 1]) {
                        dp[r][c].insert(val ^ grid[r][c]);
                    }
                }
            }
        }
        int min_xor = 2147483647; // Max int
        for (int val : dp[m - 1][n - 1]) {
            min_xor = min(min_xor, val);
        }
        
        return min_xor;
    }
};