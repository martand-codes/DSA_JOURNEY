// Problem: Validate Binary Search Tree (LeetCode 98)
// Pattern: DFS + Range Validation
// TC: O(n)
// SC: O(h)
//
// Idea:
// Every node must lie within a valid range.
// Left subtree updates the maximum boundary.
// Right subtree updates the minimum boundary.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
       
        return validate(root, LONG_MIN, LONG_MAX);
    }

    bool validate(TreeNode* node, long minBoundary, long maxBoundary) {
    
        if (node == nullptr) {
            return true;
        }
        if (node->val <= minBoundary || node->val >= maxBoundary) {
            return false;
        }
        bool leftIsValid = validate(node->left, minBoundary, node->val);
        bool rightIsValid = validate(node->right, node->val, maxBoundary);
        return leftIsValid && rightIsValid;
    }
};