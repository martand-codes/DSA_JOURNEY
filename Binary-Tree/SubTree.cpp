// Problem: Subtree of Another Tree (LeetCode 572)
// Pattern: Tree DFS + Tree Comparison
// TC: O(m × n)
// SC: O(h)
//
// Idea:
// Traverse every node in the main tree.
// Whenever values match, compare the two
// trees recursively.
// Otherwise continue searching in the left
// and right subtrees.

class Solution {
public:
    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        // Base Cases: 
        if (root == nullptr && subRoot == nullptr) {
            return true;
        } else if(root == nullptr || subRoot == nullptr) {
            return false;
        }

        if (root->val != subRoot->val) {
            return false;
        }

        return isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base Cases: 
        if (root == nullptr && subRoot == nullptr) {
            return true;
        } else if(root == nullptr || subRoot == nullptr) {
            return false;
        }

        if (root->val == subRoot->val) {
            if(isIdentical(root, subRoot)) {
                return true;
            }
        }

        int isLeftSubtree = isSubtree(root->left, subRoot);

        if(!isLeftSubtree) {
            return isSubtree(root->right, subRoot);
        }

        return true;
    }
};