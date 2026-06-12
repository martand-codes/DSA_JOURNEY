// Problem: Longest Valid Parentheses
// Pattern: Parentheses / Two Pass Counter Technique
// TC: O(n)
// SC: O(1)
//
// Idea:
// Pass 1 (Left -> Right):
// Reset when ')' exceeds '('.
//
// Pass 2 (Right -> Left):
// Reset when '(' exceeds ')'.
//
// This handles unmatched parentheses on both sides.

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int max_len = 0;
        int n = s.length();
        
        // Pass 1: Left to Right
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                max_len = max(max_len, 2 * right);
            } else if (right > left) {
                // Streak broken by too many closing brackets
                left = 0;
                right = 0;
            }
        }
        
        // Reset counters for the second pass
        left = 0;
        right = 0;
        
        // Pass 2: Right to Left
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                max_len = max(max_len, 2 * left);
            } else if (left > right) {
                // Streak broken by too many opening brackets
                left = 0;
                right = 0;
            }
        }
        
        return max_len;
    }
};