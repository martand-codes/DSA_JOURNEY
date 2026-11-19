/*
------------------------------------------------------------
Problem : Island Perimeter (LeetCode 463)
Pattern : Graph + DFS (Flood Fill)
Time Complexity : O(R × C)
Space Complexity : O(R × C)

Idea:
- Find the first land cell.
- Perform DFS from that cell.
- If DFS reaches water or goes out of bounds,
  contribute 1 to the perimeter.
- If the cell is already visited, contribute 0.
- Sum the contributions from all four directions.

Key Insight:
Each edge of a land cell contributes to the perimeter
only if it is adjacent to water or lies on the grid
boundary.
------------------------------------------------------------
*/

/*
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) { // Because we look for non sqaure grids
                if(grid[i][j] == 1) {
                    perimeter += 4;
                
                    if( i > 0 && grid[i-1][j] == 1){ // Safety Check
                        perimeter -= 2;
                    }
                    if( j > 0 && grid[i][j-1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        return perimeter;
    }
};
*/

// Solving using dfs

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    return dfsHelper(i, j, grid);
                }
            }
        }
        return 0;
    }
    int dfsHelper(int row, int column, vector<vector<int>>& grid) {
        // Base Cases
        if(row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size()) {
            return 1;
        }

        // If only Water
        if(grid[row][column] == 0) {
            return 1;
        }

        // Visisted
        if(grid[row][column] == -1) {
            return 0;
        }

        grid[row][column] = -1;
        int perimeter = 0;

        perimeter += dfsHelper(row - 1, column, grid);
        perimeter += dfsHelper(row + 1, column, grid);
        perimeter += dfsHelper(row, column - 1, grid);
        perimeter += dfsHelper(row, column + 1, grid);

        return perimeter;

        
    }

};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        queue<pair<int, int>> q;

        // Find the first land cell and mark it visited (-1)
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = -1;
                    q.push({r, c});
                    break;
                }
            }
            if (!q.empty()) break;
        }

        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                // Out of grid bounds or water -> contributes 1 to perimeter
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == 0) {
                    perimeter++;
                }
                // Unvisited land -> mark visited immediately before pushing to avoid duplicates
                else if (grid[nr][nc] == 1) {
                    grid[nr][nc] = -1;
                    q.push({nr, nc});
                }
                // If grid[nr][nc] == -1 (already visited land), do nothing (shared edge)
            }
        }

        return perimeter;
    }
};