/*
------------------------------------------------------------
Problem : Number of Islands (LeetCode 200)
Pattern : Graph + DFS (Flood Fill)
Time Complexity : O(R × C)
Space Complexity : O(R × C)

Idea:
- Traverse every cell in the grid.
- When an unvisited land cell ('1') is found,
  increment the island count.
- Perform DFS to mark the entire connected island
  as visited by converting land to water ('0').
- Continue scanning until the entire grid is processed.

Key Insight:
Each DFS completely explores one connected component
(island). Therefore, every DFS call started from an
unvisited land cell corresponds to exactly one island.
------------------------------------------------------------
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int row = 0, column = 0;
      int numberofIslands = 0;
      for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                numberofIslands++;
                dfs(i, j, grid);
            }
        }
      }
      return numberofIslands;
    }

    void dfs(int row, int column, vector<vector<char>> &grid) {
    
        // Base Case:
        if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size()) {
            return;
        }
        if(grid[row][column] == '0') {
            return;
        }
        grid[row][column] = '0';
        dfs(row + 1, column, grid);
        dfs(row - 1, column, grid);
        dfs(row, column + 1, grid);
        dfs(row, column - 1, grid); 
    }
};



