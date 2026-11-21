/*
------------------------------------------------------------
Problem : Graph Valid Tree (LeetCode 261)

Pattern : Graph / Depth-First Search (DFS) /
          Cycle Detection / Parent Tracking /
          Connected Components

Time Complexity :
ValidTree : O(V + E)
HasCycle  : O(V + E) overall

Space Complexity : O(V + E)

Idea:
Determine whether an undirected graph forms a valid tree.

A valid tree must satisfy two conditions:
- It must be connected, meaning every vertex is reachable
  from every other vertex.
- It must be acyclic, meaning it contains no cycles.

- First, check whether the number of edges equals n - 1.
- If edges.size() != n - 1:
  - Return false because a connected undirected tree
    with n vertices must contain exactly n - 1 edges.
- Initialize an adjacency list to represent the graph.
- Traverse the edges list:
  - Add each edge in both directions because the graph
    is undirected.
- Initialize a visited array of size n with false.
- Initialize visitedCount to zero to track the number
  of vertices visited during DFS.

Cycle Detection using DFS:
- Start DFS from vertex 0 with parent = -1.
- Inside the DFS function:
  - Mark the current node as visited.
  - Increment visitedCount.
  - Traverse all neighboring vertices.

For every neighbor:
- If the neighbor is unvisited:
  - Recursively call DFS with the current node as
    its parent.
  - If the recursive call detects a cycle, propagate
    true immediately.
- If the neighbor is already visited and is not the
  parent of the current node:
  - A cycle exists, so return true.

- If all neighbors are processed without detecting
  a cycle, return false.

Connectivity Check:
- If DFS detects a cycle, return false immediately.
- Otherwise, compare visitedCount with n.
- If visitedCount == n:
  - Every vertex is reachable from vertex 0.
  - The graph is connected and acyclic.
  - Return true.
- Otherwise, return false because the graph is
  disconnected.

Finally:
- Return true only when the graph satisfies both
  the edge-count condition and the connectivity
  and cycle-detection checks.

Key Insight:
An undirected graph is a valid tree if and only if
it is connected and contains no cycles.

The edge-count condition provides an important
optimization:

A connected undirected graph with n vertices and
exactly n - 1 edges is necessarily a tree.

However, this implementation additionally verifies
connectivity and detects cycles explicitly.

During DFS, tracking the parent node is essential
because every undirected edge appears in both
vertices' adjacency lists.

When traversing from node u to node v, the edge
back from v to u must not be treated as a cycle.

Therefore:
- An unvisited neighbor indicates a new DFS traversal.
- A visited neighbor different from the parent indicates
  a back edge and hence a cycle.

The visitedCount variable tracks how many distinct
vertices are reached from the starting vertex.

If visitedCount equals n, the entire graph is connected.

V represents the number of vertices in the graph.
E represents the number of edges in the graph.

Building the adjacency list requires O(V + E) time
and O(V + E) space.

Each vertex is visited exactly once, and every edge
is examined at most twice during DFS.

Therefore, the overall time complexity is O(V + E).

The adjacency list requires O(V + E) space, while
the visited array and recursive DFS call stack
require O(V) additional space.

Hence, the overall auxiliary space complexity is
O(V + E), including graph storage.

------------------------------------------------------------
*/

class Solution {
public:
    bool hasCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited, int& visitedCount) {
        visited[node] = true;
        visitedCount++;

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                if (hasCycle(nei, node, adj, visited, visitedCount)) {
                    return true;
                }
            } else if (nei != parent) {
                return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int visitedCount = 0;

        if (hasCycle(0, -1, adj, visited, visitedCount)) {
            return false;
        }

        return visitedCount == n;
    }
};