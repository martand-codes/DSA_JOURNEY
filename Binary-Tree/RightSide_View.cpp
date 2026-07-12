// Problem: Binary Tree Right Side View (LeetCode 199)
// Pattern: Tree BFS
// TC: O(n)
// SC: O(n)
//
// Idea:
// Perform level-order traversal.
// At each level, record the last node processed.
// Those nodes form the right side view.

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                // Only save the value if it's the very last node in the current level!
                if (i == levelSize - 1) {
                    result.push_back(currentNode->val);
                }

                // Always push both children if they exist: My First Approach was to ignore the leftChild If RightChild exists
                if(currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                if(currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
        }
        return result;
    }
};