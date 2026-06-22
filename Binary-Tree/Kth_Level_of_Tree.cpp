// Problem: Print Kth Level of Binary Tree
// Pattern: DFS / Recursion
// TC: O(n)
// SC: O(h)
//
// Idea:
// Traverse recursively while tracking current level.
// Print nodes whenever current level equals k.



void kthLevel(Node* root, int k, int currentLevel) {

    if(root == NULL) {
        return;
    }

    if(currentLevel == k) {
        cout << root->data << " ";
        return;
    }

    kthLevel(root->left, k, currentLevel + 1);
    kthLevel(root->right, k, currentLevel + 1);
}