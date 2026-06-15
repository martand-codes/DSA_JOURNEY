// Topic: Binary Tree Traversals
// Pattern: DFS + BFS
//
// Traversals Covered:
// 1. Preorder Traversal   (Root -> Left -> Right)
// 2. Inorder Traversal    (Left -> Root -> Right)
// 3. Postorder Traversal  (Left -> Right -> Root)
// 4. Level Order Traversal (BFS)
// 5. Level Order Traversal Line-by-Line
//
// Time Complexity:
// Preorder   : O(n)
// Inorder    : O(n)
// Postorder  : O(n)
// LevelOrder : O(n)
//
// Space Complexity:
// DFS Traversals : O(h)  // h = height of tree (recursion stack)
// BFS Traversal  : O(w)  // w = maximum width of tree (queue)
//
// Concepts Used:
// - Recursion
// - Depth First Search (DFS)
// - Breadth First Search (BFS)
// - Queue
//
// Notes:
// Preorder  -> Useful for tree serialization and copying.
// Inorder   -> Gives sorted order for BSTs.
// Postorder -> Useful for deletion and bottom-up calculations.
// LevelOrder -> Processes nodes level by level.

// Preorder Traversal

void preorder(Node* root) {
    // Base Case:
    if (root == NULL) {
        return;
    }
    cout<<root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}


// Inorder Traversal

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
} 


// Postorder Traversal

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
} 


// Levelorder Traversal

void levelorder(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> Q;
    Q.push(root);  // First Push the Root

    while(!Q.empty()) {
        Node* current = Q.front(); // Store the front of the Queue inside the answer
        Q.pop();

        cout<<current->data<< " ";
        // Now Check the children for Left and Right So we cannot insert NULL
        if(current->left != NULL) {
            Q.push(current->left);
        }
        if(current->right != NULL) {
            Q.push(current->right);
        }
    }
    cout<<endl;
}

// Levelorder Traversal: If we want Level wise output then track NULL
 
void levelorder(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node> Q;
    Q.push(root);  // First Push the Root
    Q.push(NULL);

    while(!Q.empty()) {
        Node* current = Q.front(); // Store the front of the Queue inside the answer
        Q.pop();

        if(current == NULL) {
            cout<<endl;
            if(Q.empty()) {
                break; // This will break the loop after the last level
            }
            Q.push(NULL); // To Track next Line
        } else {
            cout<<current->data<< " ";
            // Now Check the children for Left and Right So we cannot insert NULL
            if(current->left != NULL) {
                Q.push(current->left);
            }
            if(current->right != NULL) {
                Q.push(current->right);
            }   
        }
    }      
}