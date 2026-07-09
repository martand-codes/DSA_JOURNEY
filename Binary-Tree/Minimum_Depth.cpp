// Problem: Minimum Depth of Binary Tree (LeetCode 111)
// Pattern: Tree DFS / Recursion
// TC: O(n)
// SC: O(h)
//
// Idea:
// Compute left and right subtree depths.
// Handle skewed trees separately.
// Otherwise return min(left, right) + 1.

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        // For Skewed Tree 
        if (root->left == nullptr) {
            return rightDepth + 1;
        }
        if (root->right == nullptr) {
            return leftDepth + 1;
        }

        return min(leftDepth, rightDepth) + 1;

    }
};