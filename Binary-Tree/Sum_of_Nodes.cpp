// Same Height Approach

int Sum (Node* root) {
    // Base Case:
    if(root == NULL) {
        return 0;
    }
    int leftSum = Sum(root->left);
    int rightSum = Sum(root->right);
    int currentSum =  leftSum + rightSum + root->value;
    return currentSum;
}