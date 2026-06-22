
Node* insert(Node* root, int value) {
    // Base Case:
    if(root == NULL) {
        root = new Node(value);
        return root;
    }

    if(value < root) {
       root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value)
    }

    return root;
}

Node* BuildTree(int arr[], int n {
    Node* root == NULL;

    for(int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
}