// Problem: Top View of Binary Tree
// Pattern: BFS + Horizontal Distance Mapping
// TC: O(n log n)
// SC: O(n)
//
// Idea:
// Perform level-order traversal.
// Track horizontal distance (HD) of each node.
// Store the first node encountered for every HD.
// Print nodes from leftmost HD to rightmost HD.

void topView(Node* root) {
    //BFS
    queue<pair<Node*, int>> Q; // (Node, HD)
    map<int, int> m; // (HD, node->data)

    Q.push(make_pair(root, 0)); // First we will push the root

    while (!Q.empty()) {
        pair<Node*, int> current = Q.front();
        Q.pop();

        Node* currentNode = current.first;
        int currentHD = current.second;

        if(m.count(currentHD) == 0) { // No unique is present
            m[currentHD] = currentNode->data; // Add that unique HD inside the map
        }

        if(currentNode->left != NULL) { 
            pair<Node*, int> left = make_pair(currentNode->left, currentHD - 1); // We know the root HD
            Q.push(left);
        }
        
        if(currentNode->right != NULL) { 
            pair<Node*, int> right = make_pair(currentNode->right, currentHD + 1); // We know the root HD
            Q.push(right);
        }

    }

    for(auto p : m) {
        cout << p.second << " ";
    }
}
