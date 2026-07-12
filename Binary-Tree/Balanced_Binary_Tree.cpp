// Problem: Balanced Binary Tree (LeetCode 110)
// Pattern: Tree DFS + Bottom-Up DP
// TC: O(n)
// SC: O(h)
//
// Idea:
// Return subtree height.
// If any subtree is already unbalanced,
// return -1 immediately.
// Otherwise return the height.

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) {
            return 1;
        }
        return checkHeight(root) != -1;
    }
    int checkHeight(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftHeight = checkHeight(root->left);
        int rightHeight = checkHeight(root->right);

        // Checking for Left and right Child
        if(leftHeight == -1 || rightHeight == -1) {
            return -1;
        }

        // Checking for Balance
        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;

    }
};