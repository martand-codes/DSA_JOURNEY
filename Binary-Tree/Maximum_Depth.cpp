// Problem: Maximum Depth of Binary Tree (LeetCode 104)
// Pattern: Tree DFS / Recursion
// TC: O(n)
// SC: O(h)
//
// Idea:
// Recursively compute the depth of the left and right
// subtrees. The answer is max(left, right) + 1

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};