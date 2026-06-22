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


// Better Approach for SC: O(1)

TreeNode* Lca (TreeNode* root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }

    if (root->val == n1 || root->val == n2) {
        return root;
    }

    TreeNode* leftLCA = Lca(root->left, n1, n2);
    TreeNode* rightLCA = Lca(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}