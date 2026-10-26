/*
------------------------------------------------------------
Problem : Longest Increasing Path in a Matrix (LeetCode 329)
Pattern : DFS + Dynamic Programming + Memoization

Time Complexity : O(M * N)
Space Complexity : O(M * N)

Idea:
- Create a DP matrix initialized to 0.
- Each dp[r][c] stores the length of the longest
  strictly increasing path starting from cell (r, c).
- Use DFS to explore the four adjacent directions.
- Only move to a neighboring cell if its value is greater
  than the current cell's value.
- For each valid neighbor, calculate:
      1 + dfs(next_r, next_c)
- Store the maximum path length in dp[r][c].
- If a cell's DP value is already calculated, return it
  immediately instead of exploring it again.
- Start DFS from every cell and track the global maximum.

Key Insight:
Because movement is allowed only toward strictly greater
values, a path can never form a cycle.

Memoization ensures that each cell's longest increasing
path is computed only once, even if multiple DFS calls
reach that cell.

Recurrence:

    dp[r][c] = 1 + max(
        dp[next_r][next_c]
    )

over all valid neighbors with:

    matrix[next_r][next_c] > matrix[r][c]

The answer is the maximum dp[r][c] over the entire matrix.

------------------------------------------------------------
*/

class Solution {
    int m, n;
    // (up, down, left, right)
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c) {
        if (dp[r][c] != 0) {
            return dp[r][c];
        }
        int max_path = 1; 
        for (int i = 0; i < 4; i++) {
            int next_r = r + dirs[i][0];
            int next_c = c + dirs[i][1];
            if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n 
                && matrix[next_r][next_c] > matrix[r][c]) {
                max_path = max(max_path, 1 + dfs(matrix, dp, next_r, next_c));
            }
        }
        dp[r][c] = max_path;
        return max_path;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int longest_path = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                longest_path = max(longest_path, dfs(matrix, dp, r, c));
            }
        }

        return longest_path;
    }
};