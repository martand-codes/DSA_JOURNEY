/*
------------------------------------------------------------
Problem : Course Schedule (LeetCode 207)

Pattern : Graph / Depth-First Search (DFS) /
          Cycle Detection / Directed Graph /
          Recursion Stack / Topological Sorting

Time Complexity :
CanFinish : O(V + E)
DFS       : O(V + E) overall

Space Complexity : O(V + E)

Idea:
Determine whether all courses can be completed based
on the given prerequisite relationships.

A course cannot be completed if its prerequisite
relationships form a directed cycle.

- Initialize an adjacency list to represent the
  directed graph.
- Traverse the prerequisites list:
  - Each edge [a, b] means course b must be completed
    before course a.
  - Add a directed edge from b to a in the adjacency
    list.
- Initialize two boolean arrays:
  - visited tracks vertices that have been visited
    during DFS.
  - pathVisited tracks vertices currently present
    in the active DFS recursion path.

DFS Cycle Detection:
- Start DFS from every unvisited vertex.
- Inside the DFS function:
  - Mark the current node as visited.
  - Mark the current node as pathVisited because
    it belongs to the active recursion path.
- Traverse all neighboring vertices.

For every neighbor:
- If the neighbor is unvisited:
  - Recursively call DFS on that neighbor.
  - If the recursive call detects a cycle,
    return true immediately.
- Otherwise, if the neighbor is already present
  in the current recursion path:
  - A directed cycle has been detected.
  - Return true immediately.

- After processing all neighbors:
  - Remove the current node from the active recursion
    path by setting pathVisited[node] to false.
  - Return false because no cycle was detected
    along this DFS traversal.

Finally:
- Iterate through all courses.
- If a course is unvisited, initiate DFS from it.
- If any DFS traversal detects a cycle, return false
  because not all courses can be completed.
- If every DFS traversal finishes without detecting
  a cycle, return true.

Key Insight:
A directed graph contains a cycle if DFS encounters
a vertex that is already present in the current
recursion path.

Two separate visited arrays are necessary because
visiting a node previously does not necessarily mean
that a cycle exists.

visited:
Tracks whether a node has been explored at any point
during the entire DFS traversal.

pathVisited:
Tracks whether a node belongs to the current active
DFS recursion path.

For example:
If a node points to another node that was visited
in a previous completed DFS branch, it does not
necessarily indicate a cycle.

However, if a node points to an ancestor that is
still present in the current recursion path, a
directed cycle exists.

The pathVisited array prevents false cycle detection
between previously explored branches.

The graph is constructed using directed edges because
prerequisite relationships have a specific direction.

V represents the number of vertices (courses).
E represents the number of directed edges (prerequisites).

Building the adjacency list requires O(V + E) time.

Each vertex is visited exactly once, and every directed
edge is examined once during DFS.

Therefore, the overall time complexity is O(V + E).

The adjacency list requires O(V + E) space.

The visited array, pathVisited array, and recursive
DFS call stack each require O(V) space.

Hence, the overall auxiliary space complexity is
O(V + E), including graph storage.

------------------------------------------------------------
*/

class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<bool>& visited,
             vector<bool>& pathVisited)
    {
        visited[node] = true;      
        pathVisited[node] = true;
        
        for(int neighbour : graph[node])
        {
            if(!visited[neighbour])
            {
                if(dfs(neighbour, graph, visited, pathVisited))
                    return true;      
            }
            else if(pathVisited[neighbour])
            {
                return true;
            }
        }
        pathVisited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for(auto &edge : prerequisites)
        {
            int from = edge[1];
            int to   = edge[0];

            graph[from].push_back(to);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);
        
        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, graph, visited, pathVisited))
                    return false;
            }
        }
        return true;
    }
};