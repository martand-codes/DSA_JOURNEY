/*
------------------------------------------------------------
Problem : Min Cost to Connect All Points (LeetCode 1584)
Pattern : Graph + Greedy + Prim's Algorithm (Minimum Spanning Tree)

Time Complexity : O(N² log N)
Space Complexity : O(N)

Idea:
- Treat each point as a vertex in a complete graph.
- The weight between two vertices is their Manhattan Distance.
- Start Prim's Algorithm from any point.
- Maintain a min-heap to always select the minimum-cost edge that
  connects a new point to the growing MST.
- Maintain a minCost[] array to store the cheapest known edge for
  every unvisited point.
- Update minCost[] whenever a cheaper connection is discovered.

Key Insight:
Instead of pushing every possible edge into the priority queue,
only push an edge if it provides a cheaper way to connect that
vertex to the MST. This avoids many unnecessary heap insertions
while preserving Prim's greedy property.
------------------------------------------------------------
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        priority_queue<
            pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min Heap

        int source = 0;
        int n = points.size();

        vector<bool> MST(n, false);
        vector<int> minCost(n, INT_MAX);

        pq.push({0, source});
        minCost[source] = 0;

        int minimumCost = 0;

        while (!pq.empty()) {

            int u = pq.top().second;
            int currentCost = pq.top().first;
            pq.pop();

            if (MST[u])
                continue;

            MST[u] = true;
            minimumCost += currentCost;

            for (int destination = 0; destination < n; destination++) {

                if (!MST[destination]) {

                    int weight =
                        abs(points[u][0] - points[destination][0]) +
                        abs(points[u][1] - points[destination][1]);

                    if (weight < minCost[destination]) {

                        minCost[destination] = weight;
                        pq.push({weight, destination});
                    }
                }
            }
        }

        return minimumCost;
    }
};