/*
------------------------------------------------------------
Problem : Max Area of Island (LeetCode 695)
Pattern : Graph + DFS (Flood Fill)
Time Complexity : O(R × C)
Space Complexity : O(R × C)

Idea:
- Traverse every cell.
- Whenever land is found, perform DFS.
- DFS returns the size of that connected island.
- Keep track of the largest area encountered.

Key Insight:
Instead of only marking an island as visited,
let every DFS call return the size of the connected
component rooted at that cell.
------------------------------------------------------------
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maximumArea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    int currentArea = dfsHelper(i, j, grid);
                    maximumArea = max(maximumArea, currentArea);
                }
            }
        }
        return maximumArea;
    }
    int dfsHelper(int row, int column, vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        
        int maximumArea = 0;

        // Base Case
        if(row < 0 || row >= r || column < 0 || column >= c || grid[row][column] == 0) {
            return 0;
        }
        grid[row][column] = 0; // Initializing

        int currentArea = 1;
        currentArea += dfsHelper(row + 1, column, grid);
        currentArea += dfsHelper(row - 1, column, grid);
        currentArea += dfsHelper(row, column + 1, grid);
        currentArea += dfsHelper(row, column - 1, grid);
        return currentArea;
    }
        
};
