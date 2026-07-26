/*
------------------------------------------------------------
Problem : Prim's Algorithm (Minimum Spanning Tree)
Pattern : Graph + Greedy + Priority Queue (Min Heap)

Time Complexity : O((V + E) log V)
Space Complexity : O(V + E)

Idea:
- Start from any vertex.
- Use a min heap to always choose the minimum weight edge
  connecting the current MST to a new vertex.
- Add the selected vertex to the MST.
- Push all outgoing edges of the newly added vertex into the heap.
- Repeat until all vertices are included.

Key Insight:
At every step, choose the lightest edge that connects a visited
vertex to an unvisited vertex. This greedy choice always produces
a Minimum Spanning Tree.
------------------------------------------------------------
*/

void prims(int src) {

    vector<bool> mst(V, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, src});

    int ans = 0;

    while(!pq.empty()) {

        auto [wt, u] = pq.top();
        pq.pop();

        if(mst[u])
            continue;

        mst[u] = true;
        ans += wt;

        for(const auto& [v, currentWt] : graph[u]) {

            if(!mst[v]) {
                pq.push({currentWt, v});
            }
        }
    }

    cout << ans;
}