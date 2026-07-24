/*
------------------------------------------------------------
Problem : Pacific Atlantic Water Flow (LeetCode 417)
Pattern : Graph + Reverse DFS (Flood Fill)

Time Complexity : O(R × C)
Space Complexity : O(R × C)

Idea:
- Start DFS from all Pacific border cells.
- Start DFS from all Atlantic border cells.
- Traverse only to neighboring cells with height greater
  than or equal to the current cell.
- Cells reachable from both oceans form the answer.

Key Insight:
Instead of checking whether every cell can reach an ocean,
reverse the process and let each ocean expand inward.
The intersection of the two reachable sets is the result.
------------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<bool>> pacifica(r, vector<bool>(c, false));
        vector<vector<bool>> atlantica(r, vector<bool>(c, false));

        for(int i = 0; i < r; i++) {
            dfsHelper(i, 0, heights[i][0], heights, pacifica);
            dfsHelper(i, c - 1, heights[i][c-1], heights, atlantica);
        }
        for(int j = 0; j < c; j++) {
            dfsHelper(0, j, heights[0][j], heights, pacifica);
            dfsHelper(r - 1, j, heights[r-1][j], heights, atlantica);
        }

        vector<vector<int>> results;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++){
                if(pacifica[i][j] && atlantica[i][j]) {
                    results.push_back({i, j});
                }
            }
        }
        return results;

    }
    void dfsHelper(int row, int column, int previousHeight, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        int r = heights.size();
        int c = heights[0].size();
        
        

        if(row < 0 || column < 0 || row >= r || column >= c) {
            return;
        }
        if(visited[row][column]) {
            return;
        }
        if (heights[row][column] < previousHeight) {
            return;
        }
        // Visiting the Source
        visited[row][column] = true;

        dfsHelper(row + 1, column, heights[row][column], heights, visited);
        dfsHelper(row - 1, column, heights[row][column], heights, visited);
        dfsHelper(row, column + 1, heights[row][column], heights, visited);
        dfsHelper(row, column - 1, heights[row][column], heights, visited);
    }
};