// Problem: Construct Quad Tree (LeetCode 427)
// Pattern: Divide & Conquer + Recursion
// TC: O(n² log n)
// SC: O(log n)
//
// Idea:
// If the current square contains all equal values,
// create a leaf.
// Otherwise divide into four equal quadrants
// and recursively build each child.

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
    
    Node* build(vector<vector<int>>& grid, int row, int column, int size) {
        if(checkUniformity(grid, row, column, size)) {

            bool val = grid[row][column] == 1;
            return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
        }

        int newSize = size / 2;
        Node* parent = new Node(true, false, nullptr, nullptr, nullptr, nullptr);
        parent->topLeft = build(grid, row, column, newSize);
        parent->topRight = build(grid, row, column + newSize, newSize);
        parent->bottomLeft = build(grid, row + newSize, column, newSize);
        parent->bottomRight = build(grid, row + newSize, column + newSize, newSize);

        return parent;
    }
    
    bool checkUniformity(vector<vector<int>>& grid, int row, int column, int size) {
        int target = grid[row][column];

        for(int i = row; i < row + size; i++) {
            for(int j = column; j < column + size; j++) {
                if (grid[i][j] != target) {
                    return false; 
                }
            }
        }
        return true;
    } 
};