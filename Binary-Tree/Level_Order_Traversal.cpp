// Problem: Binary Tree Level Order Traversal (LeetCode 102)
// Pattern: Tree BFS
// TC: O(n)
// SC: O(n)
//
// Idea:
// Perform level-order traversal using a queue.
// Process one level at a time using the queue size.
// Store each level separately.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> Result;


        // Base Case:
        if(root == nullptr) {
            return Result;
        }
        // If Level Order comes: Always Queue
        queue<TreeNode*> q;

        // Let's Start Pushing
        q.push(root);

        while(!q.empty()) {
            int level = q.size(); // This will tell the size each level

            vector<int> currentLevel; 

            for(int i = 0; i < level; i++) {
                TreeNode* currentNode = q.front(); // Making the current Node as Front of the Queue
                q.pop(); // Pop And Record

                currentLevel.push_back(currentNode->val); // Inserting in the Answer SubSet

                // First Check and then Push
                if(currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                if(currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }

            }
            // Finally After completing the Subset return the whole Set
            Result.push_back(currentLevel);
        }
        return Result;

    }
};