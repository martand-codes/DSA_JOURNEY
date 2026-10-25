/*
------------------------------------------------------------
Problem : Number of Closed Islands (LeetCode 1254)
Pattern : Graphs + DFS + Flood Fill

Time Complexity : O(M * N)
Space Complexity : O(M * N)

Idea:
- First, traverse all boundary cells of the grid.
- Whenever a boundary cell contains 0 (land), perform DFS
  to mark its entire connected island as visited by
  changing its cells to 1.
- These islands are not closed because they touch the
  boundary.
- Next, traverse only the interior cells of the grid.
- Whenever an unvisited land cell (0) is found:
    - Increment the closed island count.
    - Perform DFS to mark the entire island as visited.
- Return the total number of closed islands.

Key Insight:
A closed island must be completely surrounded by water
and must not touch the grid boundary.

Instead of explicitly checking whether every island is
enclosed, eliminate all islands connected to the boundary
first.

After this step, every remaining connected component of
land is guaranteed to be a closed island.

------------------------------------------------------------
*/

class Solution {

    void dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        grid[r][c] = 1;
        dfs(grid, r - 1, c); // up
        dfs(grid, r + 1, c); // down
        dfs(grid, r, c - 1); // left
        dfs(grid, r, c + 1); // right
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(grid, r, c);
                }
            }
        }
        
        int closedIslandsCount = 0;
        for (int r = 1; r < rows - 1; ++r) {
            for (int c = 1; c < cols - 1; ++c) {
                if (grid[r][c] == 0) {
                    closedIslandsCount++;
                    dfs(grid, r, c);
                }
            }
        }
        return closedIslandsCount;
    }
};