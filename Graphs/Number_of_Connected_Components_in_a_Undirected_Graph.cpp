/*
------------------------------------------------------------
Problem : Number of Connected Components in an Undirected
          Graph (LeetCode 323)

Pattern : Graph / Depth-First Search (DFS) /
          Adjacency List / Connected Components /
          Graph Traversal

Time Complexity :
CountComponents : O(V + E)
DFS             : O(V + E) overall

Space Complexity : O(V + E)

Idea:
Count the number of connected components in an undirected
graph containing n vertices and a given list of edges.

- Initialize an adjacency list to represent the graph.
- Traverse the edges list:
  - For every edge connecting vertices u and v:
    - Add v to the adjacency list of u.
    - Add u to the adjacency list of v.
  - Since the graph is undirected, both directions
    must be represented.
- Initialize a visited array of size n with false
  to track visited vertices.
- Initialize components to zero to count the number
  of connected components.

DFS Traversal:
- Iterate through every vertex from 0 to n - 1.
- If the current vertex has not been visited:
  - Increment components because an unvisited vertex
    indicates the discovery of a new connected component.
  - Call DFS starting from that vertex.

DFS Function:
- Mark the current node as visited.
- Traverse all its neighboring vertices using the
  adjacency list.
- For every unvisited neighbor:
  - Recursively call DFS on that neighbor.
- Continue traversal until all vertices belonging
  to the current connected component are visited.

Finally:
- After processing all vertices, return components
  as the total number of connected components.

Key Insight:
A connected component is a maximal group of vertices
where every vertex is reachable from every other
vertex through some path.

Starting DFS from an unvisited vertex explores and
marks every vertex belonging to its connected component.

Once that DFS traversal finishes, all vertices in that
component are marked as visited.

Therefore, when the outer loop encounters another
unvisited vertex, it must belong to a different
connected component.

Incrementing components exactly once before each new
DFS traversal ensures that every connected component
is counted exactly once.

The adjacency list efficiently represents the graph
because it stores only the actual connections between
vertices rather than an entire V x V adjacency matrix.

V represents the number of vertices in the graph.
E represents the number of edges in the graph.

Building the adjacency list requires O(V + E) space.

Initializing the visited array requires O(V) space.

Each vertex is visited exactly once, and every edge
is examined at most twice because the graph is
undirected and each edge appears in both adjacency
lists.

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
    void dfs(int node, vector<vector<int>>& adjacent, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbours : adjacent[node]) {
            if (!visited[neighbours]) {
                dfs(neighbours, adjacent, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacent(n);
        for (const auto& e : edges) {
            adjacent[e[0]].push_back(e[1]);
            adjacent[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adjacent, visited);
            }
        }

        return components;
    }
};