/*
------------------------------------------------------------
Problem : Count Servers that Communicate (LeetCode 1267)
Pattern : Matrix Traversal / Counting / Frequency Arrays

Time Complexity : O(M * N)
Space Complexity : O(M + N)

Idea:
Perform two passes over the grid.

In the first pass, calculate the number of servers present
in every row and column using two frequency arrays.

In the second pass, traverse the grid again and count each
server that has at least one other server in its row or
column.

A server communicates if its row count or column count
is greater than 1.

Key Insight:
A server is considered communicating if another server
exists in the same row or column.

Precomputing row and column frequencies allows checking
each server in O(1) time during the second traversal.
------------------------------------------------------------
*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowCounter(m, 0);
        vector<int> columnCounter(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    rowCounter[i]++;
                    columnCounter[j]++;
                }
            }
        }
        int serverCommunicating = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    if(rowCounter[i] > 1 || columnCounter[j] > 1) {
                        serverCommunicating++;
                    }
                }
            }
        }
        return serverCommunicating;
    }
};