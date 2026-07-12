// Problem: Lowest Common Ancestor of a BST (LeetCode 235)
// Pattern: BST Traversal
// TC: O(h)
// SC: O(1)
//
// Idea:
// Traverse the BST.
// If both nodes are smaller, move left.
// If both nodes are larger, move right.
// Otherwise, the current node is the LCA.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while(root != nullptr) {
            
            // If both are GREATER move the root pointer RIGHT
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            
            //If both are LESS move the root pointer LEFT
            else if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            
            // The Split! so break the loop and return
            else {
                return root;
            }
        }
       
        return nullptr;
    }
};