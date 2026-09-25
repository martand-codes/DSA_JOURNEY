/*
------------------------------------------------------------
Problem : Unique Paths III (LeetCode 980)
Pattern : DFS + Backtracking

Time Complexity : O(4^(M × N))
Space Complexity : O(M × N)

Idea:
- Find the starting cell and count all cells that must
  be visited before reaching the destination.
- Use DFS to explore all four possible directions.
- Mark the current cell as visited before exploring.
- Decrease the number of remaining required cells.
- When the destination is reached, count the path only if
  all required cells have been visited.
- Restore the current cell after exploring all directions
  so that it can be used by other possible paths.

Key Insight:
Reaching the destination is not enough. A path is valid
only when it reaches the destination after visiting every
non-obstacle cell exactly once. Backtracking allows us to
explore each possible path while maintaining the visited
state correctly.

------------------------------------------------------------
*/

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startRow = 0, startCol = 0, emptyCount = 1;  
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                } else if (grid[i][j] == 0) {
                    emptyCount++;
                }
            }
        }
        return dfs(grid, startRow, startCol, emptyCount);
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c, int remaining) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == -1) {
            return 0;
        }
        if (grid[r][c] == 2) {
            if (remaining == 0) return 1;
            else return 0;
        }
        grid[r][c] = -1;     
        int paths = 0;
        paths += dfs(grid, r + 1, c, remaining - 1); // Down
        paths += dfs(grid, r - 1, c, remaining - 1); // Up
        paths += dfs(grid, r, c + 1, remaining - 1); // Right
        paths += dfs(grid, r, c - 1, remaining - 1); // Left
        grid[r][c] = 0; 
        
        return paths;
    }
};