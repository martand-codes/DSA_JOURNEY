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
