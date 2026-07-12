// Problem: Delete Node in BST
// Pattern: BST Recursion
// TC: O(h)
// SC: O(h)
//
// Cases:
// 1. Leaf Node
// 2. One Child
// 3. Two Children
//
// Idea:
// For two children:
// - Find inorder successor
// - Copy successor value
// - Delete successor node



// First Find the Inorder Traversal for node with with 2 childs

Node* inorderTraversal(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root; 
}

// Now Deletion Function
// 2 Steps: 1) Search 2) Delete: 3 cases

Node* deleteNode(Node* root, int value) {
    // Base Case:

    if(root == NULL) {
        return NULL;
    }

    if(value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Case 1: No Child

        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL; // Simply delete it and attach NULL to the parent
        }

        // Case 2: 1 Child

        if(root->left == NULL || root->right == NULL ) {
            return root->left ? NULL : root->right : root->left;
        }

        // Case 3 : 2 children
        // Find the inorder Successor and then replace it then delete the node

        Node* IS = inorderTraversal(root->right); // Because Inorder means bigger value and it will always come in right in a BST
        root->data = IS->data; // Replacing
        root->right = deleteNode(root->right, IS->data); // Case 1 and Case 2
        return root;
    }

    return root;
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base Case: No Root!
        if (root == nullptr) {
            return nullptr;
        }

        // Rule Of BST go (search) left and right
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        
        // --- PHASE 2: DELETE ---
        // We found the node! (key == root->val)
        else {
            // For 0 and 1 child
            if(root->left == nullptr) { // Memory empty in left
                // Making a temporary node
                TreeNode* temporary = root->right;
                delete root; // Freeing the memory
                return temporary;
            }
            // Same for Right Child!
            else if (root->right == nullptr) {
                TreeNode* temporary = root->left;
                delete root;
                return temporary;
            }
            
            // For 2 children
            // First find the inorder successor (smallest node on the right side)
            TreeNode* successor = findMin(root->right);
            
            // Secondly Copy successor value to root value
            root->val = successor->val;
            
            // Third Delete
            root->right = deleteNode(root->right, successor->val);
        }
        
        return root;
    }
    // F(x) for finding the inorder successor
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};