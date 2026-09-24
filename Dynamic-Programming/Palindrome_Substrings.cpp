/*
------------------------------------------------------------
Problem : Palindromic Substrings (LeetCode 647)
Pattern : Dynamic Programming (2D String DP)

Time Complexity : O(N²)
Space Complexity : O(N²)

Idea:
- dp[i][j] represents whether the substring s[i...j]
  is a palindrome.
- A substring is a palindrome if:
    1. Its first and last characters are equal, and
    2. Its inner substring is also a palindrome.
- Substrings of length 1 and 2 are handled directly.
- Traverse i from right to left so that dp[i + 1][j - 1]
  is already calculated.
- Every time dp[i][j] becomes true, increment the total
  number of palindromic substrings.

Key Insight:
Instead of finding the longest palindrome, count every
substring that satisfies the palindrome condition. Each
true DP state corresponds to exactly one palindromic
substring.

------------------------------------------------------------
*/


class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 0) {
            return 0;
        }
        int totalPalindromes = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1] == true)) {
                    dp[i][j] = true;
                    totalPalindromes++;
                }
            }
        }
        return totalPalindromes;
    }
};