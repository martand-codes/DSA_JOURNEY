// Problem: Generate Parentheses (LeetCode 22)
// Pattern: Backtracking + Constraint Generation
// TC: O(Catalan(n) × n)
// SC: O(n)
//
// Idea:
// Maintain counts of open and close parentheses.
// Add '(' if open < n.
// Add ')' only if close < open.
// This generates only valid parenthesis strings.

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> Answer;
        string subStr = "";
        helper(Answer, n, 0, 0, subStr);
        return Answer;
    }

    void helper(vector<string>& Answer, int n, int open, int close, string& subStr) {
        // Base Case:
        if(open == n && close == n) {
            Answer.push_back(subStr);
            return;
        }

        // For Opening 
        if(open < n) {
            // Optimization
            subStr.push_back('(');
            helper(Answer, n, open + 1, close, subStr );
            subStr.pop_back(); // BackTracking
        }

        // For Closing
        if(close < open) {
            // Optimizing
            subStr.push_back(')');
            helper(Answer, n, open, close + 1, subStr);
            subStr.pop_back(); // BackTracking
        }
    }
};