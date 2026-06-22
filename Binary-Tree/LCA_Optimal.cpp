// Better Approach for SC: O(1)

TreeNode* Lca (TreeNode* root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }

    if (root->val == n1 || root->val == n2) {
        return root;
    }

    TreeNode* leftLCA = Lca(root->left, n1, n2);
    TreeNode* rightLCA = Lca(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}