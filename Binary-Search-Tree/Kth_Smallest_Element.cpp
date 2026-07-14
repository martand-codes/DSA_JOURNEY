// Problem: Kth Smallest Element in a BST (LeetCode 230)
// Pattern: BST + Inorder Traversal
// TC: O(n)
// SC: O(h)
//
// Idea:
// Perform inorder traversal.
// BST inorder gives sorted order.
// Count visited nodes.
// The kth visited node is the answer.

class Solution {
public:

    // Making Global Variables to use it everywhere!
    int counter = 0;
    int result = 0;
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return result;
    }
    void helper(TreeNode* root, int k) {
        // Base Case:
        if(root == nullptr || counter >= k) {
            return;
        }
        helper(root->left, k);
        counter++;
        if (counter == k) {
            result = root->val;
            return;
        }
        helper(root->right, k);
    }
};