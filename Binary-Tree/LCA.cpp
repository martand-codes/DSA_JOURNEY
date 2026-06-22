// Problem: Lowest Common Ancestor of a Binary Tree
// Pattern: Root-to-Node Path
// TC: O(n)
// SC: O(n)
//
// Idea:
// 1. Find path from root to p.
// 2. Find path from root to q.
// 3. Compare both paths.
// 4. Last common node is the LCA.


class Solution {
public:

    bool rootToNodeDistance (TreeNode* root, TreeNode* n, vector<TreeNode*>& path) {

        if (root == NULL) {
            return false;
        }

        path.push_back(root);

        if(root == n) {
            return true;
        }

        bool isLeft = rootToNodeDistance(root->left, n, path);
        bool isRight = rootToNodeDistance(root->right, n, path);

        if(isLeft || isRight) {
            return true;
        }

        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;


        rootToNodeDistance(root, p, path1);
        rootToNodeDistance(root, q, path2);

        TreeNode* lca = NULL;

        for(int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
            if (path1[i] != path2[j]) {
                break;
            }

            lca = path1[i];
        }

        return lca;
    }
};


