// Problem: Insert into a Binary Search Tree (LeetCode 701)
// Pattern: BST + Recursion
// TC: O(h)
// SC: O(h)
//
// Idea:
// Traverse according to BST property.
// When a NULL position is found,
// create a new node and connect it
// while recursion unwinds.

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // We also have to connect it not just traversing
        // Base Case: If there is nothing!
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        else if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};