// Problem: Grid Ways
// Pattern: Recursion
// TC: O(2^(m+n))
// SC: O(m+n)

int gridWays (int row, int column, int m, int n) {

    //Base Cases: 
    if (row == m-1 && column == n-1) {
        return 1;
    }
    if (row >= m || column >= n ) {
        return 0;
    }
    // For Right:
    int w1 = gridWays(row, column + 1, m, n);
    // For Down
    int w2 =  gridWays(row + 1, column,m, n);
    return w1 + w2;
}