class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        solve(0, 0, 0, 0, n, count);
        return count;
    }
    
private:
    void solve(int row, int cols, int diag1, int diag2, int n, int& count) {
        if (row == n) {
            count++;
            return;
        }
        
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        
        while (available) {
            int pos = available & -available;
            available &= available - 1;
            solve(row + 1, cols | pos, (diag1 | pos) << 1, (diag2 | pos) >> 1, n, count);
        }
    }
};