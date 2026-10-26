/*
------------------------------------------------------------
Problem : Distinct Subsequences (LeetCode 115)
Pattern : Dynamic Programming + 1D Space Optimization

Time Complexity : O(M * N)
Space Complexity : O(N)

Idea:
- Let dp[j] represent the number of ways to form the first
  j characters of string t using the characters processed
  so far from string s.
- Initialize dp[0] = 1 because there is exactly one way
  to form an empty string: choose nothing.
- If s is shorter than t, return 0 immediately.
- Traverse each character of s.
- Iterate through t backwards:
    - If s[i - 1] == t[j - 1], add dp[j - 1] to dp[j].
    - Otherwise, dp[j] remains unchanged.
- Return dp[n], the number of distinct subsequences
  of s that equal t.

Key Insight:
When the characters match, we have two choices:
1. Skip the current character in s.
2. Use the current character to match the current
   character in t.

Therefore, the transition is:

    dp[j] += dp[j - 1]

The inner loop runs backwards to ensure dp[j - 1] still
represents the previous iteration's state. This prevents
the same character of s from being used multiple times
in a single subsequence.

------------------------------------------------------------
*/


class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        if (m < n) return 0;
        
        
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; 
        
        for (int i = 1; i <= m; ++i) {
 
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[n];
    }
};