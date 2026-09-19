/*
------------------------------------------------------------
Problem : Wildcard Matching (LeetCode 44)
Pattern : Dynamic Programming (2D String DP)

Time Complexity : O(N × M)
Space Complexity : O(N × M)

Idea:
- dp[i][j] represents whether the first i characters of
  string s can be matched by the first j characters of
  pattern p.
- If the characters match or the pattern contains '?',
  move diagonally:
      dp[i][j] = dp[i - 1][j - 1]
- If the pattern contains '*', it has two choices:
    1. Match zero characters:
       dp[i][j - 1]
    2. Match the current character:
       dp[i - 1][j]
- Initialize the first row to handle patterns containing
  only '*' characters.

Key Insight:
A '*' can represent any sequence of characters, including
an empty sequence. Therefore, at every '*' we either let it
consume the current character or treat it as matching
nothing.

------------------------------------------------------------
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
        dp[0][0] = true;

        for(int j = 1; j <=m; j++) {
            if(p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            } else { // Other than *
                dp[0][j] = false;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j<= m; j++) {
                if(s[i - 1] == p[j - 1]  || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // Because the * can also match an empty char
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];

    }
};