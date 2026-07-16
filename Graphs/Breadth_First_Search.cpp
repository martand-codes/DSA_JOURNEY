/*
Algorithm : Breadth First Search (BFS)
Data Structure : Queue
Traversal : Level-by-Level
Time Complexity : O(V + E)
Space Complexity : O(V)

Idea:
- BFS explores the graph level by level starting from a source vertex.
- A Queue is used to process vertices in FIFO (First In First Out) order.
- A visited array prevents revisiting the same vertex.
- Every unvisited neighbour is marked as visited and pushed into the queue.

Pattern:
1. Push the source vertex into the queue.
2. Mark it as visited.
3. While the queue is not empty:
   - Pop the front vertex.
   - Process the current vertex.
   - Visit all unvisited neighbours.
   - Mark them visited and push them into the queue.

Applications:
- Shortest Path in an Unweighted Graph
- Connected Components
- Level Order Traversal of Trees
- Network Broadcasting
- Web Crawling
- Finding Minimum Number of Edges
*/

// It is written by Queue
void BFS () {
    queue<int> Q;
    vector<bool> visited(V, false); // Bool Vector to prevent Visited Vertex and V == No of vertices
    Q.push(0); // Or the Source Vertex;
    visited[0] = true; // Marked the Source Vertex as visited

    // Now the Looping
    while(!Q.empty()) {
        int u = Q.front(); // The current Vertex Inside the Queue
        Q.pop(); // Pop the Current Vertex

        // For Tackling Neighbours
        list<int> neighbours = l[u]; // u ---- v
        for(int v : neighbours) {
            if(!visited[v]) { // IFF Not Visited
                visited[v] = true;
                Q.push(v);
            }
        }
    }
}
