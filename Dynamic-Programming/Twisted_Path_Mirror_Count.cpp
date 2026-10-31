/*
------------------------------------------------------------
Problem : Unique Paths with Teleportation / Special Cells
Pattern : Dynamic Programming + State Tracking + Grid Traversal

Time Complexity : O(M * N)
Space Complexity : O(M * N)

Idea:
- Maintain two DP matrices:
    dp_right[i][j] → Number of ways to reach cell (i, j)
                     with the last move being RIGHT.
    dp_down[i][j]  → Number of ways to reach cell (i, j)
                     with the last move being DOWN.
- Initialize the first possible moves from the starting cell.
- Traverse the grid row by row.
- For an empty cell (0):
    - Combine both incoming states.
    - Propagate the total number of paths to the right
      and downward.
- For a special cell (1):
    - A path arriving from the left can only continue DOWN.
    - A path arriving from above can only continue RIGHT.
- Apply modulo 10^9 + 7 during every transition.
- Return the sum of both incoming states at the destination.

Key Insight:
The number of paths reaching a cell depends not only on
the cell itself but also on the direction of the previous
move.

Therefore, a single DP value per cell is insufficient.
We maintain two directional states to preserve this
information.

For an empty cell:

    total = dp_right[i][j] + dp_down[i][j]

For a special cell, the movement direction is switched:

    LEFT arrival  → DOWN departure
    UP arrival    → RIGHT departure

This directional state tracking allows each cell to be
processed in constant time.

------------------------------------------------------------
*/


class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();   
        int n = grid[0].size(); 
        const int MOD = 1e9 + 7;
        
        vector<vector<long long>> dp_right(m, vector<long long>(n, 0));
        vector<vector<long long>> dp_down(m, vector<long long>(n, 0));
        
        if (n > 1) dp_right[0][1] = 1;
        if (m > 1) dp_down[1][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                if (grid[i][j] == 0) {
                    long long total = (dp_right[i][j] + dp_down[i][j]) % MOD;
                    
                    if (j + 1 < n) {
                        dp_right[i][j + 1] = (dp_right[i][j + 1] + total) % MOD;
                    }
                    if (i + 1 < m) {
                        dp_down[i + 1][j] = (dp_down[i + 1][j] + total) % MOD;
                    }
                } else if (grid[i][j] == 1) {
                    if (i + 1 < m) {
                        dp_down[i + 1][j] = (dp_down[i + 1][j] + dp_right[i][j]) % MOD;
                    }
                    if (j + 1 < n) {
                        dp_right[i][j + 1] = (dp_right[i][j + 1] + dp_down[i][j]) % MOD;
                    }
                }
            }
        }
        return (dp_right[m - 1][n - 1] + dp_down[m - 1][n - 1]) % MOD; 
    }
};