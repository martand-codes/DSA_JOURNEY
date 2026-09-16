/*
------------------------------------------------------------
Problem : Edit Distance (LeetCode 72)
Pattern : Dynamic Programming (2D String DP)

Time Complexity : O(N × M)
Space Complexity : O(N × M)

Idea:
- dp[i][j] represents the minimum number of operations
  required to convert the first i characters of word1
  into the first j characters of word2.
- Base cases:
    * Empty word1 -> Insert all characters of word2.
    * Empty word2 -> Delete all characters of word1.
- If characters match, no operation is required:
      dp[i][j] = dp[i-1][j-1]
- Otherwise choose the minimum among:
    * Insert    -> dp[i][j-1] + 1
    * Delete    -> dp[i-1][j] + 1
    * Replace   -> dp[i-1][j-1] + 1

Key Insight:
Every mismatch can be resolved using exactly one of
three edit operations. Dynamic Programming explores
all prefixes of both strings and stores the minimum
cost for each pair of prefixes.
------------------------------------------------------------
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // If word1 empty
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        // If word2 empty
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 0 + dp[i-1][j -1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])); // Insertion Deletion & Updation
                }
            }
        }
        return dp[n][m];
    }
};