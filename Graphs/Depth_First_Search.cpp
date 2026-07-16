/*
Algorithm : Depth First Search (DFS)
Data Structure : Recursion (Call Stack)
Traversal : Depth-wise

Time Complexity : O(V + E)
Space Complexity : O(V)

Idea:
- DFS explores one path completely before backtracking.
- Recursion is used to visit neighbouring vertices.
- A visited array prevents revisiting the same vertex.
- Every unvisited neighbour is explored recursively.

Pattern:
1. Mark the current vertex as visited.
2. Process the current vertex.
3. Traverse all neighbours.
4. If a neighbour is unvisited, recursively call DFS.
5. Continue until all reachable vertices are visited.

Applications:
- Connected Components
- Cycle Detection
- Topological Sorting
- Path Finding
- Strongly Connected Components
- Tree Traversals
- Maze Solving
*/

void dfs(int u, vector<bool>& visited) {
    visited[u] = true;
    cout<<u<<" ";
    list<int> neighbours = l[u];
    for(int v : neighbours) {
        if(!visited[v]) {
            dfs(v, visited);
        }
    }
}