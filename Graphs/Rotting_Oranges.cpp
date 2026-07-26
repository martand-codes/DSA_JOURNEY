/*
------------------------------------------------------------
Problem : Rotting Oranges (LeetCode 994)
Pattern : Graph + Multi-Source BFS

Time Complexity : O(R × C)
Space Complexity : O(R × C)

Idea:
- Push all initially rotten oranges into the queue.
- Count the number of fresh oranges.
- Perform Multi-Source BFS level by level.
- Each BFS level represents one minute.
- Infect all adjacent fresh oranges and add them to the queue.
- Continue until no fresh oranges remain or spreading is impossible.

Key Insight:
Treat every initially rotten orange as a starting point.
Because BFS expands level by level, the first time a fresh
orange is reached is exactly the earliest minute it can rot.
------------------------------------------------------------
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        // We have to store in pairs as it's a 2D Grid
        queue<pair<int, int>> q;

        // Directional Vector:
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        int freshCounter = 0;
        int minutes = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    freshCounter++;
                }
            }
        }
        // BFS
        while(!q.empty() && freshCounter > 0) {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++) {
                int row = q.front().first;
                int column = q.front().second;
                q.pop();

                for(auto& dir : directions) {
                    int newRow = row + dir.first;
                    int newColumn = column + dir.second;

                    // Condition if it's Fresh Orange

                    if(newRow >= 0 && newRow < r && newColumn >= 0 && newColumn < c && grid[newRow][newColumn] == 1) {
                        grid[newRow][newColumn] = 2; // Rotting the Adjacent in all 4 directions
                        freshCounter--;
                        q.push({newRow, newColumn});
                    }
                }
            }
            minutes++;
            
        }
        if(freshCounter > 0) {
            return -1;
        }
        return minutes;
    }
};