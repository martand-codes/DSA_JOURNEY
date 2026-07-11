// Problem: Same Tree (LeetCode 100)
// Pattern: Tree DFS / Recursion
// TC: O(n)
// SC: O(h)
//
// Idea:
// Compare corresponding nodes.
// If values differ or one node is null,
// trees are different.
// Otherwise recursively compare
// left and right subtrees.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base Cases:
        if(p == nullptr && q == nullptr) {
            return 1;
        }
        // For 1 different Node
        if (p == nullptr || q == nullptr) {
            return false;
        }

        if(p->val != q->val) {
            return 0;
        }

        if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
            return 1;
        }
        return 0; 
    }
};