// Problem: Sudoku Solver
// Pattern: Backtracking
// TC: O(9^(empty cells))
// SC: O(empty cells)


class Solution {
public:
    bool solveSudoku(int sudoku[9][9], int row, int column) {

        // Base Case
        if (row == 9) {
            return true;
        }
        int nextRow = row;
        int nextColumn = column + 1;
        if (column + 1 == 9) {
            nextRow = row + 1;
            nextColumn = 0;
        }
        if (sudoku[row][column] != 0 ){
            return solveSudoku(sudoku, nextRow, nextColumn);
        }
        for (int digit = 1; digit <= 9; digit++){
            if(isSafe(sudoku, row, column, digit )) {
                sudoku[row][column] = digit;
                if (solveSudoku(sudoku, nextRow, nextColumn)){
                    return  true;
                }
                sudoku[row][column] = 0;
            }
        }
    
        return false;
    }

    bool isSafe(int sudoku[9][9], int row, int column, int digit) {
        // Vertical Check
        for (int i = 0; i < 9; i++) {
            if(sudoku[i][column] == digit){
                return false;
            }
        }
        // Horizontal Check
        for (int j = 0; j < 9; j++) {
            if(sudoku[row][j] == digit){
                return false;
            }
        }

        // 3 * 3 Grid
        int startRow = (row / 3) * 3;
        int startColumn = (column / 3) * 3;

        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startColumn; j < startColumn + 3; j++){
                if(sudoku[i][j] == digit){
                    return false;
                }
            }
        }
        return true;
    }
    
};