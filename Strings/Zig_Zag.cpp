// Problem: Zigzag Conversion
// Pattern: String Simulation
// TC: O(n)
// SC: O(n)

class Solution {
public:
    string convert(string s, int numRows) {
        // If there's only 1 row or the string is shorter than the rows, 
        // the zigzag pattern is just the string itself.
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create an array of strings for each row
        vector<string> rows(min(numRows, int(s.length())));
        int currRow = 0;
        bool goingDown = false;

        // Place each character in the correct row
        for (char c : s) {
            rows[currRow] += c;
            
            // Change direction when we hit the top or bottom row
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to the next row
            currRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        string result = "";
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};