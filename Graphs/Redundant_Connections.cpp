/*
------------------------------------------------------------
Problem : Redundant Connection (LeetCode 684)

Pattern : Graph / Depth-First Search (DFS) /
          Cycle Detection / Parent Tracking /
          Undirected Graph

Time Complexity :
FindRedundantConnection : O(N^2)
DFS                     : O(N + E) per iteration

Space Complexity : O(N)

Idea:
Find the edge that can be removed from an undirected
graph so that the resulting graph becomes a tree.

The graph initially represents a tree with one additional
edge, which creates exactly one cycle.

- Initialize n as the number of edges.
- Create an adjacency list of size n + 1 because
  the vertices are numbered from 1 to n.
- Process the edges one by one.

Edge Processing:
- For every edge connecting u and v:
  - Add v to the adjacency list of u.
  - Add u to the adjacency list of v.
- Initialize a fresh visited array of size n + 1.
- Run DFS starting from u with parent = -1.
- Check whether adding the current edge creates
  a cycle in the graph.

DFS Cycle Detection:
- Mark the current source vertex as visited.
- Traverse all adjacent vertices.
- For every adjacent vertex:
  - If it is unvisited:
    - Recursively call DFS with the current source
      as its parent.
    - If the recursive call detects a cycle,
      return true immediately.
  - If it is already visited and is not the parent:
    - A cycle has been detected.
    - Return true.
- If all adjacent vertices are processed without
  detecting a cycle, return false.

Finally:
- If DFS detects a cycle after inserting the current
  edge, return that edge as the redundant connection.
- If no redundant edge is found, return an empty vector.

Key Insight:
The graph is initially a tree with one additional edge.

A tree is connected and contains no cycles.
Adding one extra edge to a tree creates exactly one cycle.

Instead of removing every edge and checking whether
the resulting graph becomes a tree, the algorithm
processes edges incrementally.

After inserting each edge, DFS checks whether the
currently constructed graph contains a cycle.

The first edge that causes DFS to detect a cycle
is the redundant connection.

Parent tracking is essential because the graph is
undirected and every edge appears in both adjacency
lists.

When DFS moves from vertex u to vertex v, the reverse
edge from v to u must not be considered a cycle.

An already visited neighbor different from the parent
indicates a cycle.

N represents the number of edges in the input graph.
V represents the number of vertices.
E represents the number of edges currently inserted.

For this problem, V = N and the final graph contains
N + 1 edges.

Each iteration performs:
- O(1) adjacency list insertion.
- O(V + E) DFS traversal in the worst case.
- O(V) space for the visited array and recursion stack.

Since DFS is executed after every edge insertion,
the overall time complexity is O(N^2).

The adjacency list requires O(V + E) space.
The visited array and recursive DFS stack require
O(V) additional space.

Therefore, the overall auxiliary space complexity
is O(N), excluding the input and returned edge.

------------------------------------------------------------
*/

class Solution {
public:
    bool dfs(int src, int parent, vector<int> adj[], vector<bool>& vis) {
        vis[src] = true;
        for (auto adjnode : adj[src]) {
            if (!vis[adjnode]) {
                if (dfs(adjnode, src, adj, vis))
                    return true;
            } else if (adjnode != parent)
                return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n + 1];
        for (int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            vector<bool> vis(n + 1, false);
            if (dfs(edges[i][0], -1, adj, vis)) {
                return edges[i];
            }
        }
        return {};
    }
};