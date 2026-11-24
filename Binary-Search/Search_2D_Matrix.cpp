/*
------------------------------------------------------------
Problem : Search a 2D Matrix (LeetCode 74)
Pattern : Binary Search / Matrix Traversal / Index Mapping /
          Search Space Reduction

Time Complexity :
O(log(N * M))

- Binary search operates on a virtual 1D array containing
  N * M elements.
- Each iteration reduces the search space by half.
- Therefore, at most O(log(N * M)) iterations are required.
- Accessing matrix elements using index mapping takes O(1).

Space Complexity :
O(1)

- Only a constant number of variables are used.
- Binary search is performed iteratively without recursion.
- No additional data structures are created.

Idea:
1. Treat the 2D matrix as a virtually flattened 1D sorted
   array without actually converting it into another array.

2. Initialize the binary search boundaries:

       start = 0
       end = (N * M) - 1

   Here, N represents the number of rows and M represents
   the number of columns.

3. Calculate the middle index:

       mid = start + (end - start) / 2

4. Convert the virtual 1D index into its corresponding
   2D matrix coordinates:

       row = mid / M
       col = mid % M

   Integer division identifies the row, while modulo
   identifies the column.

5. Compare matrix[row][col] with the target:

   - If equal, the target is found. Return true.
   - If the current element is smaller than the target,
     eliminate the left half by updating start = mid + 1.
   - If the current element is greater than the target,
     eliminate the right half by updating end = mid - 1.

6. Continue until start exceeds end.

7. If the loop terminates without finding the target,
   return false.

Key Insight:
The matrix has two important properties:

- Each row is sorted in ascending order.
- The first element of each row is greater than the last
  element of the previous row.

These properties guarantee that the entire matrix can be
treated as one globally sorted 1D array.

Instead of creating an actual flattened array, we use
mathematical index mapping to access elements directly.

Index Mapping:

    1D index = mid

    2D row = mid / M
    2D col = mid % M

Example:

    Matrix:
    [
        [ 1,  3,  5,  7],
        [10, 11, 16, 20],
        [23, 30, 34, 60]
    ]

    M = 4

    If mid = 6:

        row = 6 / 4 = 1
        col = 6 % 4 = 2

    Therefore:

        matrix[1][2] = 16

Important Concepts:
- Virtual Flattening: Treating a 2D structure as a 1D
  search space without allocating additional memory.
- Binary Search: Eliminating half of the remaining
  search space after every comparison.
- Index Mapping: Converting a linear index into
  corresponding row and column coordinates.

Complexity Variables:
N = Number of rows in the matrix.
M = Number of columns in the matrix.

Assumption:
The matrix is non-empty and contains rows of equal length.

------------------------------------------------------------
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int start = 0, end = m * n - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(matrix[mid / m][mid % m] == target) {
                return true;
            } 
            else if(matrix[mid / m][mid % m] < target) {
                start = mid + 1;
            }   else {
                    end = mid - 1;
                }
        }

        return false;
    }
};