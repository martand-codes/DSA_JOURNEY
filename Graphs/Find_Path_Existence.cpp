/*
------------------------------------------------------------
Problem : Find if Path Exists in Graph (LeetCode 1971)
Pattern : Graph + DFS
Time Complexity : O(V + E)
Space Complexity : O(V + E)

Idea:
- Convert the edge list into an adjacency list.
- Start DFS from the source vertex.
- Use a visited array to avoid revisiting vertices.
- If the destination is reached, return true.
- Otherwise continue exploring all neighbours.
- If no path exists, return false.

Key Learning:
Graphs are almost always traversed using an adjacency list
combined with DFS or BFS.
------------------------------------------------------------
*/

// With DFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            //For Bidirectional Graph
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
            vector<bool> visited(n, false);
            return dfsHelper(graph, visited, source, destination);
        
    }
     bool dfsHelper(vector<vector<int>>& graph, vector<bool>& visited, int current, int destination) {
        // Base Cases:
        if (current == destination) {
            return true;
        }
        if (visited[current] == true) {
            return false; // Which Means we are Traversing a cycle
        }
        visited[current] = true;

        for(int neighbour : graph[current]) {
            if(dfsHelper(graph, visited, neighbour, destination)) {
                return true;
            }
        }
        return false;
    }
};

// Using BFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Base Case Check
        if (source == destination) return true;

        // 1. Build the Adjacency List (Exact same as DFS!)
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // 2. Setup Visited Array
        vector<bool> visited(n, false);
        
        // 3. Setup the Queue for BFS
        queue<int> q;
        
        // Start the ripple: Push the source and mark it visited immediately
        q.push(source);
        visited[source] = true;
        
        // 4. The Main Loop
        while(!q.empty()) {
            // Grab the guy at the front of the line
            int current = q.front();
            q.pop();
            
            // Check all of his neighbors
            for(int neighbor : graph[current]) {
                if(neighbor == destination) {
                    return true; // We found it!
                }
                
                // If we haven't seen this neighbor, queue them up!
                if(!visited[neighbor]) {
                    visited[neighbor] = true; // Mark BEFORE pushing!
                    q.push(neighbor);
                }
            }
        }
        
        // The queue is empty and we never found the destination
        return false;
    }
};
