/*
Problem : Topological Sort (DFS Based)
Pattern : Graph + DFS + Stack
Time Complexity : O(V + E)
Space Complexity : O(V)

Idea:
- Perform a DFS traversal starting from every unvisited
  vertex.
- After visiting all adjacent vertices of a node, push
  the node onto a stack.
- Once DFS is complete, pop elements from the stack to
  obtain the topological ordering.

Key Insight:
A node is pushed onto the stack only after all of its
dependencies (outgoing neighbours) have been processed.
Therefore, when the stack is popped, every node appears
before the vertices that depend on it, producing a valid
topological ordering.

Note:
- Works only for Directed Acyclic Graphs (DAGs).
- Cannot produce a valid ordering if the graph contains
  a cycle.
*/

void topologicalSort() {
    vector<bool> visited(V, false);
    stack<int> s;

    for(int i = 0; i < V; i++) {
        if(!visited[V]) {
            topologicalSortHelper(i, visited, s);
        }
    }
     while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

void topologicalSortHelper(int src, vector<bool> &visited, stack<int> &s) {
    visited[src] = true; // DFS
    list<int> neighbours = l[src];
    for(int v : neighbours) {
        if(!visited[i]) {
            topologicalSortHelper(v, visited, s);
        }
    }
    s.push(src);
} 
