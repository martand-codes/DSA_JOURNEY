// Problem: Minimum Score of a Path Between Two Cities (LeetCode 2492)
// Pattern: Graphs + BFS
// TC: O(V + E)
// SC: O(V + E)
//
// Idea:
// Build an adjacency list.
// Perform BFS from city 1.
// Traverse the entire connected component.
// Track the minimum edge weight encountered.
// That minimum is the answer.

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        
        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;
        
        int ans = 1e9;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (const auto& edge : adj[u]) {
                ans = min(ans, edge.second);
                if (!vis[edge.first]) {
                    vis[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
        
        return ans;
    }
};