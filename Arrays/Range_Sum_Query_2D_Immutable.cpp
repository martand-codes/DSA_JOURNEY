/*
------------------------------------------------------------
Problem : Range Sum Query 2D - Immutable (LeetCode 304)
Pattern : 2D Prefix Sum / Matrix Preprocessing / Inclusion-Exclusion

Time Complexity :
Constructor : O(M * N)
SumRegion  : O(1)

Space Complexity : O(M * N)

Idea:
Precompute a 2D prefix sum matrix where prefix[r][c]
represents the sum of all elements in the submatrix
from (0, 0) to (r - 1, c - 1) of the original matrix.

Use an extra row and column initialized with zeros to
simplify boundary handling and avoid special cases.

During preprocessing:
- Traverse the original matrix row by row.
- Calculate each prefix sum using the current matrix
  element, the prefix sum above it, the prefix sum
  to its left, and subtract the overlapping region.

For sumRegion():
- Convert the given 0-indexed coordinates into the
  corresponding prefix sum boundaries.
- Retrieve the total sum using four prefix sum values.
- Subtract the regions above and to the left.
- Add back the overlapping region, which was
  subtracted twice.

Key Insight:
A 2D prefix sum allows any rectangular submatrix sum
to be calculated using only four prefix sum values.

The inclusion-exclusion principle eliminates unwanted
regions and restores the overlapping area.

M represents the number of rows and N represents
the number of columns in the original matrix.

Preprocessing takes O(M * N) time, but every subsequent
range sum query takes O(1) time.

------------------------------------------------------------
*/

class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int current_val = matrix[r][c];
                prefix[r + 1][c + 1] = current_val 
                                     + prefix[r][c + 1] 
                                     + prefix[r + 1][c] 
                                     - prefix[r][c];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r1 = row1 + 1;
        int c1 = col1 + 1;
        int r2 = row2 + 1;
        int c2 = col2 + 1;
        return prefix[r2][c2] 
             - prefix[r1 - 1][c2] 
             - prefix[r2][c1 - 1] 
             + prefix[r1 - 1][c1 - 1];
    }
};
