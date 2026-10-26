/*
------------------------------------------------------------
Problem : Count Islands With Sum Divisible by K
Pattern : Graphs + DFS + Flood Fill + Component Aggregation

Time Complexity : O(M * N)
Space Complexity : O(M * N)

Idea:
- Traverse every cell in the grid.
- Whenever a cell contains a positive value, start DFS
  to explore its entire connected island.
- During DFS:
    - Add the current cell's value to the island sum.
    - Mark the cell as visited by setting it to 0.
    - Explore all four adjacent directions.
- After collecting the island's total sum, check whether
  it is divisible by k.
- If island_sum % k == 0, increment the island count.
- Return the total number of qualifying islands.

Key Insight:
Each island is a connected component of positive-valued
cells, connected horizontally or vertically.

DFS visits every cell in a component exactly once and
calculates its total value.

An island qualifies when:

    island_sum % k == 0

Marking visited cells as 0 avoids revisiting them and
eliminates the need for a separate visited matrix.

------------------------------------------------------------
*/


class Solution {
    long long dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }
        long long current_val = grid[r][c];
        grid[r][c] = 0;
        long long total_sum = current_val;
        total_sum += dfs(grid, r - 1, c); // up
        total_sum += dfs(grid, r + 1, c); // down
        total_sum += dfs(grid, r, c - 1); // left
        total_sum += dfs(grid, r, c + 1); // right
        return total_sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int divisible_islands = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0) {
                    long long island_sum = dfs(grid, r, c);
                    if (island_sum % k == 0) {
                        divisible_islands++;
                    }
                }
            }
        }
        return divisible_islands;
    }
};