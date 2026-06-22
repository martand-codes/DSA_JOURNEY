int Search (Node* root, int key) {
    // Base Case:
    if (root == NULL) {
        return -1;
    }

    if(root->value < key) {
        Search(root->left, key);
    }

    if(root->value > key) {
        Search(root->right, key);
    }

    if(root->value == key) {
        return root;
    }

    return root;
    
}