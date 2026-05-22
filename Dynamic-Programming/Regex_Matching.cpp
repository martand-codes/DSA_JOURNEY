// Problem: Regular Expression Matching
// Pattern: Dynamic Programming
// TC: O(m * n)
// SC: O(m * n)

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] represents if the first i characters of s 
        // match the first j characters of p.
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        
        // Base case: matching an empty string with patterns like "a*", "a*b*", or ".*"
        // A '*' can represent zero occurrences of the preceding character.
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                // We look two steps back to ignore the '*' and its preceding character
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                
                // Case 1: Current characters match, or the pattern has a '.' wildcard
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // Inherit the match status from the previous characters in both strings
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // Case 2: The pattern character is a '*'
                else if (p[j - 1] == '*') {
                    // Scenario A: Assume zero occurrences of the preceding character.
                    // We drop the '*' and the character before it.
                    dp[i][j] = dp[i][j - 2];
                    
                    // Scenario B: Assume one or more occurrences of the preceding character.
                    // This is only valid if the preceding character actually matches s[i-1].
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        // If it matches, we "consume" one character from s, but keep the '*' 
                        // available in the pattern for potential future matches.
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        // The answer is whether the entirety of both strings matched
        return dp[m][n];
    }
};