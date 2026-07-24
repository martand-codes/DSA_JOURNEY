/*
------------------------------------------------------------
Problem : Walls and Gates / Islands and Treasure (LeetCode 286)
Pattern : Graph + Multi-Source BFS

Time Complexity : O(R × C)
Space Complexity : O(R × C)

Idea:
- Push all gates (0s) into the queue initially.
- Perform BFS simultaneously from every gate.
- Whenever an unvisited empty room (INF) is reached,
  assign it a distance of parent + 1.
- Since BFS explores level by level, the first time an
  empty room is visited is guaranteed to be its shortest
  distance from any gate.

Key Insight:
Instead of running BFS from every empty room, start BFS
from every gate at once (Multi-Source BFS). The expanding
waves from all gates naturally ensure each room receives
the minimum possible distance.
------------------------------------------------------------
*/

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        // direction arrays
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // BFS
        while(!q.empty()) {
            int row = q.front().first;
            int column = q.front().second;
            q.pop();

            for(auto& dir : directions) {
                int newRow = row + dir.first;
                int newColumn = column + dir.second;

                if (newRow < 0 || newRow >= r || newColumn < 0 || newColumn >= c || grid[newRow][newColumn] != 2147483647) {
                    continue; 
                }
                grid[newRow][newColumn] = grid[row][column] + 1;

                q.push({newRow, newColumn});
            }
        }
    }
};