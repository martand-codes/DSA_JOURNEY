/*
------------------------------------------------------------
Problem : Dijkstra's Algorithm (Single Source Shortest Path)
Pattern : Graph + Greedy + Priority Queue (Min Heap)

Time Complexity : O((V + E) log V)
Space Complexity : O(V + E)

Idea:
- Maintain the shortest known distance from the source to every vertex.
- Use a min heap to always process the vertex with the minimum
  tentative distance.
- Relax all outgoing edges of the current vertex.
- If a shorter path to a neighbour is found, update its distance
  and push it into the priority queue.

Key Insight:
Once a vertex is extracted from the min heap with its minimum
distance, no shorter path to that vertex can exist (assuming all
edge weights are non-negative). The priority queue ensures vertices
are processed in increasing order of distance.
------------------------------------------------------------
*/

void dijkstra(int src, vector<vector<Edge>>& graph, int V) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {

        auto [currentDist, u] = pq.top();
        pq.pop();

        if(currentDist > dist[u])
            continue;

        for(const Edge& e : graph[u]) {

            if(dist[e.v] > dist[u] + e.wt) {

                dist[e.v] = dist[u] + e.wt;

                pq.push({dist[e.v], e.v});
            }
        }
    }
}