/*
------------------------------------------------------------
Problem : Longest Common Subsequence (LCS)
Pattern : Dynamic Programming (2D String DP)

Time Complexity : O(N × M)
Space Complexity : O(N × M)

Idea:
- dp[i][j] represents the length of the LCS between
  the first i characters of str1 and the first j
  characters of str2.
- If the current characters match, include the character
  and move diagonally:
      dp[i][j] = 1 + dp[i - 1][j - 1]
- If they do not match, skip one character from either
  string and take the better result:
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

Key Insight:
When characters match, they can contribute to the LCS.
When they do not match, the optimal subsequence must
exclude at least one of the two current characters.
------------------------------------------------------------
*/


int lcs(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}