/*
------------------------------------------------------------
Problem : Longest Palindromic Substring (LeetCode 5)
Pattern : Dynamic Programming (2D String DP)

Time Complexity : O(N²)
Space Complexity : O(N²)

Idea:
- dp[i][j] represents whether the substring s[i...j]
  is a palindrome.
- A substring is a palindrome if:
    1. Its characters at both ends are equal, and
    2. Its inner substring is also a palindrome.
- Substrings of length 1 and 2 are handled directly.
- Traverse i from right to left so that dp[i + 1][j - 1]
  has already been calculated.
- Track the starting index and maximum length of the
  longest palindrome found.

Key Insight:
A longer substring is a palindrome only when its two end
characters match and everything inside those characters is
already known to be a palindrome. Therefore, the answer
can be built from smaller substrings.

------------------------------------------------------------
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int start = 0;
        int maxLength = 1;
        
        // We traverse both forwards and backwards in palindrome
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1 || dp[i + 1][j - 1] == true) {
                        dp[i][j] = true;
                        if (j - i + 1 > maxLength) {
                            start = i;
                            maxLength = j - i + 1;
                        }
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};