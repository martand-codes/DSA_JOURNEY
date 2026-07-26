/*
------------------------------------------------------------
Problem : Bellman-Ford Algorithm (Single Source Shortest Path)
Pattern : Graph + Dynamic Programming (Edge Relaxation)

Time Complexity : O(V × E)
Space Complexity : O(V)

Idea:
- Initialize all distances as infinity except the source.
- Relax every edge exactly (V - 1) times.
- Each relaxation attempts to improve the shortest known path.
- Perform one additional pass to detect a negative weight cycle.

Key Insight:
A shortest path can contain at most (V - 1) edges. If any edge
can still be relaxed after (V - 1) iterations, the graph contains
a negative weight cycle reachable from the source.
------------------------------------------------------------
*/

void bellmanFord(vector<vector<Edge>>& graph, int V, int src) {

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++) {

        for(int u = 0; u < V; u++) {

            for(const Edge& e : graph[u]) {

                if(dist[u] != INT_MAX &&
                   dist[e.v] > dist[u] + e.wt) {

                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }
}