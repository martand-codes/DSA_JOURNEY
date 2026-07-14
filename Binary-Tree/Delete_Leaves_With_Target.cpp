// Problem: Delete Leaves With a Given Value (LeetCode 1325)
// Pattern: Postorder DFS (Bottom-Up Recursion)
// Time Complexity: O(n)
// Space Complexity: O(h)
//
// Idea:
// Process the left and right subtrees first (postorder traversal).
// After both children are updated, check whether the current node
// has become a leaf. If it is a leaf and its value equals the target,
// delete it by returning nullptr. Otherwise, return the current node.
//
// Key Insight:
// Bottom-up traversal is necessary because deleting child leaves can
// turn their parent into a new leaf that may also need to be deleted.

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base Case
        if(root == nullptr) {
            return nullptr;
        }
        // Since we have to delete all the nodes we will use Bottom Up Approach (Postorder)
        root->left = removeLeafNodes(root->left, target); // If Deletion Happens Think about relinking
        root->right = removeLeafNodes(root->right, target);

        if(root->left == nullptr && root->right == nullptr) {
            if(root->val == target) {
                return nullptr;
            }
        }
        return root;
    }
};