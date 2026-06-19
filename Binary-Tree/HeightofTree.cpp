// Height of Tree

int height(Node* root) {
    // Base Case
    if(root == NULL) {
        return 0;
    }

    // 1. Go to left subtree using recursion
    int leftHeight = height(root->left);

    // 2. Go to right subtree
    int rightHeight = height(root->right);

    // Find the maximum of them

    int currentHeight = max(leftHeight, rightHeight) + 1;

    return currentHeight;
}