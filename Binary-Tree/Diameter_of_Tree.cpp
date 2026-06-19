// Problem: Diameter of Binary Tree
// Pattern: Tree DP / Postorder Traversal
//
// Approach 1:
// TC: O(n²)
// SC: O(h)
//
// Idea:
// For every node,
// Diameter = height(left) + height(right) + 1
//
// Approach 2:
// TC: O(n)
// SC: O(h)
//
// Idea:
// Return {diameter, height}
// from every subtree in a single DFS.


// for O(n^2)

// First make the height Function

int height(Node * root) {
    // Base Case:
    if (root == NULL) {
        return 0;
    }

    int lefHeight = height(root->left);
    int rightHeight = height(root->right);
    int currentHeight = max(leftHeight, rightHeight) + 1;
    return currentHeight;
}

// Now let's find the diameter

int Diameter (Node* root) {
    // Base Case:
    if(root == NULL) {
        return 0;
    }
    // 2 Casees: 
    // a. With Root 
    // b. Without Root

    // a
    int withRootDiameter = height(root->left) + height(root->right) + 1;

    // b
    int leftDiameter = Diameter(root->left);
    int rightDiameter = Diameter(root->right);

    int maximumDiameter = max(withRootDiameter, max(leftDiameter, rightDiameter));

    return maximumDiameter;
}

// For O(n)

// We will use pairs to find Diameter and Height

pair<int, int> linearDiameter(Node* root) {
    // Base Case:
    if (root == NULL) {
        return make_pair(0,0);
    }

    // Pair = (diameter, height)
    pair<int, int> leftInfo = linearDiameter(root->left);
    pair<int, int> rightInfo = linearDiameter(root->right);

    int currentDiameter = leftInfo.second + rightInfo.second + 1; 
    int finalDiameter = max(currentDiameter, max(leftInfo.first, rightInfo.first));
    int finalHeight = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiameter, finalHeight);
}