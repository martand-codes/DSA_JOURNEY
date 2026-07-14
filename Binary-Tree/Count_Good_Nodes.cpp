// Problem: Count Good Nodes in Binary Tree (LeetCode 1448)
// Pattern: DFS + Carry State
// TC: O(n)
// SC: O(h)
//
// Idea:
// Carry the maximum value seen from the root
// to the current node.
// If the current node is >= maximum,
// count it as a good node.

class Solution {
public:
    int goodNodes(TreeNode* root) {
      return helper(root, root->val);
    }
    int helper(TreeNode* root, int maxValue) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;

        if(root->val >= maxValue) {
            count = 1;
        }

        int newMax = max(maxValue, root->val);

        int leftCount = helper(root->left, newMax);
        int rightCount = helper(root->right, newMax);

        return count + leftCount + rightCount;
    }
};