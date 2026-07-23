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
        int islands = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    dfsHelper(i, j, grid);
                }
            }
        }
        return islands;
    }
    void dfsHelper(int row, int column, vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        // Base Case
        if(row < 0 || row >= r || column < 0 || column >= c || grid[row][column] == '0') {
            return;
        }
        grid[row][column] = '0'; // Marked the First element 
        dfsHelper(row + 1, column, grid); // Down
        dfsHelper(row - 1, column, grid); // Up
        dfsHelper(row, column + 1, grid); // Right
        dfsHelper(row, column - 1, grid); // Left
        
    }
};