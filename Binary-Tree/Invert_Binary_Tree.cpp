// Problem: Invert Binary Tree (LeetCode 226)
// Pattern: Binary Tree + DFS
// TC: O(n)
// SC: O(h)
//
// Idea:
// Visit every node.
// Swap its left and right children.
// Recursively invert both subtrees.

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == nullptr) {
            return nullptr;
        }
        
        swap(root->left, root->right);
        
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};