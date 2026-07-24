/*
------------------------------------------------------------
Problem : Clone Graph (LeetCode 133)
Pattern : Graph + DFS + HashMap

Time Complexity : O(V + E)
Space Complexity : O(V)

Idea:
- Traverse graph using DFS.
- Clone each node exactly once.
- Store mapping from original node to cloned node.
- Reuse cloned nodes whenever encountered again.

Key Insight:
The hash map is not merely for marking nodes as visited;
it stores the correspondence between original nodes and
their cloned counterparts, enabling correct reconstruction
of edges while avoiding infinite recursion in cyclic graphs.
------------------------------------------------------------
*/

class Solution {
public:
    unordered_map<Node*, Node*>Visited; // To Prevent Stack Overflow
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }
        if(Visited.find(node) != Visited.end()) {
            return Visited[node];
        }
        // Making a new Node
        Node* clonedNode = new Node(node->val);

        Visited[node] = clonedNode;

        for(Node* neighbor : node->neighbors) {
            clonedNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return clonedNode;
    }
};
    